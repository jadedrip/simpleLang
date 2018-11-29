
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "lex\\silang.yxx"

#include "../src/lex.h"

#define YYERROR_VERBOSE 1
#define YYDEBUG 1
#define YY_NO_UNISTD_H

extern "C" int yylex();
void yyerror( const char* error );



/* Line 189 of yacc.c  */
#line 86 "intermediate/silang.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AEQ = 258,
     ISOPT = 259,
     AND = 260,
     OR = 261,
     NOEQ = 262,
     EQ = 263,
     REQ = 264,
     LEQ = 265,
     ARRAY = 266,
     URIGHTMOVE = 267,
     RIGHTMOVE = 268,
     LEFTMOVE = 269,
     DEC = 270,
     INC = 271,
     BINARY = 272,
     EOL = 273,
     FEOF = 274,
     FUNC = 275,
     DOTS = 276,
     TYPE = 277,
     RGO = 278,
     WHEN_NULL = 279,
     ITYPE = 280,
     L_IDENTIFIER = 281,
     U_IDENTIFIER = 282,
     INTEGER = 283,
     FLOAT = 284,
     INT64 = 285,
     FLOAT64 = 286,
     BOOLEAN = 287,
     STRING_LITERAL = 288,
     CALL = 289,
     IF = 290,
     ELSE = 291,
     WHILE = 292,
     FOR = 293,
     RETURN = 294,
     CLASS = 295,
     INTERF = 296,
     PROTECTED = 297,
     PACKAGE = 298,
     IMPORT = 299,
     NULLPTR = 300,
     STATIC = 301,
     CONST = 302,
     ENUM = 303,
     SWITCH = 304,
     CASE = 305,
     DEFAULT = 306,
     SINGLETON = 307,
     TRY_TOKEN = 308,
     CATCH = 309,
     FINALLY = 310,
     GET_TOKEN = 311,
     SET_TOKEN = 312,
     OPERATOR = 313,
     NEW_TOKEN = 314,
     DELETE_TOKEN = 315,
     INIT_TOKEN = 316,
     FINALIZE_TOKEN = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 13 "lex\\silang.yxx"

	AstType		*tp;
	AstNode		*expr;
	char*		str;
	int			type;



