#ifndef WRITE_AST_TO_FILE_H
#define WRITE_AST_TO_FILE_H

#include "ast_node.h"

/*初始化抽象语法树节点索引, 由writeAstToFile调用*/
void writeNodeToFile(AstNode *root, FILE *file_stream);
/*将抽象语法树写入到文件里*/

void writeAstToFile(AstNode *root);

/*判断节点值是string型还是number型*/
int valueIsNumber(enum AstNodeType type);

#endif