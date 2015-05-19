/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "bison_c.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include "ast_node.h"

	void yyerror(char *s);

/* Line 371 of yacc.c  */
#line 76 "bison_c.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison_c.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 9 "bison_c.y"

	struct AstNode *a;
	double d;
	char s[32];


/* Line 387 of yacc.c  */
#line 177 "bison_c.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 205 "bison_c.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,     2,     2,    60,    63,     2,
      52,    53,    58,    54,    66,    55,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    67,
      61,    68,    62,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    65,    70,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    15,    17,    20,
      23,    27,    32,    34,    37,    40,    43,    45,    47,    49,
      51,    53,    58,    60,    64,    68,    72,    74,    78,    82,
      84,    88,    92,    96,   100,   102,   106,   110,   112,   116,
     118,   122,   124,   128,   130,   134,   136,   140,   142,   144,
     148,   152,   154,   156,   158,   160,   162,   164,   166,   168,
     170,   174,   176,   180,   182,   184,   186,   188,   190,   192,
     194,   196,   198,   200,   205,   208,   214,   222,   228,   231,
     235,   237,   243,   246,   250,   252,   255,   257
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     100,     0,    -1,    36,    -1,    35,    -1,    37,    -1,    38,
      -1,    52,    86,    53,    -1,    72,    -1,    73,    43,    -1,
      73,    44,    -1,    73,    52,    53,    -1,    73,    52,    87,
      53,    -1,    73,    -1,    43,    74,    -1,    44,    74,    -1,
      75,    76,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    74,    -1,    52,    89,    53,    76,    -1,    76,    -1,
      77,    58,    76,    -1,    77,    59,    76,    -1,    77,    60,
      76,    -1,    77,    -1,    78,    54,    77,    -1,    78,    55,
      77,    -1,    78,    -1,    79,    61,    78,    -1,    79,    62,
      78,    -1,    79,    47,    78,    -1,    79,    48,    78,    -1,
      79,    -1,    80,    49,    79,    -1,    80,    50,    79,    -1,
      80,    -1,    81,    63,    80,    -1,    81,    -1,    82,    64,
      81,    -1,    82,    -1,    83,    65,    82,    -1,    83,    -1,
      84,    45,    83,    -1,    84,    -1,    85,    46,    84,    -1,
      85,    -1,    86,    -1,    87,    66,    86,    -1,    89,    90,
      67,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    91,    -1,
      90,    66,    91,    -1,    92,    -1,    92,    68,    93,    -1,
      36,    -1,    35,    -1,    36,    -1,    37,    -1,    95,    -1,
      96,    -1,    97,    -1,    98,    -1,    99,    -1,   102,    -1,
      36,    68,    86,    67,    -1,    86,    67,    -1,    27,    52,
      86,    53,   102,    -1,    27,    52,    86,    53,   102,    24,
     102,    -1,    30,    52,    86,    53,   102,    -1,    28,    67,
      -1,    28,    86,    67,    -1,   101,    -1,    89,    36,    52,
      53,   102,    -1,    69,    70,    -1,    69,   103,    70,    -1,
     104,    -1,   103,   104,    -1,    88,    -1,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    42,    43,    44,    45,    52,    53,    56,
      59,    64,    72,    73,    76,    79,    84,    85,    86,    87,
      91,    92,   100,   101,   105,   109,   116,   117,   121,   130,
     131,   135,   139,   143,   150,   151,   155,   162,   163,   170,
     171,   178,   179,   186,   187,   194,   195,   202,   206,   207,
     216,   222,   223,   224,   225,   226,   227,   228,   229,   233,
     234,   241,   242,   248,   252,   253,   254,   261,   262,   263,
     264,   265,   266,   270,   278,   284,   291,   302,   312,   316,
     325,   330,   339,   343,   350,   351,   356,   357
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "DEFINE", "EXTERN", "REGISTER",
  "STATIC", "TYPEDEF", "CHAR", "DOUBLE", "FLOAT", "INT", "LONG", "SHORT",
  "SIGNED", "UNSIGNED", "VOID", "VOLATILE", "BREAK", "CASE", "CONTINUE",
  "DEFAULT", "DO", "ELSE", "FOR", "GOTO", "IF", "RETURN", "SWITCH",
  "WHILE", "ENUM", "STRUCT", "UNION", "SIZEOF", "NUMBER", "IDENTIFIER",
  "CHARACTER", "STRING_CONSTANT", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "INC_OP", "DEC_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "LOWER_THAN_ELSE", "'('", "')'", "'+'", "'-'", "'~'",
  "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'", "','",
  "';'", "'='", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression", "expression",
  "argument_expression_list", "declaration", "type_name",
  "init_declarator_list", "init_declarator", "declarator", "initializer",
  "statement", "assignment_statement", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "function_definition", "compound_statement",
  "block_item_list", "block_item", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    40,    41,    43,    45,   126,    33,    42,    47,
      37,    60,    62,    38,    94,   124,    44,    59,    61,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    75,
      76,    76,    77,    77,    77,    77,    78,    78,    78,    79,
      79,    79,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    87,    87,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    92,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    96,    97,    97,    98,    99,    99,
     100,   101,   102,   102,   103,   103,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     2,     2,
       3,     4,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     5,     7,     5,     2,     3,
       1,     5,     2,     3,     1,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    51,    52,    53,    54,    55,    56,    57,    58,     0,
       0,    80,     0,     1,     0,     0,     0,    81,     0,     0,
       0,     3,     2,     4,     5,     0,     0,     0,    16,    17,
      18,    19,    82,     7,    12,    20,     0,    22,    26,    29,
      34,    37,    39,    41,    43,    45,    47,     0,    86,     0,
      87,    67,    68,    69,    70,    71,    72,     0,    84,     0,
       2,    78,     0,     0,     0,     0,    13,    14,     0,     0,
       8,     9,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    63,     0,    59,    61,    83,    85,     0,    79,     0,
       0,     6,     0,    10,    48,     0,    23,    24,    25,    27,
      28,    32,    33,    30,    31,    35,    36,    38,    40,    42,
      44,    46,     0,    50,     0,     0,     0,    73,    21,    11,
       0,    60,    64,    65,    66,    62,    75,    77,    49,     0,
      76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,   105,    48,    49,    92,
      93,    94,   135,    50,    51,    52,    53,    54,    55,    10,
      11,    56,    57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
     133,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -24,
      15,   -51,   -12,   -51,   -25,   -14,    21,   -51,    -2,   143,
      17,   -51,     6,   -51,   -51,   168,   168,   120,   -51,   -51,
     -51,   -51,   -51,   -51,   -33,   -51,   191,   -51,     8,   -37,
      -9,   -29,    16,    33,    35,    59,    67,    38,   -51,    80,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,    71,   -51,   191,
     -51,   -51,    50,   191,   191,   191,   -51,   -51,    65,    66,
     -51,   -51,   -30,   -51,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     -51,   -51,     5,   -51,    52,   -51,   -51,    68,   -51,    69,
      70,   -51,   191,   -51,   -51,   -50,   -51,   -51,   -51,     8,
       8,   -37,   -37,   -37,   -37,    -9,    -9,   -29,    16,    33,
      35,    59,    80,   -51,    57,   -14,   -14,   -51,   -51,   -51,
     191,   -51,   -51,   -51,   -51,   -51,   114,   -51,   -51,   -14,
     -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,    63,   -51,   -32,    18,   -19,    19,    54,
      64,    72,    73,    62,   -51,   -18,   -51,   -51,     2,   -51,
      30,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -15,   -51,    96
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      17,    62,     9,   129,    73,    21,    60,    23,    24,    68,
      70,    71,    12,    25,    26,    13,   130,    77,    78,    72,
      83,    84,    27,   103,    28,    29,    30,    31,    15,    69,
       1,     2,     3,     4,     5,     6,     7,     8,    79,    80,
      14,    97,   106,   107,   108,    99,   100,    68,    18,    19,
      59,    20,    81,    82,   104,    16,    21,    22,    23,    24,
     111,   112,   113,   114,    25,    26,    74,    75,    76,    63,
     128,   122,   123,    27,    64,    28,    29,    30,    31,    85,
       1,     2,     3,     4,     5,     6,     7,     8,    66,    67,
      16,    32,   132,   133,   134,   109,   110,    86,    18,    19,
      87,    20,   115,   116,    88,    90,    21,    22,    23,    24,
     136,   137,   138,    89,    25,    26,    91,    98,   101,   102,
     124,   125,   126,    27,   140,    28,    29,    30,    31,     1,
       2,     3,     4,     5,     6,     7,     8,   127,   139,   117,
      16,    95,     1,     2,     3,     4,     5,     6,     7,     8,
     118,   121,   131,    96,     0,    21,    60,    23,    24,   119,
       0,   120,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    28,    29,    30,    31,    21,    60,
      23,    24,     0,     0,     0,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,    29,    30,
      31,     0,     0,    21,    60,    23,    24,     0,     0,     0,
      61,    25,    26,     0,     0,     0,     0,     0,     0,     0,
      65,     0,    28,    29,    30,    31,    21,    60,    23,    24,
       0,     0,     0,     0,    25,    26,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    28,    29,    30,    31
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      15,    19,     0,    53,    36,    35,    36,    37,    38,    27,
      43,    44,    36,    43,    44,     0,    66,    54,    55,    52,
      49,    50,    52,    53,    54,    55,    56,    57,    53,    27,
       9,    10,    11,    12,    13,    14,    15,    16,    47,    48,
      52,    59,    74,    75,    76,    63,    64,    65,    27,    28,
      52,    30,    61,    62,    72,    69,    35,    36,    37,    38,
      79,    80,    81,    82,    43,    44,    58,    59,    60,    52,
     102,    66,    67,    52,    68,    54,    55,    56,    57,    63,
       9,    10,    11,    12,    13,    14,    15,    16,    25,    26,
      69,    70,    35,    36,    37,    77,    78,    64,    27,    28,
      65,    30,    83,    84,    45,    67,    35,    36,    37,    38,
     125,   126,   130,    46,    43,    44,    36,    67,    53,    53,
      68,    53,    53,    52,   139,    54,    55,    56,    57,     9,
      10,    11,    12,    13,    14,    15,    16,    67,    24,    85,
      69,    70,     9,    10,    11,    12,    13,    14,    15,    16,
      86,    89,   122,    57,    -1,    35,    36,    37,    38,    87,
      -1,    88,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      67,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    14,    15,    16,    89,
     100,   101,    36,     0,    52,    53,    69,   102,    27,    28,
      30,    35,    36,    37,    38,    43,    44,    52,    54,    55,
      56,    57,    70,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    88,    89,
      94,    95,    96,    97,    98,    99,   102,   103,   104,    52,
      36,    67,    86,    52,    68,    52,    74,    74,    86,    89,
      43,    44,    52,    76,    58,    59,    60,    54,    55,    47,
      48,    61,    62,    49,    50,    63,    64,    65,    45,    46,
      67,    36,    90,    91,    92,    70,   104,    86,    67,    86,
      86,    53,    53,    53,    86,    87,    76,    76,    76,    77,
      77,    78,    78,    78,    78,    79,    79,    80,    81,    82,
      83,    84,    66,    67,    68,    53,    53,    67,    76,    53,
      66,    91,    35,    36,    37,    93,   102,   102,    86,    24,
     102
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 41 "bison_c.y"
    { (yyval.a) = newAstNode(Identifier, newNodeValue(0, (yyvsp[(1) - (1)].s)), linesno); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 42 "bison_c.y"
    { (yyval.a) = newAstNode(Number, newNodeValue(1, (yyvsp[(1) - (1)].d)), linesno); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 43 "bison_c.y"
    { (yyval.a) = newAstNode(String, newNodeValue(0, (yyvsp[(1) - (1)].s)), linesno); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 44 "bison_c.y"
    { (yyval.a) = newAstNode(String, newNodeValue(0, (yyvsp[(1) - (1)].s)), linesno); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 45 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "primary_expression"), linesno);
											  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), linesno);
											  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), linesno);
											  linkAstNode((yyval.a), left_bracket, (yyvsp[(2) - (3)].a), right_bracket, NULL); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 52 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 53 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "postfix_expression"), linesno);
											  AstNode *inc_op = newAstNode(Operator, newNodeValue(0, "++"), linesno);
											  linkAstNode((yyval.a), (yyvsp[(1) - (2)].a), inc_op, NULL); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 56 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "postfix_expression"), linesno);
											  AstNode *dec_op = newAstNode(Operator, newNodeValue(0, "--"), linesno);
											  linkAstNode((yyval.a), (yyvsp[(1) - (2)].a), dec_op, NULL); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 60 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "postfix_expression"), linesno);
											  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), linesno);
											  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), linesno);
											  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), left_bracket, right_bracket, NULL); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 65 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "postfix_expression"), linesno);
											  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), linesno);
											  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), linesno);
											  linkAstNode((yyval.a), (yyvsp[(1) - (4)].a), left_bracket, (yyvsp[(3) - (4)].a), right_bracket, NULL); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 72 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 73 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "unary_expression"), linesno);
											  AstNode *inc_op = newAstNode(Operator, newNodeValue(0, "++"), linesno);
											  linkAstNode((yyval.a), inc_op, (yyvsp[(2) - (2)].a), NULL); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 76 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "unary_expression"), linesno);
											  AstNode *dec_op = newAstNode(Operator, newNodeValue(0, "--"), linesno);
											  linkAstNode((yyval.a), dec_op, (yyvsp[(2) - (2)].a), NULL); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 79 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "unary_expression"), linesno);
											  linkAstNode((yyval.a), (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a), NULL); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 84 "bison_c.y"
    { (yyval.a) = newAstNode(Operator, newNodeValue(0, "+"), linesno); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 85 "bison_c.y"
    { (yyval.a) = newAstNode(Operator, newNodeValue(0, "-"), linesno); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 86 "bison_c.y"
    { (yyval.a) = newAstNode(Operator, newNodeValue(0, "~"), linesno); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 87 "bison_c.y"
    { (yyval.a) = newAstNode(Operator, newNodeValue(0, "!"), linesno); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 91 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 93 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "cast_expression"), linesno);
											  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), linesno);
											  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), linesno);
											  linkAstNode((yyval.a), left_bracket, (yyvsp[(2) - (4)].a), right_bracket, (yyvsp[(4) - (4)].a), NULL); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 100 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 102 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "multiplicative_expression"), linesno); 
									  AstNode *multiply = newAstNode(Operator, newNodeValue(0, "*"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), multiply, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 106 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "multiplicative_expression"), linesno); 
									  AstNode *divide = newAstNode(Operator, newNodeValue(0, "/"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), divide, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 110 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "multiplicative_expression"), linesno); 
									  AstNode *divide = newAstNode(Operator, newNodeValue(0, "%"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), divide, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 116 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 118 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "additive_expression"), linesno);
									  AstNode *add = newAstNode(Operator, newNodeValue(0, "+"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), add, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 122 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "additive_expression"), linesno);
									  AstNode *sub = newAstNode(Operator, newNodeValue(0, "-"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), sub, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 130 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 132 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "relational_expression"), linesno);
									  AstNode *less = newAstNode(Operator, newNodeValue(0, "<"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), less, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 136 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "relational_expression"), linesno);
									  AstNode *greater = newAstNode(Operator, newNodeValue(0, ">"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), greater, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 140 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "relational_expression"), linesno);
									  AstNode *le_op = newAstNode(Operator, newNodeValue(0, "<="), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), le_op, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 144 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "relational_expression"), linesno);
									  AstNode *ge_op = newAstNode(Operator, newNodeValue(0, ">="), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), ge_op, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 150 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 152 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "equality_expression"), linesno);
									  AstNode *eq_op = newAstNode(Operator, newNodeValue(0, "=="), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), eq_op, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 156 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "equality_expression"), linesno);
									  AstNode *ne_op = newAstNode(Operator, newNodeValue(0, "!="), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), ne_op, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 162 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 164 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "and_expression"), linesno);
									  AstNode *and = newAstNode(Operator, newNodeValue(0, "&"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), and, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 170 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 172 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "exclusive_or_expression"), linesno);
									  AstNode *e_or = newAstNode(Operator, newNodeValue(0, "^"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), e_or, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 178 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 180 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "inclusive_or_expression"), linesno);
									  AstNode *i_or = newAstNode(Operator, newNodeValue(0, "|"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), i_or, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 186 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 188 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "logical_and_expression"), linesno);
									  AstNode *l_and = newAstNode(Operator, newNodeValue(0, "&&"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), l_and, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 194 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 196 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "logical_or_expression"), linesno);
									  AstNode *l_or = newAstNode(Operator, newNodeValue(0, "||"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), l_or, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 202 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 206 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 208 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "argument_expression_list"), linesno);
									  AstNode *comma = newAstNode(Operator, newNodeValue(0, ","), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), comma, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 217 "bison_c.y"
    { (yyval.a) = newAstNode(Declaration, newNodeValue(0, "declaration"), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), NULL); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 222 "bison_c.y"
    { (yyval.a) = newAstNode(Keyword, newNodeValue(0, "char"), linesno); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 223 "bison_c.y"
    { (yyval.a) = newAstNode(Keyword, newNodeValue(0, "double"), linesno); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 224 "bison_c.y"
    { (yyval.a) = newAstNode(Keyword, newNodeValue(0, "float"), linesno); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 225 "bison_c.y"
    { (yyval.a) = newAstNode(Keyword, newNodeValue(0, "int"), linesno); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 226 "bison_c.y"
    { (yyval.a) = newAstNode(Keyword, newNodeValue(0, "long"), linesno); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 227 "bison_c.y"
    { (yyval.a) = newAstNode(Keyword, newNodeValue(0, "short"), linesno); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 228 "bison_c.y"
    { (yyval.a) = newAstNode(Keyword, newNodeValue(0, "signed"), linesno); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 229 "bison_c.y"
    { (yyval.a) = newAstNode(Keyword, newNodeValue(0, "unsigned"), linesno); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 233 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 235 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "init_declarator_list"), linesno);
									  AstNode *comma = newAstNode(Operator, newNodeValue(0, ","), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), comma, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 241 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 242 "bison_c.y"
    { (yyval.a) = newAstNode(Expression, newNodeValue(0, "init_declarator"), linesno);
									  AstNode *assign = newAstNode(Operator, newNodeValue(0, "="), linesno);
									  linkAstNode((yyval.a), (yyvsp[(1) - (3)].a), assign, (yyvsp[(3) - (3)].a), NULL); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 248 "bison_c.y"
    { (yyval.a) = newAstNode(Identifier, newNodeValue(0, (yyvsp[(1) - (1)].s)), linesno); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 252 "bison_c.y"
    { (yyval.a) = newAstNode(Number, newNodeValue(1, (yyvsp[(1) - (1)].d)), linesno); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 253 "bison_c.y"
    { (yyval.a) = newAstNode(Identifier, newNodeValue(0, (yyvsp[(1) - (1)].s)), linesno); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 254 "bison_c.y"
    { (yyval.a) = newAstNode(String, newNodeValue(0, (yyvsp[(1) - (1)].s)), linesno); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 261 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 262 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 263 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 264 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 265 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 266 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 270 "bison_c.y"
    { (yyval.a) = newAstNode(Statement, newNodeValue(0, "assignment_statement"), linesno);
										  AstNode *identifier = newAstNode(Identifier, newNodeValue(0, (yyvsp[(1) - (4)].s)), linesno);
										  AstNode *assign = newAstNode(Operator, newNodeValue(0, "="), linesno);
										  AstNode *semicolon = newAstNode(Operator, newNodeValue(0, ";"), linesno);
										  linkAstNode((yyval.a), identifier, assign, (yyvsp[(3) - (4)].a), semicolon, NULL); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 278 "bison_c.y"
    { (yyval.a) = newAstNode(Statement, newNodeValue(0, "expression_statement"), linesno);
										  AstNode *semicolon = newAstNode(Operator, newNodeValue(0, ";"), linesno);
										  linkAstNode((yyval.a), (yyvsp[(1) - (2)].a), semicolon, NULL); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 285 "bison_c.y"
    { (yyval.a) = newAstNode(Statement, newNodeValue(0, "selection_statement_no_else"), (yyvsp[(3) - (5)].a)->linenumber);
								  (yyval.a)->endlinenumber = (yyvsp[(5) - (5)].a)->firstchild->linenumber;
								  AstNode *if_keyword = newAstNode(Keyword, newNodeValue(0, "if"), (yyvsp[(3) - (5)].a)->linenumber);
								  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), (yyvsp[(3) - (5)].a)->linenumber);
								  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), (yyvsp[(3) - (5)].a)->linenumber);
								  linkAstNode((yyval.a), if_keyword, left_bracket, (yyvsp[(3) - (5)].a), right_bracket, (yyvsp[(5) - (5)].a), NULL); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 292 "bison_c.y"
    { (yyval.a) = newAstNode(Statement, newNodeValue(0, "selection_statement_with_else"), (yyvsp[(3) - (7)].a)->linenumber);
								  (yyval.a)->endlinenumber = (yyvsp[(7) - (7)].a)->firstchild->linenumber;
								  AstNode *if_keyword = newAstNode(Keyword, newNodeValue(0, "if"), (yyvsp[(3) - (7)].a)->linenumber);
								  AstNode *else_keyword = newAstNode(Keyword, newNodeValue(0, "else"), (yyvsp[(3) - (7)].a)->linenumber);
								  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), (yyvsp[(3) - (7)].a)->linenumber);
								  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), (yyvsp[(3) - (7)].a)->linenumber);
								  linkAstNode((yyval.a), if_keyword, left_bracket, (yyvsp[(3) - (7)].a), right_bracket, (yyvsp[(5) - (7)].a), else_keyword, (yyvsp[(7) - (7)].a), NULL); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 303 "bison_c.y"
    { (yyval.a) = newAstNode(Statement, newNodeValue(0, "iteration_statement"), (yyvsp[(3) - (5)].a)->linenumber);
								  (yyval.a)->endlinenumber = (yyvsp[(5) - (5)].a)->firstchild->linenumber;
								  AstNode *while_keyword = newAstNode(Keyword, newNodeValue(0, "while"), (yyvsp[(3) - (5)].a)->linenumber);
								  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), (yyvsp[(3) - (5)].a)->linenumber);
								  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), (yyvsp[(3) - (5)].a)->linenumber);
								  linkAstNode((yyval.a), while_keyword, left_bracket, (yyvsp[(3) - (5)].a), right_bracket, (yyvsp[(5) - (5)].a), NULL); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 312 "bison_c.y"
    { (yyval.a) = newAstNode(Statement, newNodeValue(0, "jump_statement"), linesno);
										  AstNode *return_keyword = newAstNode(Keyword, newNodeValue(0, "return"), linesno);
										  AstNode *semicolon = newAstNode(Operator, newNodeValue(0, ";"), linesno);
										  linkAstNode((yyval.a), return_keyword, semicolon, NULL); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 316 "bison_c.y"
    { (yyval.a) = newAstNode(Statement, newNodeValue(0, "jump_statement"), linesno);
										  AstNode *return_keyword = newAstNode(Keyword, newNodeValue(0, "return"), linesno);
										  AstNode *semicolon = newAstNode(Operator, newNodeValue(0, ";"), linesno);
										  linkAstNode((yyval.a), return_keyword, (yyvsp[(2) - (3)].a), semicolon, NULL); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 326 "bison_c.y"
    { ast_root = (yyvsp[(1) - (1)].a); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 331 "bison_c.y"
    { (yyval.a) = newAstNode(FunctionDefinition, newNodeValue(0, "function_definition"), (yyvsp[(1) - (5)].a)->linenumber);
								  AstNode *identifier = newAstNode(Identifier, newNodeValue(0, (yyvsp[(2) - (5)].s)), (yyvsp[(1) - (5)].a)->linenumber);
								  AstNode *left_bracket = newAstNode(Operator, newNodeValue(0, "("), (yyvsp[(1) - (5)].a)->linenumber);
								  AstNode *right_bracket = newAstNode(Operator, newNodeValue(0, ")"), (yyvsp[(1) - (5)].a)->linenumber);
								  linkAstNode((yyval.a), (yyvsp[(1) - (5)].a), identifier, left_bracket, right_bracket, (yyvsp[(5) - (5)].a), NULL); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 339 "bison_c.y"
    { (yyval.a) = newAstNode(FunctionDefinition, newNodeValue(0, "compound_statement"), linesno);
								  AstNode *big_left_bracket = newAstNode(Operator, newNodeValue(0, "{"), linesno);
								  AstNode *big_right_bracket = newAstNode(Operator, newNodeValue(0, "}"), linesno);
								  linkAstNode((yyval.a), big_left_bracket, big_right_bracket, NULL); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 343 "bison_c.y"
    { (yyval.a) = newAstNode(FunctionDefinition, newNodeValue(0, "compound_statement"), (yyvsp[(2) - (3)].a)->linenumber-1);
								  AstNode *big_left_bracket = newAstNode(Operator, newNodeValue(0, "{"), linesno);
								  AstNode *big_right_bracket = newAstNode(Operator, newNodeValue(0, "}"), linesno);
								  linkAstNode((yyval.a), big_left_bracket, (yyvsp[(2) - (3)].a), big_right_bracket, NULL); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 350 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 351 "bison_c.y"
    { (yyval.a) = newAstNode(FunctionDefinition, newNodeValue(0, "block_item_list"), (yyvsp[(1) - (2)].a)->linenumber);
									  linkAstNode((yyval.a), (yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a), NULL); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 356 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 357 "bison_c.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); }
    break;


/* Line 1792 of yacc.c  */
#line 2179 "bison_c.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 360 "bison_c.y"


void yyerror(char *s)
{
	fflush(stdout);
	fprintf(stderr, "Error: lines %d: %s\n", linesno, s);
}