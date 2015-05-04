#include <stdio.h>

#include "bison_c.tab.h"
#include "ast_node.h"
#include "cfg_node.h"
#include "graph_to_dot.h"

int main(int argc, char **argv)
{
	CfgNode *cfg_entry;

	/*yyparse()返回值为0或1
	返回0表示执行成功，并已建立好抽象语法树;
	返回1表示执行出错，会自动调用yyerror()函数输出错误信息.*/
	if(yyparse())
		return 1;

	node_counter = 1;
	initialiseNodeId(ast_root);

	cfg_entry = createCFG(ast_root);

	graph_to_dot(cfg_entry);

	freeCfgNode(cfg_entry);
	freeAstNode(ast_root);

	return 0;
}