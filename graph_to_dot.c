#include <stdio.h>

#include "graph_to_dot.h"

char *enum_to_string[] = {
	"Entry",
	"Assign_express_jump",
	"Select",
	"Iteration",
	"Exit"
};

void graph_to_dot(CfgNode *root)
{
	FILE *dotfile;

	if ((dotfile = fopen("cfg.dot", "w")) == NULL)
	{
		printf("open file failed!\n");
		return;
	}

	fprintf(dotfile, "digraph CFG {\n");

	DFSTraverse(root, dotfile);

	fprintf(dotfile, "}\n");

	fclose(dotfile);
}

void DFSTraverse(CfgNode *node, FILE *dotfile)
{
	CfgNodeList *p;

	node->visited = true;

	for (p = node->successor; p ; p = p->next)
	{
		fprintf(dotfile, "	%s%d -> %s%d\n", 
			enum_to_string[node->nodetype_cfg], node->node_of_ast ? node->node_of_ast->id : 0, 
			enum_to_string[p->node_cfg->nodetype_cfg], 
			p->node_cfg->node_of_ast ? p->node_cfg->node_of_ast->id : 0 );
		
		if ( !p->node_cfg->visited)
			DFSTraverse(p->node_cfg, dotfile);
	}
}
