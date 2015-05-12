#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bison_c.tab.h"
#include "ast_node.h"
#include "cfg_node.h"
#include "graph_to_dot.h"
#include "write_ast_to_file.h"

int main(int argc, char **argv)
{
	CfgNode *cfg_entry;
	/*int linenumber;
	Symbol *var = NULL, *p;
	char name_temp[20];

	printf("Please input the slicing criterion.\n");
	printf("line number: ");
	scanf("%d", &linenumber);

	while (scanf("%s", name_temp) != EOF)
	{
		p = (Symbol *)malloc(sizeof(Symbol));
		strcpy(p->name, name_temp);

		p->next = var;
		var = p;
	}*/

	/*yyparse()返回值为0或1
	返回0表示执行成功，并已建立好抽象语法树;
	返回1表示执行出错，会自动调用yyerror()函数输出错误信息.*/
	if(yyparse())
		return 1;

	node_counter = 1;
	initialiseNodeId(ast_root);

	writeAstToFile(ast_root);

	cfg_entry = createCFG(ast_root);

	graph_to_dot(cfg_entry);

	freeAstNode(ast_root);
	freeCfgNode(cfg_entry);
	
	return 0;
}