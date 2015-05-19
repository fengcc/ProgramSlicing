%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "ast_node.h"

	void yyerror(char *s);
%}

%union {
	struct AstNode *a;
	double d;
	char s[32];
}

%token AUTO DEFINE EXTERN REGISTER STATIC TYPEDEF
%token CHAR DOUBLE FLOAT INT LONG SHORT SIGNED UNSIGNED VOID VOLATILE
%token BREAK CASE CONTINUE DEFAULT DO ELSE FOR GOTO IF RETURN SWITCH WHILE 
%token ENUM STRUCT UNION SIZEOF

%token <d> NUMBER 
%token <s> IDENTIFIER CHARACTER STRING_CONSTANT

%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN INC_OP DEC_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP


%type <a> primary_expression postfix_expression argument_expression_list unary_expression unary_operator cast_expression
%type <a> type_name multiplicative_expression additive_expression relational_expression equality_expression and_expression
%type <a> exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression expression
%type <a> declaration init_declarator_list init_declarator declarator initializer
%type <a> statement assignment_statement expression_statement selection_statement iteration_statement jump_statement
%type <a> translation_unit function_definition compound_statement block_item_list block_item

%start translation_unit

%nonassoc LOWER_THAN_ELSE	/* 定义优先级，解决二义性 */
%nonassoc ELSE

%%

primary_expression
	: IDENTIFIER			/*标识符*/		{ $$ = newAstNode(Identifier, newNodeValue(0, $1), linesno); }
	| NUMBER				/*数字*/			{ $$ = newAstNode(Number, newNodeValue(1, $1), linesno); }
	| CHARACTER				/*字符*/			{ $$ = newAstNode(String, newNodeValue(0, $1), linesno); }
	| STRING_CONSTANT		/*字符串常量*/	{ $$ = newAstNode(String, newNodeValue(0, $1), linesno); }
	| '(' expression ')'					{ $$ = newAstNode(Expression, newNodeValue(0, "primary_expression"), linesno);
											  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), linesno);
											  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), linesno);
											  linkAstNode($$, left_bracket, $2, right_bracket, NULL); }
	;

postfix_expression			/*数组，自定义函数 均未考虑*/
	: primary_expression					{ $$ = $1; }
	| postfix_expression INC_OP				{ $$ = newAstNode(Expression, newNodeValue(0, "postfix_expression"), linesno);
											  AstNode *inc_op = newAstNode(Operator, newNodeValue(0, "++"), linesno);
											  linkAstNode($$, $1, inc_op, NULL); }
	| postfix_expression DEC_OP				{ $$ = newAstNode(Expression, newNodeValue(0, "postfix_expression"), linesno);
											  AstNode *dec_op = newAstNode(Operator, newNodeValue(0, "--"), linesno);
											  linkAstNode($$, $1, dec_op, NULL); }
	| postfix_expression '(' ')'			/*无参库函数调用*/	
											{ $$ = newAstNode(Expression, newNodeValue(0, "postfix_expression"), linesno);
											  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), linesno);
											  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), linesno);
											  linkAstNode($$, $1, left_bracket, right_bracket, NULL); }
	| postfix_expression '(' argument_expression_list ')' 	/*有参库函数调用*/
											{ $$ = newAstNode(Expression, newNodeValue(0, "postfix_expression"), linesno);
											  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), linesno);
											  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), linesno);
											  linkAstNode($$, $1, left_bracket, $3, right_bracket, NULL); }
	;						

unary_expression
	: postfix_expression					{ $$ = $1; }
	| INC_OP unary_expression				{ $$ = newAstNode(Expression, newNodeValue(0, "unary_expression"), linesno);
											  AstNode *inc_op = newAstNode(Operator, newNodeValue(0, "++"), linesno);
											  linkAstNode($$, inc_op, $2, NULL); }
	| DEC_OP unary_expression				{ $$ = newAstNode(Expression, newNodeValue(0, "unary_expression"), linesno);
											  AstNode *dec_op = newAstNode(Operator, newNodeValue(0, "--"), linesno);
											  linkAstNode($$, dec_op, $2, NULL); }
	| unary_operator cast_expression		{ $$ = newAstNode(Expression, newNodeValue(0, "unary_expression"), linesno);
											  linkAstNode($$, $1, $2, NULL); }
	;

unary_operator		/*未考虑指针和取地址符*/
	: '+'									{ $$ = newAstNode(Operator, newNodeValue(0, "+"), linesno); }
	| '-'									{ $$ = newAstNode(Operator, newNodeValue(0, "-"), linesno); }
	| '~'									{ $$ = newAstNode(Operator, newNodeValue(0, "~"), linesno); }
	| '!'									{ $$ = newAstNode(Operator, newNodeValue(0, "!"), linesno); }
	;

