#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print_slicing_result.h"

void printSlicingResult(char *sourcefile, RecordCfgNode *slicing_result,
				 			AstNode *ast_root, CfgNode *entry)
{
	int i;
	FILE *in, *out;
	char *destinationfile;		/*存放切片结果的文件名*/
	char line_contents[1024];	/*记录当前读取行的内容*/
	int linecount ;				/*记录当前需要读取行的行号*/
	int file_path_length = strlen(sourcefile);
	CfgNode **cfg_array;
	RecordCfgNode *p;

	if ((in = fopen(sourcefile, "r")) == NULL)
	{
		printf("Cannot open source file!\n");
		return;
	}

	destinationfile = (char *)malloc((file_path_length + 7) * sizeof(char));
	strcpy(destinationfile, sourcefile);
	destinationfile[file_path_length - 2] = '\0';
	strcat(destinationfile, "_slice.c");

	if ((out = fopen(destinationfile, "w")) == NULL)
	{
		printf("Cannot open destination file!\n");
		return;
	}

	/*为指针数组分配内存空间*/
	cfg_array = (CfgNode **)malloc((linesno + 1) * sizeof(CfgNode *));
	/*先将数组内容都置空*/
	for (i = 0; i <= linesno; i++)
		cfg_array[i] = NULL;
	/*然后将控制流图节点指针存入以行号为下标的对应数组元素中*/
	initialiseCfgArray(entry, cfg_array);

	linecount = 1;
	for (i = 1; i <= linesno; i++)
	{
		if (fgets(line_contents, 1024, in) == NULL)	/*失败或到达文件结尾*/
			break;

		if (i < linecount)	/*还没到需要读取的那一行*/
			continue;

		if (cfg_array[linecount] == NULL	/*不再控制流图节点中*/
			|| isInSlicingResult(slicing_result, linecount))	/*或者在控制流图中且在切片结果链表中*/
		{
			fputs(line_contents, out);	/*写到文件里*/
			linecount++;
		}
		else	/*在控制流图中但不在切片结果链表中*/
		{
			if (cfg_array[linecount]->nodetype_cfg == Iteration
				|| cfg_array[linecount]->nodetype_cfg == Select)
			{
				/*找到紧接在此节点后的下一个切片结果节点*/
				for (p = slicing_result; p; p = p->next)
					if (linecount < p->node_cfg->node_of_ast->linenumber)
						break;

				/*如果下一个切片结果节点在此节点对应的抽象语法树中，即控制依赖*/
				if (p && isInAstNode(cfg_array[linecount]->node_of_ast->firstchild,
									 p->node_cfg->node_of_ast->linenumber))
				{
					fputs(line_contents, out);	/*写到文件里*/
					linecount++;
				}
				else	/*否则，直接跳过此语句，将应读取行置为此语句结束行的下一行*/
					linecount = cfg_array[linecount]->node_of_ast->endlinenumber + 1;

			}
			else if (strcmp(cfg_array[linecount]->node_of_ast->value.value_string, "jump_statement") == 0)
			{
				fputs(line_contents, out);
				linecount++;
			}
			else
			{
				linecount++;
			}
		}
	}

	while (slicing_result)
	{
		p = slicing_result;
		slicing_result = slicing_result->next;
		free(p);
	}

	printf("Program slicing finished, the result is stored in the %s\n", destinationfile);

	fclose(in);
	fclose(out);
	free(destinationfile);
	free(cfg_array);
}

void initialiseCfgArray(CfgNode *node_cfg, CfgNode **cfg_array)
{
	CfgNodeList *p;

	if (node_cfg->nodetype_cfg != Entry
			&& node_cfg->nodetype_cfg != Exit)
	{
		cfg_array[node_cfg->node_of_ast->linenumber] = node_cfg;
		node_cfg->visited = true;
	}

	for (p = node_cfg->successor; p; p = p->next)
		if (!p->node_cfg->visited)
			initialiseCfgArray(p->node_cfg, cfg_array);
}

/*在切片结果中返回1,否则返回0*/
int isInSlicingResult(RecordCfgNode *slicing_result, int linecount)
{
	RecordCfgNode *p = NULL;

	p = slicing_result;
	while (p)
	{
		if (linecount == p->node_cfg->node_of_ast->linenumber)
			return 1;

		/*因为切片结果链表是按行号递增的顺序的,所以若行号小于当前行号，就不用往后找了*/
		if (linecount < p->node_cfg->node_of_ast->linenumber)
			break;

		p = p->next;
	}

	return 0;
}

int isInAstNode(AstNode *node_ast, int linecount)
{
	if (!node_ast)
		return 0;

	if (node_ast->linenumber == linecount)
		return 1;

	return isInAstNode(node_ast->firstchild, linecount)
			|| isInAstNode(node_ast->nextsibling, linecount);
}