#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program_slicing.h"

int programSlicing(CfgNode *entry, int lineno, Symbol *var)
{
	CfgNode *slice_start_node;
	RecordCfgNode *slicing_result = NULL, *p;
	RecordCfgNode *visited_node_list = NULL;
	
	slice_start_node = searchNode(entry, lineno);
	if (!slice_start_node)
	{
		printf("line number error!\n");
		return 1;
	}

	/*深度优先遍历切片*/
	DFSSlicing(slice_start_node, &var, &visited_node_list, &slicing_result);

	/*访问过的节点标记复原*/
	while (visited_node_list)
	{
		visited_node_list->node_cfg->visited = false;
		
		p = visited_node_list;
		visited_node_list = visited_node_list->next;
		free(p);
	}

	printf("Slicing result:\n");
	while (slicing_result)
	{
		printf("%d\n", slicing_result->node_cfg->node_of_ast->linenumber);
		p = slicing_result;
		slicing_result = slicing_result->next;
		free(p);
	}

	return 0;
}

CfgNode *searchNode(CfgNode *node_cfg, int lineno)
{
	RecordCfgNode *visited_node_list = NULL, *p;
	CfgNode *search_result;

	search_result = DFSSearch(node_cfg, lineno, &visited_node_list);

	while (visited_node_list)
	{
		visited_node_list->node_cfg->visited = false;
		
		p = visited_node_list;
		visited_node_list = visited_node_list->next;
		free(p);
	}

	return search_result;
}

CfgNode *DFSSearch(CfgNode *node_cfg, int lineno, RecordCfgNode **visited_node)
{
	RecordCfgNode *p;
	CfgNodeList *q;
	CfgNode *dfs_return;

	if (node_cfg->node_of_ast && node_cfg->node_of_ast->linenumber == lineno)
		return node_cfg;

	node_cfg->visited = true;
	
	/*头插法*/
	p = (RecordCfgNode *)malloc(sizeof(RecordCfgNode));
	p->node_cfg = node_cfg;
	p->next = *visited_node;
	*visited_node = p;

	for (q = node_cfg->successor; q; q = q->next)
	{
		if (!q->node_cfg->visited)
		{
			dfs_return = DFSSearch(q->node_cfg, lineno, visited_node);
			if (dfs_return)
				return dfs_return;
		}
	}

	/*没找到，返回NULL*/
	return NULL;
}

void DFSSlicing(CfgNode *node_cfg, Symbol **relevant, 
	RecordCfgNode **visited_node, RecordCfgNode **slicing_list)
{
	RecordCfgNode *p, *p1;
	CfgNodeList *q;
	Symbol *r, *temp;	/*释放relevant所占空间时使用*/
	int flag;

	if (subtractSymbol(relevant, node_cfg->def_s))	/*如果修改过，即node_cfg定义了relevant中的变量*/
	{
		insertSlicingResult(slicing_list, node_cfg);

		/*将node_cfg中使用的变量加入到relevant链表中*/
		mergeSymbol(relevant, node_cfg->use_s);
	}

	if (node_cfg->nodetype_cfg != Iteration)
	{
		node_cfg->visited = true;

		/*插入到访问过的节点链表中*/
		p = (RecordCfgNode *)malloc(sizeof(RecordCfgNode));
		p->node_cfg = node_cfg;
		p->next = *visited_node;
		*visited_node = p;	
	}

	if (!(*relevant))	/*relevant链表为空时结束,不在向上遍历*/
		return;

	if (node_cfg->nodetype_cfg == Entry)
	{
		/*释放relevant所占空间*/
		r = *relevant;
		while (r)
		{
			temp = r;
			r = r->next;
			free(temp);
		}
		return;	/*结束*/
	}

	for (q = node_cfg->predecessor; q; q = q->next)
	{
		/*是循环控制节点*/
		if (q->node_cfg->nodetype_cfg == Iteration)
		{
			/*查找其是否在节点访问列表中，即是否是第一次访问*/
			p = *visited_node;
			flag = 0;
			while (p)
			{
				/*找到*/
				if (p->node_cfg->node_of_ast->linenumber == q->node_cfg->node_of_ast->linenumber)
				{
					p->visit_count++;
					flag = 1;
					break;
				}
				p = p->next;
			}

			if (!flag)	/*如果没有找到*/
			{
				p = (RecordCfgNode *)malloc(sizeof(RecordCfgNode));
				p->node_cfg = q->node_cfg;
				p->node_cfg->visited = true;
				p->visit_count = 1;

				/*插入到已访问列表*/
				p->next = *visited_node;
				*visited_node = p;
			}

			if (flag && p->visit_count == 2)	/*如果找到且是第二次访问，此时p指向找到的节点*/
			{
				while (*visited_node != p)
				{
					(*visited_node)->node_cfg->visited = false;
					
					p1 = *visited_node;
					*visited_node = (*visited_node)->next;
					free(p1);
				}
			}

			temp = copySymbolList(*relevant);
			DFSSlicing(q->node_cfg, &temp, visited_node, slicing_list);

			continue;
		}

		if (!q->node_cfg->visited)
		{
			temp = copySymbolList(*relevant);
			DFSSlicing(q->node_cfg, &temp, visited_node, slicing_list);
		}
	}

	/*退出函数前，释放relevant所占空间*/
	r = *relevant;
	while (r)
	{
		temp = r;
		r = r->next;
		free(temp);
	}
}

Symbol *copySymbolList(Symbol *s)
{
	Symbol *head = NULL, *p;

	while(s)
	{
		p = (Symbol *)malloc(sizeof(Symbol));
		strcpy(p->name, s->name);
		p->next = head;
		head = p;

		s = s->next;
	}

	return head;
}

/*按行号递增的顺序插入切片结果链表中*/
void insertSlicingResult(RecordCfgNode **slicing_list, CfgNode *node_cfg)
{
	RecordCfgNode *pre, *p, *t;

	/*小于第一个节点的行号，插入到第一个节点前即可*/
	if ( !(*slicing_list)
		|| node_cfg->node_of_ast->linenumber < (*slicing_list)->node_cfg->node_of_ast->linenumber)
	{
		t = (RecordCfgNode *)malloc(sizeof(RecordCfgNode));
		t->node_cfg = node_cfg;
		t->next = *slicing_list;
		*slicing_list = t;

		return;
	}

	/*等于第一个节点行号，即切片结果链表里已有该节点，不用任何操作，直接退出函数*/
	if (node_cfg->node_of_ast->linenumber == (*slicing_list)->node_cfg->node_of_ast->linenumber)
		return;

	/*即大于第一个节点行号的情况*/
	pre = *slicing_list;
	p = pre->next;
	while (p)
	{
		/*插入到两者之间*/
		if (node_cfg->node_of_ast->linenumber < p->node_cfg->node_of_ast->linenumber)
		{
			t = (RecordCfgNode *)malloc(sizeof(RecordCfgNode));
			t->node_cfg = node_cfg;
			t->next = p;
			pre->next = t;

			return;
		}
		
		if (node_cfg->node_of_ast->linenumber == p->node_cfg->node_of_ast->linenumber)
			return;

		pre = p;
		p = p->next;
	}

	/*执行到此说明节点行号大于切片结果链表里所有节点的行号，把节点插入到链表结尾*/
	t = (RecordCfgNode *)malloc(sizeof(RecordCfgNode));
	t->node_cfg = node_cfg;
	t->next = NULL;
	pre->next = t;
}