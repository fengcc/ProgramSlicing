/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BISON_C_TAB_H_INCLUDED
# define YY_YY_BISON_C_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AUTO = 258,
     DEFINE = 259,
     EXTERN = 260,
     REGISTER = 261,
     STATIC = 262,
     TYPEDEF = 263,
     CHAR = 264,
     DOUBLE = 265,
     FLOAT = 266,
     INT = 267,
     LONG = 268,
     SHORT = 269,
     SIGNED = 270,
     UNSIGNED = 271,
     VOID = 272,
     VOLATILE = 273,
     BREAK = 274,
     CASE = 275,
     CONTINUE = 276,
     DEFAULT = 277,
     DO = 278,
     ELSE = 279,
     FOR = 280,
     GOTO = 281,
     IF = 282,
     RETURN = 283,
     SWITCH = 284,
     WHILE = 285,
     ENUM = 286,
     STRUCT = 287,
     UNION = 288,
     SIZEOF = 289,
     NUMBER = 290,
     IDENTIFIER = 291,
     CHARACTER = 292,
     STRING_CONSTANT = 293,
     ADD_ASSIGN = 294,
     SUB_ASSIGN = 295,
     MUL_ASSIGN = 296,
     DIV_ASSIGN = 297,
     INC_OP = 298,
     DEC_OP = 299,
     AND_OP = 300,
     OR_OP = 301,
     LE_OP = 302,
     GE_OP = 303,
     EQ_OP = 304,
     NE_OP = 305,
     LOWER_THAN_ELSE = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 9 "bison_c.y"

	struct AstNode *a;
	double d;
	char s[32];


/* Line 2058 of yacc.c  */
#line 115 "bison_c.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_BISON_C_TAB_H_INCLUDED  */