/* Line 214 of yacc.c  */
#line 193 "intermediate/silang.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 205 "intermediate/silang.tab.cpp"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1562

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNRULES -- Number of states.  */
#define YYNSTATES  364

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,     2,     2,    87,    23,     2,
      26,    27,    21,    19,    85,    20,     4,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    42,
      11,     3,    12,    86,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,    25,     2,    46,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    24,    41,    28,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    13,    16,    17,    19,    22,
      23,    26,    31,    33,    37,    41,    45,    47,    50,    54,
      56,    59,    61,    63,    65,    67,    69,    71,    73,    75,
      77,    79,    81,    83,    85,    87,    89,    91,    93,    95,
      97,   102,   106,   108,   112,   115,   120,   122,   126,   132,
     134,   138,   140,   142,   146,   152,   155,   157,   159,   161,
     163,   165,   167,   169,   171,   173,   176,   179,   185,   188,
     190,   193,   197,   198,   204,   206,   208,   210,   213,   220,
     224,   232,   236,   238,   240,   244,   249,   251,   254,   256,
     260,   266,   270,   276,   280,   285,   287,   291,   296,   297,
     299,   303,   305,   307,   313,   316,   319,   323,   324,   326,
     330,   332,   340,   341,   344,   346,   348,   350,   354,   361,
     363,   366,   368,   370,   372,   374,   376,   378,   380,   382,
     384,   386,   388,   390,   392,   394,   396,   398,   400,   402,
     404,   406,   408,   410,   412,   414,   416,   418,   424,   428,
     430,   432,   434,   436,   438,   444,   446,   449,   454,   458,
     460,   464,   469,   470,   472,   475,   482,   484,   488,   489,
     492,   498,   508,   509,   511,   515,   519,   521,   523,   525,
     527,   529,   531,   533,   537,   541,   544,   547,   549,   551,
     553,   555,   558,   561,   565,   571,   575,   579,   581,   583,
     585,   587,   589,   596,   601,   604,   610,   616,   620
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,    92,    93,    99,    -1,    48,    -1,    91,
       4,    48,    -1,    65,    91,    -1,    -1,    94,    -1,    93,
      94,    -1,    -1,    66,    96,    -1,    66,    26,    97,    27,
      -1,    48,    -1,    95,     4,    48,    -1,    95,     4,    21,
      -1,    95,     4,    49,    -1,    96,    -1,    97,    96,    -1,
      40,    99,    41,    -1,   100,    -1,    99,   100,    -1,   123,
      -1,   109,    -1,   116,    -1,   126,    -1,   128,    -1,   161,
      -1,   162,    -1,   141,    -1,   159,    -1,   158,    -1,   146,
      -1,   133,    -1,   101,    -1,   106,    -1,   149,    -1,   153,
      -1,   132,    -1,   136,    -1,   131,    -1,    69,    48,     3,
     162,    -1,    48,     3,   162,    -1,   162,    -1,   103,    85,
     162,    -1,   122,    48,    -1,   122,    48,     3,   162,    -1,
     104,    -1,   105,    85,   104,    -1,    70,    49,    40,   107,
      41,    -1,   108,    -1,   107,    85,   108,    -1,   102,    -1,
      48,    -1,   110,    49,   115,    -1,   110,    49,    45,   122,
     115,    -1,   168,   109,    -1,    62,    -1,    74,    -1,   123,
      -1,   120,    -1,   121,    -1,   112,    -1,   113,    -1,   101,
      -1,   133,    -1,   119,    42,    -1,    64,    45,    -1,    83,
      26,   135,    27,    98,    -1,    84,    98,    -1,   111,    -1,
     114,   111,    -1,    40,   114,    41,    -1,    -1,    63,    48,
      40,   118,    41,    -1,   123,    -1,   119,    -1,   117,    -1,
     118,   117,    -1,    35,    48,    26,   135,    27,   137,    -1,
      78,    48,    98,    -1,    79,    48,    26,   122,    48,    27,
      98,    -1,    79,    48,    98,    -1,    49,    -1,    47,    -1,
     122,    43,    44,    -1,   122,    43,   162,    44,    -1,    35,
      -1,   122,    86,    -1,   104,    -1,   123,    85,    48,    -1,
     123,    85,    48,     3,   162,    -1,    43,   103,    44,    -1,
      26,   162,    85,   103,    27,    -1,   127,     5,   162,    -1,
      47,   127,     5,   162,    -1,    48,    -1,   127,    85,    48,
      -1,    48,    26,   129,    27,    -1,    -1,   130,    -1,   129,
      85,   130,    -1,   162,    -1,   102,    -1,   122,    48,    26,
     129,    27,    -1,    82,   162,    -1,   119,    98,    -1,   122,
      36,    48,    -1,    -1,   105,    -1,   105,    85,   134,    -1,
     134,    -1,    80,   144,    26,   135,    27,   137,    98,    -1,
      -1,    45,   139,    -1,   104,    -1,   122,    -1,   138,    -1,
     139,    85,   138,    -1,    35,    26,   105,    27,   137,    98,
      -1,    61,    -1,    61,   103,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    29,    -1,
      11,    -1,    12,    -1,    87,    -1,     4,    -1,    18,    -1,
      17,    -1,    16,    -1,    14,    -1,    13,    -1,    38,    -1,
      10,    -1,     5,    -1,     9,    -1,     8,    -1,     7,    -1,
      25,    -1,    28,    -1,   142,    -1,   143,    -1,    57,    26,
     147,    27,   148,    -1,   145,    58,   148,    -1,   145,    -1,
     162,    -1,   163,    -1,   100,    -1,    98,    -1,    71,   162,
      40,   150,    41,    -1,   151,    -1,   150,   151,    -1,    72,
     152,    45,    99,    -1,    73,    45,    99,    -1,   162,    -1,
     152,    85,   162,    -1,    75,    98,   154,   157,    -1,    -1,
     155,    -1,   154,   155,    -1,    76,    26,   156,    48,    27,
      98,    -1,   122,    -1,   156,    85,   122,    -1,    -1,    77,
      98,    -1,    59,    26,   162,    27,   148,    -1,    60,    26,
     160,    42,   162,    42,   162,    27,   148,    -1,    -1,   104,
      -1,    48,     3,   162,    -1,    48,     3,    98,    -1,   164,
      -1,   124,    -1,   140,    -1,   128,    -1,   125,    -1,    67,
      -1,    48,    -1,    26,   162,    27,    -1,   162,   142,   162,
      -1,   143,   162,    -1,   162,   143,    -1,   161,    -1,   165,
      -1,   166,    -1,   167,    -1,   162,    31,    -1,   162,    30,
      -1,   162,    39,   162,    -1,   162,    86,   162,    45,   162,
      -1,    49,     4,    48,    -1,   162,     6,    47,    -1,    50,
      -1,    51,    -1,    52,    -1,    53,    -1,    55,    -1,   162,
      43,   162,    45,   162,    44,    -1,   162,    43,   162,    44,
      -1,   162,    98,    -1,    88,    49,    26,   162,    27,    -1,
      88,    49,    26,   169,    27,    -1,    48,     3,   162,    -1,
     169,    85,    48,     3,   162,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    61,    62,    66,    67,    78,    79,    82,
      84,    85,    89,    90,    94,    95,    99,   100,   104,   108,
     109,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     135,   138,   142,   143,   148,   149,   153,   154,   160,   164,
     165,   170,   171,   178,   180,   182,   186,   187,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   204,   209,   214,
     215,   218,   219,   226,   230,   231,   235,   236,   240,   248,
     252,   253,   264,   265,   266,   267,   268,   269,   274,   275,
     276,   280,   288,   292,   293,   297,   298,   305,   309,   310,
     311,   315,   316,   324,   328,   336,   341,   346,   347,   348,
     349,   357,   362,   363,   367,   368,   372,   373,   377,   383,
     384,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   414,   415,   419,   420,   428,   432,   433,
     437,   438,   442,   443,   447,   453,   454,   458,   459,   463,
     464,   471,   475,   476,   477,   481,   485,   486,   490,   491,
     499,   502,   506,   508,   513,   514,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   544,   548,   549,   550,
     551,   552,   561,   569,   578,   584,   585,   589,   590
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'.'", "AEQ", "ISOPT", "AND",
  "OR", "NOEQ", "EQ", "'<'", "'>'", "REQ", "LEQ", "ARRAY", "URIGHTMOVE",
  "RIGHTMOVE", "LEFTMOVE", "'+'", "'-'", "'*'", "'/'", "'&'", "'|'", "'^'",
  "'('", "')'", "'~'", "'!'", "DEC", "INC", "BINARY", "EOL", "FEOF",
  "FUNC", "DOTS", "TYPE", "RGO", "WHEN_NULL", "'{'", "'}'", "';'", "'['",
  "']'", "':'", "'`'", "ITYPE", "L_IDENTIFIER", "U_IDENTIFIER", "INTEGER",
  "FLOAT", "INT64", "FLOAT64", "BOOLEAN", "STRING_LITERAL", "CALL", "IF",
  "ELSE", "WHILE", "FOR", "RETURN", "CLASS", "INTERF", "PROTECTED",
  "PACKAGE", "IMPORT", "NULLPTR", "STATIC", "CONST", "ENUM", "SWITCH",
  "CASE", "DEFAULT", "SINGLETON", "TRY_TOKEN", "CATCH", "FINALLY",
  "GET_TOKEN", "SET_TOKEN", "OPERATOR", "NEW_TOKEN", "DELETE_TOKEN",
  "INIT_TOKEN", "FINALIZE_TOKEN", "','", "'?'", "'%'", "'@'", "$accept",
  "package", "package_name", "package_name_line", "import", "import_line",
  "import_name_pre", "import_name", "import_names", "block", "lines",
  "line", "const", "equal", "exprs", "typeLet", "typeLets", "enum",
  "enum_list", "enum_assignment", "cls", "cls_type", "cls_line",
  "cls_construct", "cls_destory", "cls_lines", "cls_block", "interface",
  "interface_line", "interface_lines", "function_def", "get", "set",
  "def_type", "def", "sequence", "tuple", "tupleResolve",
  "tupleResolveDef", "call", "call_args", "call_arg", "class_new",
  "object_delete", "function", "function_variable", "function_parameters",
  "operator_overload", "function_ret", "return_tuple_elem",
  "return_tuple_elems", "lambda", "rtn", "operator_binary",
  "operator_unary", "operator", "if_cond", "if_else", "if_expr",
  "block_or_line", "switch", "cases", "case", "case_exprs", "try",
  "try_catchs", "try_catch", "try_types", "try_finally", "while_loop",
  "for_loop", "for_line", "assignment", "expr", "type_expr", "expr_value",
  "splice", "index", "object_block", "annotation", "annotation_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,    46,   258,   259,   260,   261,   262,
     263,    60,    62,   264,   265,   266,   267,   268,   269,    43,
      45,    42,    47,    38,   124,    94,    40,    41,   126,    33,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     123,   125,    59,    91,    93,    58,    96,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    44,    63,    37,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    99,
      99,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   102,   103,   103,   104,   104,   105,   105,   106,   107,
     107,   108,   108,   109,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   112,   113,   114,
     114,   115,   115,   116,   117,   117,   118,   118,   119,   120,
     121,   121,   122,   122,   122,   122,   122,   122,   123,   123,
     123,   124,   125,   126,   126,   127,   127,   128,   129,   129,
     129,   130,   130,   131,   132,   133,   134,   135,   135,   135,
     135,   136,   137,   137,   138,   138,   139,   139,   140,   141,
     141,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   143,   143,   144,   144,   145,   146,   146,
     147,   147,   148,   148,   149,   150,   150,   151,   151,   152,
     152,   153,   154,   154,   154,   155,   156,   156,   157,   157,
     158,   159,   160,   160,   161,   161,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   163,   164,   164,   164,
     164,   164,   165,   166,   167,   168,   168,   169,   169
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     3,     2,     0,     1,     2,     0,
       2,     4,     1,     3,     3,     3,     1,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     3,     2,     4,     1,     3,     5,     1,
       3,     1,     1,     3,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     5,     2,     1,
       2,     3,     0,     5,     1,     1,     1,     2,     6,     3,
       7,     3,     1,     1,     3,     4,     1,     2,     1,     3,
       5,     3,     5,     3,     4,     1,     3,     4,     0,     1,
       3,     1,     1,     5,     2,     2,     3,     0,     1,     3,
       1,     7,     0,     2,     1,     1,     1,     3,     6,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     1,
       1,     1,     1,     1,     5,     1,     2,     4,     3,     1,
       3,     4,     0,     1,     2,     6,     1,     3,     0,     2,
       5,     9,     0,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     2,     1,     1,     1,
       1,     2,     2,     3,     5,     3,     3,     1,     1,     1,
       1,     1,     6,     4,     2,     5,     5,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     9,     3,     5,     1,     0,     0,     7,
       0,     0,    12,     0,    10,   143,     0,   144,    86,     0,
      83,   182,    82,   197,   198,   199,   200,   201,     0,     0,
       0,   119,    56,     0,   181,     0,     0,     0,    57,     0,
       0,     0,     0,     8,     2,    19,    33,    88,    34,    22,
       0,    23,     0,     0,    21,   177,   180,    24,     0,    25,
      39,    37,    32,    38,   178,    28,     0,   149,    31,    35,
      36,    30,    29,    26,    27,   176,   188,   189,   190,     0,
       4,    16,     0,     0,     0,   182,     0,   179,   187,     0,
       0,     0,     0,    42,    95,     0,     0,    98,     0,     0,
       0,   172,   120,     0,     0,     0,     0,     0,   162,   131,
     139,   142,   141,   140,   138,   128,   129,   136,   135,   134,
     133,   132,   121,   122,   123,   124,   125,   126,   127,   137,
     130,   145,   146,     0,   104,     0,    20,    72,   105,     0,
      44,    87,     0,     0,     0,   185,     0,   192,   191,     0,
       0,     0,   204,     0,   186,    55,    11,    17,    14,    13,
      15,   183,     0,    86,    83,    82,    46,     0,     0,   107,
      91,     0,     0,   175,   174,   182,   102,     0,    99,   101,
     195,     0,   150,   151,     0,   173,     0,     0,     0,     0,
       0,     0,     0,   168,   163,   107,     0,     0,     0,    53,
      84,     0,     0,    98,    89,    93,    96,   153,   152,   148,
     193,     0,     0,   184,     0,   112,     0,    44,   108,     0,
     110,     0,    43,    94,     0,    97,     0,     0,     0,     0,
       0,    86,    76,     0,    75,    74,    40,    52,    51,     0,
      49,     0,     0,     0,   155,    18,     0,     0,   164,   161,
       0,   182,     0,     0,     0,     0,     0,     0,     0,    63,
      69,    61,    62,     0,     0,    59,    60,    58,    64,    72,
      85,    45,     0,     0,   203,     0,     0,    92,     0,     0,
      47,     0,     0,   112,    41,   100,   147,   196,   170,     0,
      73,    77,     0,    48,     0,     0,   159,     0,   154,   156,
     166,     0,   169,   112,     0,   205,   206,     0,    66,     0,
       0,   107,    68,    71,    70,    65,    54,   103,    90,     0,
     194,   114,   115,   116,   113,   118,   109,   106,    78,     0,
      41,    50,     0,     0,   158,     0,     0,     0,   174,     0,
      79,     0,    81,     0,   202,     0,     0,   157,   160,     0,
     167,   111,     0,     0,     0,   117,     0,   165,   208,     0,
      67,   171,     0,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     3,     8,     9,    13,    14,    82,   152,
     191,    45,    46,   176,    92,    47,   218,    48,   239,   240,
      49,    50,   260,   261,   262,   263,   199,    51,   232,   233,
      52,   265,   266,    53,    54,    55,    56,    57,    58,    87,
     177,   178,    60,    61,    62,   220,   221,    63,   279,   323,
     324,    64,    65,   153,    66,   133,    67,    68,   181,   209,
      69,   243,   244,   295,    70,   193,   194,   301,   249,    71,
      72,   186,    88,    74,   183,    75,    76,    77,    78,    79,
     253
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -258
static const yytype_int16 yypact[] =
{
     -31,    -3,    49,    64,  -258,   154,  -258,     4,  1229,  -258,
       5,   121,  -258,   167,  -258,  -258,  1433,  -258,    94,  1433,
     133,     7,   173,  -258,  -258,  -258,  -258,  -258,   174,   176,
     180,  1433,  -258,   151,  -258,   163,   159,  1433,  -258,   172,
      66,  1433,   164,  -258,  1382,  -258,  -258,  -258,  -258,  -258,
     168,  -258,   172,    73,   131,  -258,  -258,  -258,    11,  1107,
    -258,  -258,  -258,  -258,  -258,  -258,  1433,   156,  -258,  -258,
    -258,  -258,  -258,  1157,  1020,  -258,  -258,  -258,  -258,   -33,
    -258,  -258,    91,    10,   192,    25,   173,  -258,  -258,   544,
     129,   194,   -19,  1020,  -258,    18,   405,  1464,   178,  1433,
    1433,   129,   143,   189,   227,   195,  1070,  1382,   158,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,   206,  1020,   211,  -258,   165,  -258,   476,
      34,  -258,   191,  1433,   193,  1020,  1280,  -258,  -258,  1433,
    1433,  1433,  -258,  1433,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,  1433,  -258,  -258,  -258,  -258,   -16,    76,   129,
    -258,  1433,  1433,  -258,  1020,    37,  -258,   -13,  -258,  1020,
    -258,   213,   631,  -258,   668,  -258,   201,   149,  1433,   196,
    1178,  1331,   219,   111,  -258,   129,  1495,   326,   129,  -258,
    -258,   718,  1433,  1464,   243,  1020,  -258,  -258,  -258,  -258,
    1020,   581,   763,  1020,    23,   202,   129,   245,   166,   -21,
    -258,   223,  1020,  1020,   405,  -258,  1464,  1280,   207,  1280,
    1433,   204,  -258,   160,  -258,   131,  1020,   250,  -258,   -17,
    -258,  1433,   210,    95,  -258,  -258,   129,   172,  -258,  -258,
     231,   123,   805,    27,   214,   212,   215,   235,   172,  -258,
    -258,  -258,  -258,    96,   106,  -258,  -258,   131,  -258,   -22,
    -258,  1020,    29,  1433,  -258,  1433,  1433,  -258,   129,   172,
    -258,   129,   217,   202,  1020,  -258,  -258,  -258,  -258,   847,
    -258,  -258,  1433,  -258,   196,    72,  1020,  1382,  -258,  -258,
     -24,    81,  -258,   202,   405,  -258,  -258,   218,  -258,   172,
     107,   129,  -258,  -258,  -258,  -258,  -258,  -258,  1020,   892,
    1020,  -258,    76,  -258,   177,  -258,  -258,  -258,  -258,  1433,
    1020,  -258,  1382,  1433,  1382,   242,   129,   172,   933,   267,
    -258,   129,  -258,   244,  -258,   129,   983,  1382,  1020,   172,
     -24,  -258,  1433,    84,   172,  -258,  1280,  -258,  1020,   248,
    -258,  -258,   172,  -258
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -258,  -258,  -258,  -258,  -258,   264,  -258,    24,  -258,     9,
      -7,   -35,  -154,  -181,   -27,   -88,   188,  -258,  -258,   -15,
     203,  -258,    17,  -258,  -258,  -258,    14,  -258,    51,  -258,
    -140,  -258,  -258,   205,   -72,  -258,  -258,  -258,   265,    -8,
      83,    61,  -258,  -258,  -153,    13,  -189,  -258,  -257,   -54,
    -258,  -258,  -258,   256,   175,  -258,  -258,  -258,  -258,  -222,
    -258,  -258,    54,  -258,  -258,  -258,   105,  -258,  -258,  -258,
    -258,  -258,    -5,     1,  -258,  -258,  -258,  -258,  -258,  -258,
    -258
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -208
static const yytype_int16 yytable[] =
{
      59,    44,   166,    73,   102,   286,   250,   288,   238,   136,
      96,   215,   -95,   185,   225,   282,   143,    89,   197,   139,
      93,   139,   139,   172,   293,   170,   328,   217,    96,    32,
      11,   158,    93,    97,     1,    81,    59,   202,   106,    73,
     224,    38,   134,   259,   268,     4,   337,   234,   108,     6,
     277,    97,    12,    80,   306,    42,   317,   264,   159,   160,
     203,   138,   141,    97,   141,   141,   171,   145,   294,   216,
     109,   110,   226,   111,   112,   113,   114,   115,   116,   117,
     118,   166,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    15,   -95,   234,    17,   128,   144,   174,   179,    59,
     182,   184,    73,   144,   129,   173,   157,   166,   171,   259,
     268,   208,   307,   238,   226,   235,   139,   332,   156,   139,
      90,   140,   343,   264,   217,   267,   304,   139,   280,   335,
       7,   231,   359,   341,   361,   214,   298,   313,    59,    12,
     201,    73,    91,   164,   205,   165,   107,   107,   315,    97,
     210,   211,   212,   130,   213,   207,   136,   333,    10,   141,
     254,   235,   141,    93,   163,    35,   336,   241,   242,    12,
     141,    83,   222,   223,   255,   256,   164,    98,   165,   257,
     258,    94,    59,    59,   231,    73,    73,   192,   247,   236,
     321,   267,   208,   280,   208,   231,   164,   252,   165,   103,
      99,   290,   100,   271,   179,   197,   101,   164,   105,   165,
     198,   104,   107,   135,   146,   132,   142,   137,    90,    59,
     169,    59,    73,   166,    73,   284,   180,   179,   171,   187,
     188,   289,   195,   173,   192,   189,   207,   196,   207,   204,
     227,   206,   296,   230,   237,   246,   273,   278,   202,   154,
     283,   281,    91,   292,   287,   297,   302,   321,   303,   308,
     309,   311,   345,   310,   154,   327,   339,   312,   154,   349,
     352,   354,    43,   138,   318,   362,   319,   320,   167,   331,
     314,   154,   155,   316,   291,    95,   272,   285,   325,    59,
     334,   355,    73,   330,   326,   168,   131,   299,   248,   136,
       0,     0,     0,     0,     0,   338,   168,     0,     0,   154,
       0,     0,   136,   173,     0,     0,     0,     0,   340,   342,
     154,   208,     0,     0,    59,   347,    59,    73,     0,    73,
     346,     0,     0,     0,   348,     0,     0,     0,     0,    59,
       0,     0,    73,     0,     0,     0,   351,     0,    59,   154,
       0,    73,     0,   358,   154,     0,     0,   154,   357,   154,
       0,   231,     0,   360,     0,   207,     0,     0,     0,     0,
       0,   363,     0,   164,   219,   165,   154,     0,     0,     0,
     154,     0,     0,     0,     0,   154,   154,   154,   154,     0,
     254,     0,   168,     0,     0,    35,     0,   154,   154,     0,
     219,     0,   168,   269,   255,   256,     0,     0,     0,   257,
     258,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,   154,     0,     0,
      15,    16,     0,    17,     0,     0,     0,     0,   168,     0,
      84,     0,     0,     0,     0,   107,   154,     0,    19,     0,
       0,   300,     0,    85,    86,    23,    24,    25,    26,   154,
      27,     0,     0,     0,   154,     0,     0,     0,   168,     0,
       0,   154,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,   219,     0,     0,     0,
       0,     0,     0,   154,   154,   154,     0,     0,     0,     0,
       0,    15,    16,     0,    17,   154,     0,     0,     0,     0,
       0,    84,     0,   154,     0,     0,   219,     0,     0,    19,
     200,   154,     0,   154,    85,    86,    23,    24,    25,    26,
       0,    27,     0,   154,     0,     0,     0,     0,     0,     0,
       0,   350,     0,    34,     0,     0,   353,     0,   109,   110,
     322,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    15,
       0,   161,    17,   128,   147,   148,     0,     0,     0,     0,
       0,     0,   129,   149,   107,   109,   110,   150,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    15,     0,     0,    17,
     128,   147,   148,     0,     0,     0,     0,     0,     0,   129,
     149,   107,     0,     0,   150,   274,   275,     0,     0,   162,
     151,   130,     0,     0,     0,   109,   110,   228,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    15,     0,     0,    17,
     128,   147,   148,     0,     0,     0,     0,   151,   130,   129,
     149,   107,   109,   110,   150,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    15,     0,   229,    17,   128,   147,   148,
       0,     0,     0,     0,     0,     0,   129,   149,   107,     0,
       0,   150,     0,     0,     0,     0,     0,   151,   130,     0,
       0,     0,   109,   110,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    15,     0,     0,    17,   128,   147,   148,
       0,     0,     0,     0,   151,   130,   129,   149,   107,     0,
       0,   150,   270,     0,     0,     0,     0,   109,   110,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    15,     0,
       0,    17,   128,   147,   148,     0,     0,     0,     0,     0,
       0,   129,   149,   107,   151,   130,   150,     0,   276,   109,
     110,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      15,     0,   305,    17,   128,   147,   148,     0,     0,     0,
       0,     0,     0,   129,   149,   107,     0,     0,   150,   151,
     130,   109,   110,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    15,     0,     0,    17,   128,   147,   148,     0,
       0,     0,     0,     0,     0,   129,   149,   107,     0,   329,
     150,   151,   130,     0,     0,     0,   109,   110,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    15,     0,     0,
      17,   128,   147,   148,     0,     0,     0,     0,     0,     0,
     129,   149,   107,   151,   130,   150,   344,   109,   110,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    15,     0,
       0,    17,   128,   147,   148,     0,     0,     0,     0,     0,
       0,   129,   149,   107,     0,     0,   150,     0,   151,   130,
       0,     0,     0,     0,     0,     0,     0,   109,   110,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    15,     0,
     356,    17,   128,   147,   148,     0,     0,     0,  -207,   151,
     130,   129,   149,   107,   109,   110,   150,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    15,     0,     0,    17,   128,
     147,   148,     0,     0,     0,     0,     0,     0,   129,   149,
     107,     0,     0,   150,     0,     0,     0,     0,     0,   151,
     130,     0,     0,     0,   109,   110,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    15,     0,     0,    17,   128,
     147,   148,     0,     0,     0,     0,   151,   130,   129,   149,
     190,  -179,  -179,   150,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,     0,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,     0,     0,     0,     0,  -179,  -179,  -179,     0,
       0,     0,     0,     0,     0,  -179,  -179,  -179,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   130,     0,     0,
       0,  -187,  -187,     0,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,     0,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,     0,     0,     0,     0,  -187,  -187,  -187,     0,
       0,     0,     0,  -179,  -179,  -187,  -187,  -187,     0,     0,
       0,     0,     0,    15,    16,     0,    17,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,     0,    27,     0,    28,     0,    29,    30,    31,
      32,    33,     0,  -187,  -187,    34,     0,    35,    36,    37,
     241,   242,    38,    39,    15,    16,     0,    17,    40,     0,
      41,     0,     0,     0,    18,     0,    42,     0,     0,     0,
       0,     0,    19,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,     0,    27,     0,    28,     0,    29,    30,
      31,    32,    33,     0,     0,     7,    34,     0,    35,    36,
      37,     0,     0,    38,    39,    15,    16,     0,    17,    40,
       0,    41,     0,     0,     0,    18,     0,    42,     0,     0,
     107,     0,     0,    19,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,    27,     0,    28,     0,    29,
      30,    31,    32,    33,     0,     0,     0,    34,     0,    35,
      36,    37,     0,     0,    38,    39,    15,    16,     0,    17,
      40,     0,    41,     0,     0,     0,    18,     0,    42,     0,
       0,     0,   245,     0,    19,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,    27,     0,    28,     0,
      29,    30,    31,    32,    33,     0,     0,     0,    34,     0,
      35,    36,    37,     0,     0,    38,    39,    15,    16,     0,
      17,    40,     0,    41,     0,     0,     0,    18,     0,    42,
       0,     0,     0,     0,     0,    19,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,    27,     0,    28,
       0,    29,    30,    31,    32,    33,     0,     0,     0,    34,
       0,    35,    36,    37,     0,     0,    38,    39,    15,    16,
       0,    17,    40,     0,    41,     0,     0,     0,    84,     0,
      42,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,    85,    86,    23,    24,    25,    26,     0,    27,    15,
      16,     0,    17,     0,     0,     0,     0,     0,     0,    84,
      34,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,   175,    86,    23,    24,    25,    26,     0,    27,
      15,    16,     0,    17,     0,     0,     0,     0,     0,     0,
      84,    34,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,   251,    86,    23,    24,    25,    26,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34
};

static const yytype_int16 yycheck[] =
{
       8,     8,    90,     8,    31,   227,   195,   229,   189,    44,
       3,    27,     5,   101,    27,    36,     5,    16,    40,    43,
      19,    43,    43,     5,    41,    44,   283,    48,     3,    62,
      26,    21,    31,    26,    65,    11,    44,     3,    37,    44,
       3,    74,    41,   197,   197,    48,   303,   187,    39,     0,
      27,    26,    48,    48,    27,    88,    27,   197,    48,    49,
      26,    52,    86,    26,    86,    86,    85,    66,    85,    85,
       4,     5,    85,     7,     8,     9,    10,    11,    12,    13,
      14,   169,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    85,   233,    28,    29,    85,    96,    97,   107,
      99,   100,   107,    85,    38,    96,    82,   195,    85,   263,
     263,   146,    85,   294,    85,   187,    43,    45,    27,    43,
      26,    48,   311,   263,    48,   197,     3,    43,   216,    48,
      66,    35,    48,    26,   356,   162,    41,    41,   146,    48,
     139,   146,    48,    47,   143,    49,    40,    40,    42,    26,
     149,   150,   151,    87,   153,   146,   191,    85,     4,    86,
      64,   233,    86,   162,    35,    69,    85,    72,    73,    48,
      86,     4,   171,   172,    78,    79,    47,     4,    49,    83,
      84,    48,   190,   191,    35,   190,   191,    76,    77,   188,
     278,   263,   227,   281,   229,    35,    47,   196,    49,    48,
      26,    41,    26,   202,   203,    40,    26,    47,    49,    49,
      45,    48,    40,    49,    58,    40,    85,    49,    26,   227,
      26,   229,   227,   311,   229,   224,    48,   226,    85,    40,
       3,   230,    26,   224,    76,    40,   227,    26,   229,    48,
      27,    48,   241,    42,    48,    26,     3,    45,     3,    74,
      27,    85,    48,     3,    47,    45,   247,   345,    27,    45,
      48,    26,    85,    48,    89,    48,    48,   258,    93,    27,
       3,    27,     8,   264,   273,    27,   275,   276,    90,   294,
     263,   106,    79,   269,   233,    20,   203,   226,   279,   297,
     297,   345,   297,   292,   281,    90,    40,   243,   193,   334,
      -1,    -1,    -1,    -1,    -1,   304,   101,    -1,    -1,   134,
      -1,    -1,   347,   304,    -1,    -1,    -1,    -1,   309,   310,
     145,   356,    -1,    -1,   332,   332,   334,   332,    -1,   334,
     329,    -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,   347,
      -1,    -1,   347,    -1,    -1,    -1,   337,    -1,   356,   174,
      -1,   356,    -1,   352,   179,    -1,    -1,   182,   349,   184,
      -1,    35,    -1,   354,    -1,   356,    -1,    -1,    -1,    -1,
      -1,   362,    -1,    47,   169,    49,   201,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,   210,   211,   212,   213,    -1,
      64,    -1,   187,    -1,    -1,    69,    -1,   222,   223,    -1,
     195,    -1,   197,   198,    78,    79,    -1,    -1,    -1,    83,
      84,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,   233,    -1,
      35,    -1,    -1,    -1,    -1,    40,   271,    -1,    43,    -1,
      -1,   246,    -1,    48,    49,    50,    51,    52,    53,   284,
      55,    -1,    -1,    -1,   289,    -1,    -1,    -1,   263,    -1,
      -1,   296,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   278,    -1,    -1,   281,    -1,    -1,    -1,
      -1,    -1,    -1,   318,   319,   320,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,   330,    -1,    -1,    -1,    -1,
      -1,    35,    -1,   338,    -1,    -1,   311,    -1,    -1,    43,
      44,   346,    -1,   348,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,   358,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   336,    -1,    67,    -1,    -1,   341,    -1,     4,     5,
     345,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,     4,     5,    43,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    43,    44,    45,    -1,    -1,    85,
      86,    87,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    86,    87,    38,
      39,    40,     4,     5,    43,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    86,    87,    38,    39,    40,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    86,    87,    43,    -1,    45,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    43,    86,
      87,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
      43,    86,    87,    -1,    -1,    -1,     4,     5,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    86,    87,    43,    44,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    43,    -1,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    85,    86,
      87,    38,    39,    40,     4,     5,    43,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    86,    87,    38,    39,
      40,     4,     5,    43,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    86,    87,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    57,    -1,    59,    60,    61,
      62,    63,    -1,    86,    87,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    25,    26,    -1,    28,    80,    -1,
      82,    -1,    -1,    -1,    35,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      71,    -1,    -1,    74,    75,    25,    26,    -1,    28,    80,
      -1,    82,    -1,    -1,    -1,    35,    -1,    88,    -1,    -1,
      40,    -1,    -1,    43,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    -1,    57,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    -1,    69,
      70,    71,    -1,    -1,    74,    75,    25,    26,    -1,    28,
      80,    -1,    82,    -1,    -1,    -1,    35,    -1,    88,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,    74,    75,    25,    26,    -1,
      28,    80,    -1,    82,    -1,    -1,    -1,    35,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    57,
      -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    74,    75,    25,    26,
      -1,    28,    80,    -1,    82,    -1,    -1,    -1,    35,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    -1,    55,    25,
      26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    -1,    55,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    67,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    90,    92,    48,    91,     0,    66,    93,    94,
       4,    26,    48,    95,    96,    25,    26,    28,    35,    43,
      47,    48,    49,    50,    51,    52,    53,    55,    57,    59,
      60,    61,    62,    63,    67,    69,    70,    71,    74,    75,
      80,    82,    88,    94,    99,   100,   101,   104,   106,   109,
     110,   116,   119,   122,   123,   124,   125,   126,   127,   128,
     131,   132,   133,   136,   140,   141,   143,   145,   146,   149,
     153,   158,   159,   161,   162,   164,   165,   166,   167,   168,
      48,    96,    97,     4,    35,    48,    49,   128,   161,   162,
      26,    48,   103,   162,    48,   127,     3,    26,     4,    26,
      26,    26,   103,    48,    48,    49,   162,    40,    98,     4,
       5,     7,     8,     9,    10,    11,    12,    13,    14,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    29,    38,
      87,   142,   143,   144,   162,    49,   100,    49,    98,    43,
      48,    86,    85,     5,    85,   162,    58,    30,    31,    39,
      43,    86,    98,   142,   143,   109,    27,    96,    21,    48,
      49,    27,    85,    35,    47,    49,   104,   105,   122,    26,
      44,    85,     5,    98,   162,    48,   102,   129,   130,   162,
      48,   147,   162,   163,   162,   104,   160,    40,     3,    40,
      40,    99,    76,   154,   155,    26,    26,    40,    45,   115,
      44,   162,     3,    26,    48,   162,    48,    98,   100,   148,
     162,   162,   162,   162,   103,    27,    85,    48,   105,   122,
     134,   135,   162,   162,     3,    27,    85,    27,     6,    27,
      42,    35,   117,   118,   119,   123,   162,    48,   102,   107,
     108,    72,    73,   150,   151,    41,    26,    77,   155,   157,
     135,    48,   162,   169,    64,    78,    79,    83,    84,   101,
     111,   112,   113,   114,   119,   120,   121,   123,   133,   122,
      44,   162,   129,     3,    44,    45,    45,    27,    45,   137,
     104,    85,    36,    27,   162,   130,   148,    47,   148,   162,
      41,   117,     3,    41,    85,   152,   162,    45,    41,   151,
     122,   156,    98,    27,     3,    27,    27,    85,    45,    48,
      48,    26,    98,    41,   111,    42,   115,    27,   162,   162,
     162,   104,   122,   138,   139,    98,   134,    48,   137,    42,
     162,   108,    45,    85,    99,    48,    85,   137,   162,    48,
      98,    26,    98,   135,    44,    85,   162,    99,   162,    27,
     122,    98,     3,   122,    27,   138,    27,    98,   162,    48,
      98,   148,    27,    98
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 57 "lex\\silang.yxx"
    { setPackageLines((yyvsp[(3) - (3)].expr)); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 61 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 62 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 66 "lex\\silang.yxx"
    { (yyval.expr)=packageName((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 67 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 84 "lex\\silang.yxx"
    { packageImport( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 85 "lex\\silang.yxx"
    { packageImport( (yyvsp[(3) - (4)].expr) ); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 89 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 90 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 94 "lex\\silang.yxx"
    { (yyval.expr)=importName((yyvsp[(1) - (3)].expr), "*"); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 95 "lex\\silang.yxx"
    { (yyval.expr)=importName((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 100 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 104 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 109 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 135 "lex\\silang.yxx"
    { (yyval.expr)=makeConst((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].expr)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 138 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 143 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 148 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (2)].tp), (yyvsp[(2) - (2)].str)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 149 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (4)].tp), (yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 154 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 160 "lex\\silang.yxx"
    { (yyval.expr)=createEnum((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 165 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 171 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str),nullptr); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 179 "lex\\silang.yxx"
    { (yyval.expr)=makeClass((yyvsp[(1) - (3)].type),(yyvsp[(2) - (3)].str), nullptr, (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 181 "lex\\silang.yxx"
    { (yyval.expr)=makeClass((yyvsp[(1) - (5)].type),(yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].tp), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 182 "lex\\silang.yxx"
    { (yyval.expr)=annotationdClass((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 186 "lex\\silang.yxx"
    { (yyval.type)=0; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 187 "lex\\silang.yxx"
    { (yyval.type)=1; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 199 "lex\\silang.yxx"
    { (yyval.expr)=setProtected(); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 205 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(2, ":init", (yyvsp[(3) - (5)].expr), nullptr, (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 210 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(3, ":finalize", nullptr, nullptr, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 215 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 218 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 226 "lex\\silang.yxx"
    { (yyval.tp)=createInterface((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 236 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 241 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(0, (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].expr), (yyvsp[(6) - (6)].expr), nullptr); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 248 "lex\\silang.yxx"
    { (yyval.expr)=makeGet((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 252 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].tp), (yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 253 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (3)].str), nullptr, nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 264 "lex\\silang.yxx"
    { (yyval.tp)=getClassType((yyvsp[(1) - (1)].str)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 265 "lex\\silang.yxx"
    { (yyval.tp)=getType((yyvsp[(1) - (1)].type)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 266 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (3)].tp)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 267 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (4)].tp),(yyvsp[(3) - (4)].expr)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 268 "lex\\silang.yxx"
    { (yyval.tp)=getFuncType(); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 269 "lex\\silang.yxx"
    { (yyval.tp)=nullAble((yyvsp[(1) - (2)].tp)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 274 "lex\\silang.yxx"
    { (yyval.expr)=createDef((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 275 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 276 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 280 "lex\\silang.yxx"
    { (yyval.expr)=makeSequence( (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 288 "lex\\silang.yxx"
    { (yyval.expr)=makeTuple((yyvsp[(4) - (5)].expr), (yyvsp[(2) - (5)].expr)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 292 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 293 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr), true); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 297 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 298 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 305 "lex\\silang.yxx"
    { (yyval.expr)=makeCall((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 309 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 311 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 324 "lex\\silang.yxx"
    { (yyval.expr)=createNew((yyvsp[(1) - (5)].tp), (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 328 "lex\\silang.yxx"
    { (yyval.expr)=makeDelete((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 336 "lex\\silang.yxx"
    { (yyval.expr)=addFunctionBlock((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 341 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].str), nullptr, 1); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 346 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 348 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 358 "lex\\silang.yxx"
    { (yyval.expr)=createOperator((yyvsp[(2) - (7)].type), (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 362 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 363 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 368 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 373 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 378 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(6, "", (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 383 "lex\\silang.yxx"
    { (yyval.expr)=callReturn(); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 384 "lex\\silang.yxx"
    { (yyval.expr)=callReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 389 "lex\\silang.yxx"
    { (yyval.type)='+'; ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 390 "lex\\silang.yxx"
    { (yyval.type)='-'; ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 391 "lex\\silang.yxx"
    { (yyval.type)='*'; ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 392 "lex\\silang.yxx"
    { (yyval.type)='/'; ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 393 "lex\\silang.yxx"
    { (yyval.type)='&'; ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 394 "lex\\silang.yxx"
    { (yyval.type)='|'; ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 395 "lex\\silang.yxx"
    { (yyval.type)='!'; ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 396 "lex\\silang.yxx"
    { (yyval.type)='<'; ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 397 "lex\\silang.yxx"
    { (yyval.type)='>'; ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 398 "lex\\silang.yxx"
    { (yyval.type)='%'; ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 399 "lex\\silang.yxx"
    { (yyval.type)='.'; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 400 "lex\\silang.yxx"
    { (yyval.type)=LEFTMOVE; ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 401 "lex\\silang.yxx"
    { (yyval.type)=RIGHTMOVE; ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 402 "lex\\silang.yxx"
    { (yyval.type)=URIGHTMOVE; ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 403 "lex\\silang.yxx"
    { (yyval.type)=LEQ; ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 404 "lex\\silang.yxx"
    { (yyval.type)=REQ; ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 405 "lex\\silang.yxx"
    { (yyval.type)=RGO; ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 406 "lex\\silang.yxx"
    { (yyval.type)=EQ; ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 407 "lex\\silang.yxx"
    { (yyval.type)=AEQ; ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 408 "lex\\silang.yxx"
    { (yyval.type)=NOEQ; ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 409 "lex\\silang.yxx"
    { (yyval.type)=OR; ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 410 "lex\\silang.yxx"
    { (yyval.type)=AND; ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 414 "lex\\silang.yxx"
    { (yyval.type)='^'; ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 415 "lex\\silang.yxx"
    { (yyval.type)='~'; ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 428 "lex\\silang.yxx"
    { (yyval.expr)=makeIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 432 "lex\\silang.yxx"
    { (yyval.expr)=setElse((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 449 "lex\\silang.yxx"
    { (yyval.expr)=createSwitch((yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 454 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 458 "lex\\silang.yxx"
    { (yyval.expr)=createCase((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 459 "lex\\silang.yxx"
    { (yyval.expr)=createCase(nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 464 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 471 "lex\\silang.yxx"
    { (yyval.expr)=createTry( (yyvsp[(2) - (4)].expr), (yyvsp[(3) - (4)].expr), (yyvsp[(4) - (4)].expr) ); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 475 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 477 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 481 "lex\\silang.yxx"
    { (yyval.expr)=makeCatch((yyvsp[(3) - (6)].expr), (yyvsp[(4) - (6)].str), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 485 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 486 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),let((yyvsp[(3) - (3)].tp))); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 490 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 491 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 499 "lex\\silang.yxx"
    { (yyval.expr)=makeWhile((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 503 "lex\\silang.yxx"
    { (yyval.expr)=makeFor( (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].expr)); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 513 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 514 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 526 "lex\\silang.yxx"
    { (yyval.expr)=makeNull(); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 527 "lex\\silang.yxx"
    { (yyval.expr)=getVar((yyvsp[(1) - (1)].str)); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 528 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 529 "lex\\silang.yxx"
    { (yyval.expr)=binary((yyvsp[(2) - (3)].type), (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 530 "lex\\silang.yxx"
    { (yyval.expr)=unary((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 531 "lex\\silang.yxx"
    { (yyval.expr)=unaryAfter((yyvsp[(2) - (2)].type), (yyvsp[(1) - (2)].expr)); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 536 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 537 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr), false); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 538 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF(makeIsNull((yyvsp[(1) - (3)].expr)), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 539 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 540 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 544 "lex\\silang.yxx"
    { (yyval.expr)=binaryIs((yyvsp[(1) - (3)].expr), getType((yyvsp[(3) - (3)].type)));  ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 561 "lex\\silang.yxx"
    { (yyval.expr)=makeSplice((yyvsp[(1) - (6)].expr), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr)); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 569 "lex\\silang.yxx"
    { (yyval.expr)=makeIndex((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 578 "lex\\silang.yxx"
    { (yyval.expr)=makeBased((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 584 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 585 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 589 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 590 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (5)].expr), let((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].expr))); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2931 "intermediate/silang.tab.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 593 "lex\\silang.yxx"


