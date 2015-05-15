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

	p = slicing_result;
	printf("Slicing result:\n");
	while (p)
	{
		printf("%d\n", p->node_cfg->node_of_ast->linenumber);
		p = p->next;
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
	RecordCfgNode *p;
	CfgNodeList *q;
	Symbol *r, *temp;	/*释放relevant所占空间时使用*/

	if (subtractSymbol(relevant, node_cfg->def_s))	/*如果修改过，即node_cfg定义了relevant中的变量*/
	{
		p = (RecordCfgNode *)malloc(sizeof(RecordCfgNode));
		p->node_cfg = node_cfg;

		/*插入到切片结果链表中*/
		p->next = *slicing_list;
		*slicing_list = p;

		/*将node_cfg中使用的变量加入到relevant链表中*/
		mergeSymbol(relevant, node_cfg->use_s);
	}

	/*如果是循环节点，不标记为访问过，因为循环节点需要多次访问，标记后就不能再访问了*/
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
		if (!q->node_cfg->visited)
		{
			temp = copy_symbol_list(*relevant);
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

Symbol *copy_symbol_list(Symbol *s)
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