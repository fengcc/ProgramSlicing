#include <stdio.h>
#include <stdlib.h>

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
	RecordCfgNode *visited_node_list = NULL, *p;

	if ((dotfile = fopen("cfg.dot", "w")) == NULL)
	{
		printf("open file failed!\n");
		return;
	}

	fprintf(dotfile, "digraph CFG {\n");

	DFSTraverse(root, dotfile, &visited_node_list);

	fprintf(dotfile, "}\n");

	fclose(dotfile);

	while (visited_node_list)
	{
		visited_node_list->node_cfg->visited = false;

		p = visited_node_list;
		visited_node_list = visited_node_list->next;
		free(p);
	}

	/*编译产生图片*/
	system("dot -Tpng -o cfg.png cfg.dot");
}

void DFSTraverse(CfgNode *node, FILE *dotfile, RecordCfgNode **visited_node)
{
	CfgNodeList *p;
	RecordCfgNode *q;

	node->visited = true;

	q = (RecordCfgNode *)malloc(sizeof(RecordCfgNode));
	q->node_cfg = node;
	q->next = *visited_node;
	*visited_node = q;

	for (p = node->successor; p ; p = p->next)
	{
		fprintf(dotfile, "	%s%d -> %s%d\n", 
			enum_to_string[node->nodetype_cfg], node->node_of_ast ? node->node_of_ast->linenumber : 0, 
			enum_to_string[p->node_cfg->nodetype_cfg], 
			p->node_cfg->node_of_ast ? p->node_cfg->node_of_ast->linenumber : 0 );
		
		if ( !p->node_cfg->visited)
			DFSTraverse(p->node_cfg, dotfile, visited_node);
	}
}