cast_expression
	: unary_expression						{ $$ = $1; }
	| '(' type_name ')' cast_expression		/*强制类型转换*/
											{ $$ = newAstNode(Expression, newNodeValue(0, "cast_expression"), linesno);
											  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), linesno);
											  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), linesno);
											  linkAstNode($$, left_bracket, $2, right_bracket, $4, NULL); }
	;

multiplicative_expression
	: cast_expression				{ $$ = $1; }
	| multiplicative_expression '*' cast_expression	
									{ $$ = newAstNode(Expression, newNodeValue(0, "multiplicative_expression"), linesno); 
									  AstNode *multiply = newAstNode(Operator, newNodeValue(0, "*"), linesno);
									  linkAstNode($$, $1, multiply, $3, NULL); }
	| multiplicative_expression '/' cast_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "multiplicative_expression"), linesno); 
									  AstNode *divide = newAstNode(Operator, newNodeValue(0, "/"), linesno);
									  linkAstNode($$, $1, divide, $3, NULL); }
	| multiplicative_expression '%' cast_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "multiplicative_expression"), linesno); 
									  AstNode *divide = newAstNode(Operator, newNodeValue(0, "%"), linesno);
									  linkAstNode($$, $1, divide, $3, NULL); }
	;

additive_expression
	: multiplicative_expression		{ $$ = $1; }
	| additive_expression '+' multiplicative_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "additive_expression"), linesno);
									  AstNode *add = newAstNode(Operator, newNodeValue(0, "+"), linesno);
									  linkAstNode($$, $1, add, $3, NULL); }
	| additive_expression '-' multiplicative_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "additive_expression"), linesno);
									  AstNode *sub = newAstNode(Operator, newNodeValue(0, "-"), linesno);
									  linkAstNode($$, $1, sub, $3, NULL); }
	;

/*没有考虑移位运算*/

relational_expression
	: additive_expression			{ $$ = $1; }
	| relational_expression '<' additive_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "relational_expression"), linesno);
									  AstNode *less = newAstNode(Operator, newNodeValue(0, "<"), linesno);
									  linkAstNode($$, $1, less, $3, NULL); }
	| relational_expression '>' additive_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "relational_expression"), linesno);
									  AstNode *greater = newAstNode(Operator, newNodeValue(0, ">"), linesno);
									  linkAstNode($$, $1, greater, $3, NULL); }
	| relational_expression LE_OP additive_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "relational_expression"), linesno);
									  AstNode *le_op = newAstNode(Operator, newNodeValue(0, "<="), linesno);
									  linkAstNode($$, $1, le_op, $3, NULL); }
	| relational_expression GE_OP additive_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "relational_expression"), linesno);
									  AstNode *ge_op = newAstNode(Operator, newNodeValue(0, ">="), linesno);
									  linkAstNode($$, $1, ge_op, $3, NULL); }
	;

equality_expression
	: relational_expression			{ $$ = $1; }
	| equality_expression EQ_OP relational_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "equality_expression"), linesno);
									  AstNode *eq_op = newAstNode(Operator, newNodeValue(0, "=="), linesno);
									  linkAstNode($$, $1, eq_op, $3, NULL); }
	| equality_expression NE_OP relational_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "equality_expression"), linesno);
									  AstNode *ne_op = newAstNode(Operator, newNodeValue(0, "!="), linesno);
									  linkAstNode($$, $1, ne_op, $3, NULL); }
	;

and_expression
	: equality_expression			{ $$ = $1; }
	| and_expression '&' equality_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "and_expression"), linesno);
									  AstNode *and = newAstNode(Operator, newNodeValue(0, "&"), linesno);
									  linkAstNode($$, $1, and, $3, NULL); }								
	;

exclusive_or_expression
	: and_expression				{ $$ = $1; }
	| exclusive_or_expression '^' and_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "exclusive_or_expression"), linesno);
									  AstNode *e_or = newAstNode(Operator, newNodeValue(0, "^"), linesno);
									  linkAstNode($$, $1, e_or, $3, NULL); }
	;

inclusive_or_expression
	: exclusive_or_expression		{ $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "inclusive_or_expression"), linesno);
									  AstNode *i_or = newAstNode(Operator, newNodeValue(0, "|"), linesno);
									  linkAstNode($$, $1, i_or, $3, NULL); }								
	;

logical_and_expression
	: inclusive_or_expression		{ $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "logical_and_expression"), linesno);
									  AstNode *l_and = newAstNode(Operator, newNodeValue(0, "&&"), linesno);
									  linkAstNode($$, $1, l_and, $3, NULL); }
	;

