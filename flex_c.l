%{
	#include <stdlib.h>
	#include <string.h>
	#include "bison_c.tab.h"
	#include "ast_node.h"

	int linesno = 1;
	
	void comment();
	void ignoreHeadfile();
%}

digit			[0-9]
number			("+"|"-")?{digit}+
letter			[a-zA-Z_]
identifier		{letter}({letter}|{digit})*

%%

"/*"			{ comment(); }
"//".*			{ /*ignore comment*/ }

"auto"			{ return AUTO; }
"break"			{ return BREAK; }
"case"			{ return CASE; }
"char"			{ return CHAR; }
"define"		{ return DEFINE; }
"continue"		{ return CONTINUE; }
"default"		{ return DEFAULT; }
"do"			{ return DO; }
"double"		{ return DOUBLE; }
"else"			{ return ELSE; }
"enum"			{ return ENUM; }
"extern"		{ return EXTERN; }
"float"			{ return FLOAT; }
"for"			{ return FOR; }
"goto"			{ return GOTO; }
"if"			{ return IF; }
"int"			{ return INT; }
"long"			{ return LONG; }
"register"		{ return REGISTER; }
"return"		{ return RETURN; }
"short"			{ return SHORT; }
"signed"		{ return SIGNED; }
"sizeof"		{ return SIZEOF; }
"static"		{ return STATIC; }
"struct"		{ return STRUCT; }
"switch"		{ return SWITCH; }
"typedef"		{ return TYPEDEF; }
"union"			{ return UNION; }
"unsigned"		{ return UNSIGNED; }
"void"			{ return VOID; }
"volatile"		{ return VOLATILE; }
"while"			{ return WHILE; }

"+="			{ return ADD_ASSIGN; }
"-="			{ return SUB_ASSIGN; }
"*="			{ return MUL_ASSIGN; }
"/="			{ return DIV_ASSIGN; }
"++"			{ return INC_OP; }
"--"			{ return DEC_OP; }
"&&"			{ return AND_OP; }
"||"			{ return OR_OP; }
"<="			{ return LE_OP; }
">="			{ return GE_OP; }
"=="			{ return EQ_OP; }
"!="			{ return NE_OP; }
";"				{ return ';'; }
"{"				{ return '{'; }
"}"				{ return '}'; }
","				{ return ','; }
":"				{ return ':'; }
"="				{ return '='; }
"("				{ return '('; }
")"				{ return ')'; }
"["				{ return '['; }
"]"				{ return ']'; }
"."				{ return '.'; }
"&"				{ return '&'; }
"!"				{ return '!'; }
"~"				{ return '~'; }
"-"				{ return '-'; }
"+"				{ return '+'; }
"*"				{ return '*'; }
"/"				{ return '/'; }
"%"				{ return '%'; }
"<"				{ return '<'; }
">"				{ return '>'; }
"^"				{ return '^'; }
"|"				{ return '|'; }
"?"				{ return '?'; }

{number}("."{digit})?	{ yylval.d = atof(yytext); return NUMBER; }
{identifier}			{ strcpy(yylval.s, yytext); return IDENTIFIER; }
\"(.)+\"				{ strcpy(yylval.s, yytext); return STRING_CONSTANT; }
\'.\'					{ yylval.s[0] = *yytext; yylval.s[1] = '\0'; return CHARACTER; }		
"#"						{ ignoreHeadfile(); linesno++; }
\n						{ linesno++; }
.						{ /*other characters*/ }

%%
void comment(void)
{
	char c ,prev = NULL;

	while ((c = input()) != 0)
	{	
		if ( c == '\n')
			linesno++;
		if (prev == '*' && c == '/')
			return;
		prev = c;
	}
	error("unterminated comment");
}

void ignoreHeadfile()
{
	while(input() != '\n');

	return;
}