#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bison_c.tab.h"
#include "ast_node.h"
#include "cfg_node.h"
#include "program_slicing.h"
#include "graph_to_dot.h"
#include "write_ast_to_file.h"
#include "print_slicing_result.h"

int main(int argc, char **argv)
{
	extern FILE *yyin;	/*来自词法分析器*/

	CfgNode *cfg_entry;
	RecordCfgNode *slicing_result = NULL, *q;
	int lineno;
	Symbol *var = NULL, *p;
	char name_temp[20];

	if (argc != 2)
	{
		printf("Usage: ProgramSlicing <source code>\n");
		return 1;
	}

	/*修改词法分析器的输入流*/
	if ((yyin = fopen(argv[1], "r")) == NULL)
	{
		printf("Cannot open file!\n");
		return 1;
	}

	/*yyparse()返回值为0或1
	返回0表示执行成功，并已建立好抽象语法树;
	返回1表示执行出错，会自动调用yyerror()函数输出错误信息.*/
	if(yyparse())
	{
		fclose(yyin);
		return 1;
	}

	fclose(yyin);

	/*仅作为测试，完成后删去*/
	node_counter = 1;	/*记得删除声明以及ast节点中的id以及valueIsNumber函数*/
	initialiseNodeId(ast_root);
	writeAstToFile(ast_root);

	cfg_entry = createCFG(ast_root);

	/*仅作为测试，完成后删去，*/
	graph_to_dot(cfg_entry);

	fflush(stdin);
	do
	{
		/*切片准则<lineno, var>*/
		printf("Please input the slicing criterion.\n");
		printf("line number: ");
		scanf("%d", &lineno);

		printf("Set of variables: ");
		while (scanf("%s", name_temp) != EOF)
		{
			p = (Symbol *)malloc(sizeof(Symbol));
			strcpy(p->name, name_temp);

			p->next = var;
			var = p;
		}
	}while (programSlicing(cfg_entry, lineno, var, &slicing_result));

	printSlicingResult(argv[1], slicing_result, ast_root, cfg_entry);

	/*释放节点所占空间*/
	freeAstNode(ast_root);
	freeCfgNode(cfg_entry);
	
	return 0;
}