logical_or_expression
	: logical_and_expression		{ $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "logical_or_expression"), linesno);
									  AstNode *l_or = newAstNode(Operator, newNodeValue(0, "||"), linesno);
									  linkAstNode($$, $1, l_or, $3, NULL); }
	;

expression
	: logical_or_expression			{ $$ = $1; }
	;

argument_expression_list
	: expression					{ $$ = $1; }
	| argument_expression_list ',' expression
									{ $$ = newAstNode(Expression, newNodeValue(0, "argument_expression_list"), linesno);
									  AstNode *comma = newAstNode(Operator, newNodeValue(0, ","), linesno);
									  linkAstNode($$, $1, comma, $3, NULL); }
	;



declaration						/* 暂时只考虑了简单的变量声明 */
	: type_name init_declarator_list ';'
									{ $$ = newAstNode(Declaration, newNodeValue(0, "declaration"), linesno);
									  linkAstNode($$, $1, $2, NULL); }
	;

type_name					/* 类型名 */
	: CHAR							{ $$ = newAstNode(Keyword, newNodeValue(0, "char"), linesno); }
	| DOUBLE						{ $$ = newAstNode(Keyword, newNodeValue(0, "double"), linesno); }
	| FLOAT							{ $$ = newAstNode(Keyword, newNodeValue(0, "float"), linesno); }
	| INT							{ $$ = newAstNode(Keyword, newNodeValue(0, "int"), linesno); }
	| LONG							{ $$ = newAstNode(Keyword, newNodeValue(0, "long"), linesno); }
	| SHORT							{ $$ = newAstNode(Keyword, newNodeValue(0, "short"), linesno); }
	| SIGNED						{ $$ = newAstNode(Keyword, newNodeValue(0, "signed"), linesno); }
	| UNSIGNED						{ $$ = newAstNode(Keyword, newNodeValue(0, "unsigned"), linesno); }
	;

init_declarator_list 			/* 初始化列表 */
	: init_declarator				{ $$ = $1; }
	| init_declarator_list ',' init_declarator
									{ $$ = newAstNode(Expression, newNodeValue(0, "init_declarator_list"), linesno);
									  AstNode *comma = newAstNode(Operator, newNodeValue(0, ","), linesno);
									  linkAstNode($$, $1, comma, $3, NULL); }
	;

init_declarator
	: declarator					{ $$ = $1; }
	| declarator '=' initializer	{ $$ = newAstNode(Expression, newNodeValue(0, "init_declarator"), linesno);
									  AstNode *assign = newAstNode(Operator, newNodeValue(0, "="), linesno);
									  linkAstNode($$, $1, assign, $3, NULL); }
	;

declarator 						/* 暂时只考虑了简单的变量声明 */
	: IDENTIFIER					{ $$ = newAstNode(Identifier, newNodeValue(0, $1), linesno); }
	;

initializer
	: NUMBER						{ $$ = newAstNode(Number, newNodeValue(1, $1), linesno); }
	| IDENTIFIER					{ $$ = newAstNode(Identifier, newNodeValue(0, $1), linesno); }
	| CHARACTER						{ $$ = newAstNode(String, newNodeValue(0, $1), linesno); }
	;




statement
	: assignment_statement 		/* 赋值语句 */	{ $$ = $1; }
	| expression_statement		/* 表达式语句 */	{ $$ = $1; }
	| selection_statement		/* 选择语句 */	{ $$ = $1; }
	| iteration_statement		/* 循环语句 */	{ $$ = $1; }
	| jump_statement			/* 跳转语句 */	{ $$ = $1; }
	| compound_statement						{ $$ = $1; }
	;

assignment_statement
	: IDENTIFIER '=' expression ';'		{ $$ = newAstNode(Statement, newNodeValue(0, "assignment_statement"), linesno);
										  AstNode *identifier = newAstNode(Identifier, newNodeValue(0, $1), linesno);
										  AstNode *assign = newAstNode(Operator, newNodeValue(0, "="), linesno);
										  AstNode *semicolon = newAstNode(Operator, newNodeValue(0, ";"), linesno);
										  linkAstNode($$, identifier, assign, $3, semicolon, NULL); }
	;

expression_statement
	: expression ';'					{ $$ = newAstNode(Statement, newNodeValue(0, "expression_statement"), linesno);
										  AstNode *semicolon = newAstNode(Operator, newNodeValue(0, ";"), linesno);
										  linkAstNode($$, $1, semicolon, NULL); }
	;

