#ifndef PRINT_SLICING_RESULT_H
#define PRINT_SLICING_RESULT_H

#include "ast_node.h"
#include "program_slicing.h"

extern int linesno;	/*来自词法分析器*/

void printSlicingResult(char *sourcefile, RecordCfgNode *slicing_result,
				 			AstNode *ast_root, CfgNode *entry);

void initialiseCfgArray(CfgNode *node_cfg, CfgNode **cfg_array);

int isInSlicingResult(RecordCfgNode *slicing_result, int linecount);

int isInAstNode(AstNode *node_ast, int linecount);

#endif