selection_statement
	: IF '(' expression ')' compound_statement %prec LOWER_THAN_ELSE
								{ $$ = newAstNode(Statement, newNodeValue(0, "selection_statement_no_else"), $3->linenumber);
								  $$->endlinenumber = $5->firstchild->linenumber;
								  AstNode *if_keyword = newAstNode(Keyword, newNodeValue(0, "if"), $3->linenumber);
								  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), $3->linenumber);
								  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), $3->linenumber);
								  linkAstNode($$, if_keyword, left_bracket, $3, right_bracket, $5, NULL); }
	| IF '(' expression ')' compound_statement ELSE compound_statement
								{ $$ = newAstNode(Statement, newNodeValue(0, "selection_statement_with_else"), $3->linenumber);
								  $$->endlinenumber = $7->firstchild->linenumber;
								  AstNode *if_keyword = newAstNode(Keyword, newNodeValue(0, "if"), $3->linenumber);
								  AstNode *else_keyword = newAstNode(Keyword, newNodeValue(0, "else"), $3->linenumber);
								  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), $3->linenumber);
								  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), $3->linenumber);
								  linkAstNode($$, if_keyword, left_bracket, $3, right_bracket, $5, else_keyword, $7, NULL); }
	;

iteration_statement
	: WHILE '(' expression ')' compound_statement
								{ $$ = newAstNode(Statement, newNodeValue(0, "iteration_statement"), $3->linenumber);
								  $$->endlinenumber = $5->firstchild->linenumber;
								  AstNode *while_keyword = newAstNode(Keyword, newNodeValue(0, "while"), $3->linenumber);
								  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), $3->linenumber);
								  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), $3->linenumber);
								  linkAstNode($$, while_keyword, left_bracket, $3, right_bracket, $5, NULL); }
	;

jump_statement
	: RETURN ';'						{ $$ = newAstNode(Statement, newNodeValue(0, "jump_statement"), linesno);
										  AstNode *return_keyword = newAstNode(Keyword, newNodeValue(0, "return"), linesno);
										  AstNode *semicolon = newAstNode(Operator, newNodeValue(0, ";"), linesno);
										  linkAstNode($$, return_keyword, semicolon, NULL); }
	| RETURN expression ';'				{ $$ = newAstNode(Statement, newNodeValue(0, "jump_statement"), linesno);
										  AstNode *return_keyword = newAstNode(Keyword, newNodeValue(0, "return"), linesno);
										  AstNode *semicolon = newAstNode(Operator, newNodeValue(0, ";"), linesno);
										  linkAstNode($$, return_keyword, $2, semicolon, NULL); }
	;



translation_unit
	: function_definition	/*仅仅用来考虑无参main函数的，其他函数情况暂时没有考虑*/
									{ ast_root = $1; }
	;

function_definition
	: type_name IDENTIFIER '(' ')' compound_statement
								{ $$ = newAstNode(FunctionDefinition, newNodeValue(0, "function_definition"), $1->linenumber);
								  AstNode *identifier = newAstNode(Identifier, newNodeValue(0, $2), $1->linenumber);
								  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), $1->linenumber);
								  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), $1->linenumber);
								  linkAstNode($$, $1, identifier, left_bracket, right_bracket, $5, NULL); }
	;

compound_statement
	: '{' '}'					{ $$ = newAstNode(FunctionDefinition, newNodeValue(0, "compound_statement"), linesno);
								  AstNode *big_left_bracket = newAstNode(Operator, newNodeValue(0, "{"), linesno);
								  AstNode *big_right_bracket = newAstNode(Operator, newNodeValue(0, "}"), linesno);
								  linkAstNode($$, big_left_bracket, big_right_bracket, NULL); }
	| '{' block_item_list '}'	{ $$ = newAstNode(FunctionDefinition, newNodeValue(0, "compound_statement"), $2->linenumber-1);
								  AstNode *big_left_bracket = newAstNode(Operator, newNodeValue(0, "{"), linesno);
								  AstNode *big_right_bracket = newAstNode(Operator, newNodeValue(0, "}"), linesno);
								  linkAstNode($$, big_left_bracket, $2, big_right_bracket, NULL); }
	;

block_item_list
	: block_item					{ $$ = $1; }
	| block_item_list block_item	{ $$ = newAstNode(FunctionDefinition, newNodeValue(0, "block_item_list"), $1->linenumber);
									  linkAstNode($$, $1, $2, NULL); }
	;

block_item
	: declaration					{ $$ = $1; }
	| statement						{ $$ = $1; }	
	;

%%

void yyerror(char *s)
{
	fflush(stdout);
	fprintf(stderr, "Error: lines %d: %s\n", linesno, s);
}