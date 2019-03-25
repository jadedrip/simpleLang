
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
     STRING_LITERAL = 266,
     ARRAY = 267,
     URIGHTMOVE = 268,
     RIGHTMOVE = 269,
     LEFTMOVE = 270,
     DEC = 271,
     INC = 272,
     BINARY = 273,
     EOL = 274,
     FEOF = 275,
     FUNC = 276,
     DOTS = 277,
     TYPE = 278,
     RGO = 279,
     WHEN_NULL = 280,
     ITYPE = 281,
     L_IDENTIFIER = 282,
     U_IDENTIFIER = 283,
     INTEGER = 284,
     FLOAT = 285,
     INT64 = 286,
     FLOAT64 = 287,
     BOOLEAN = 288,
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
     FINALIZE_TOKEN = 317,
     GO_TOKEN = 318,
     BBRACKETS = 319
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
#line 195 "intermediate/silang.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 207 "intermediate/silang.tab.cpp"

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
#define YYLAST   2040

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  251
/* YYNRULES -- Number of states.  */
#define YYNSTATES  449

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,    89,    24,     2,
      27,    28,    22,    20,    87,    21,     4,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    43,
      11,     3,    12,    88,    90,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,    26,     2,    47,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    25,    42,    29,     2,     2,     2,
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
      19,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    13,    16,    17,    18,    20,
      23,    26,    31,    33,    37,    41,    45,    49,    51,    54,
      57,    61,    63,    66,    68,    70,    72,    74,    76,    78,
      80,    82,    84,    86,    88,    90,    92,    94,    96,    98,
     100,   102,   104,   109,   113,   115,   119,   122,   127,   129,
     133,   139,   141,   145,   149,   151,   152,   155,   156,   160,
     162,   166,   172,   175,   177,   179,   181,   183,   185,   187,
     189,   191,   193,   196,   198,   204,   205,   208,   212,   217,
     219,   222,   224,   227,   231,   232,   238,   240,   242,   244,
     247,   254,   258,   266,   270,   272,   277,   279,   283,   288,
     290,   293,   295,   299,   301,   305,   311,   316,   323,   327,
     333,   337,   341,   345,   350,   351,   353,   357,   359,   361,
     367,   370,   373,   374,   376,   380,   381,   383,   387,   389,
     397,   406,   407,   410,   412,   414,   416,   420,   427,   431,
     434,   436,   439,   441,   443,   445,   447,   449,   451,   453,
     455,   457,   459,   461,   463,   465,   467,   469,   471,   473,
     475,   477,   479,   481,   483,   485,   491,   495,   497,   499,
     501,   503,   505,   511,   513,   516,   521,   525,   527,   531,
     536,   537,   539,   542,   549,   551,   555,   556,   559,   565,
     575,   576,   578,   582,   586,   590,   592,   594,   596,   598,
     600,   602,   604,   606,   610,   613,   616,   618,   620,   622,
     624,   627,   630,   634,   640,   644,   648,   653,   657,   661,
     665,   669,   673,   677,   681,   685,   689,   693,   697,   701,
     705,   709,   713,   717,   721,   725,   729,   733,   737,   739,
     742,   744,   746,   748,   750,   752,   759,   764,   767,   773,
     779,   783
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      92,     0,    -1,    94,    95,   101,    -1,    49,    -1,    93,
       4,    49,    -1,    65,    93,    -1,    -1,    -1,    96,    -1,
      95,    96,    -1,    66,    98,    -1,    66,    27,    99,    28,
      -1,    49,    -1,    97,     4,    49,    -1,    97,     4,    22,
      -1,    97,     4,    50,    -1,    97,     4,    49,    -1,    98,
      -1,    99,    98,    -1,    41,    42,    -1,    41,   101,    42,
      -1,   102,    -1,   101,   102,    -1,   131,    -1,   114,    -1,
     123,    -1,   134,    -1,   136,    -1,   171,    -1,   172,    -1,
     151,    -1,   169,    -1,   168,    -1,   156,    -1,   141,    -1,
     103,    -1,   108,    -1,   159,    -1,   163,    -1,   140,    -1,
     145,    -1,   139,    -1,    69,    49,     3,   172,    -1,    49,
       3,   172,    -1,   172,    -1,   105,    87,   172,    -1,   129,
      49,    -1,   129,    49,     3,   172,    -1,   106,    -1,   107,
      87,   106,    -1,    70,    50,    41,   109,    42,    -1,   110,
      -1,   109,    87,   110,    -1,    50,     3,   172,    -1,    50,
      -1,    -1,    46,   129,    -1,    -1,    11,   113,    12,    -1,
      50,    -1,   113,    87,    50,    -1,   115,    50,   112,   111,
     122,    -1,   179,   114,    -1,    62,    -1,    74,    -1,   131,
      -1,   127,    -1,   128,    -1,   117,    -1,   120,    -1,   103,
      -1,   141,    -1,    64,    46,    -1,   145,    -1,    83,    27,
     144,    28,   118,    -1,    -1,    41,    42,    -1,    41,   119,
      42,    -1,    83,    27,   137,    28,    -1,   101,    -1,    84,
     142,    -1,   116,    -1,   121,   116,    -1,    41,   121,    42,
      -1,    -1,    63,    49,    41,   125,    42,    -1,   131,    -1,
     126,    -1,   124,    -1,   125,   124,    -1,    36,    49,    27,
     144,    28,   146,    -1,    78,    49,   100,    -1,    79,    49,
      27,   129,    49,    28,   100,    -1,    79,    49,   100,    -1,
      50,    -1,    50,    11,   130,    12,    -1,    48,    -1,   129,
      44,    45,    -1,   129,    44,   172,    45,    -1,    36,    -1,
     129,    88,    -1,   129,    -1,   130,    87,   129,    -1,   106,
      -1,   131,    87,    49,    -1,   131,    87,    49,     3,   172,
      -1,   129,    49,     5,   172,    -1,   129,    27,   135,    28,
       5,   172,    -1,    44,   105,    45,    -1,    27,   172,    87,
     105,    28,    -1,   135,     5,   172,    -1,    49,    87,    49,
      -1,   135,    87,    49,    -1,    49,    27,   137,    28,    -1,
      -1,   138,    -1,   137,    87,   138,    -1,   172,    -1,   104,
      -1,   129,    49,    27,   137,    28,    -1,    82,   172,    -1,
     126,   142,    -1,    -1,   100,    -1,   129,    37,    49,    -1,
      -1,   107,    -1,   107,    87,   143,    -1,   143,    -1,    80,
     154,    27,   144,    28,   146,   142,    -1,    80,    27,    28,
      27,   144,    28,   146,   142,    -1,    -1,    46,   148,    -1,
     106,    -1,   129,    -1,   147,    -1,   148,    87,   147,    -1,
      36,    27,   144,    28,   146,   100,    -1,    85,   146,   100,
      -1,    85,   172,    -1,    61,    -1,    61,   105,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    30,    -1,    11,    -1,    12,    -1,    89,    -1,     4,
      -1,    19,    -1,    18,    -1,    17,    -1,    14,    -1,    13,
      -1,    39,    -1,     8,    -1,     7,    -1,    26,    -1,    29,
      -1,   152,    -1,   153,    -1,    57,    27,   157,    28,   158,
      -1,   155,    58,   158,    -1,   155,    -1,   172,    -1,   173,
      -1,   102,    -1,   100,    -1,    71,   172,    41,   160,    42,
      -1,   161,    -1,   160,   161,    -1,    72,   162,    46,   101,
      -1,    73,    46,   101,    -1,   172,    -1,   162,    87,   172,
      -1,    75,   100,   164,   167,    -1,    -1,   165,    -1,   164,
     165,    -1,    76,    27,   166,    49,    28,   100,    -1,   129,
      -1,   166,    87,   129,    -1,    -1,    77,   100,    -1,    59,
      27,   172,    28,   158,    -1,    60,    27,   170,    43,   172,
      43,   172,    28,   158,    -1,    -1,   106,    -1,    49,     3,
     172,    -1,    49,     3,   100,    -1,    49,     5,   172,    -1,
     175,    -1,   132,    -1,   149,    -1,   136,    -1,   133,    -1,
     150,    -1,    67,    -1,    49,    -1,    27,   172,    28,    -1,
     153,   172,    -1,   172,   153,    -1,   171,    -1,   176,    -1,
     177,    -1,   178,    -1,   172,    32,    -1,   172,    31,    -1,
     172,    40,   172,    -1,   172,    88,   172,    46,   172,    -1,
      50,     4,    49,    -1,    50,     4,    50,    -1,   129,    27,
     137,    28,    -1,   172,    20,   172,    -1,   172,    21,   172,
      -1,   172,    22,   172,    -1,   172,    23,   172,    -1,   172,
      24,   172,    -1,   172,    25,   172,    -1,   172,    11,   172,
      -1,   172,    12,   172,    -1,   172,    89,   172,    -1,   172,
       4,   172,    -1,   172,    19,   172,    -1,   172,    18,   172,
      -1,   172,    17,   172,    -1,   172,    14,   172,    -1,   172,
      13,   172,    -1,   172,    39,   172,    -1,   172,    10,   172,
      -1,   172,     5,   172,    -1,   172,     8,   172,    -1,   172,
       7,   172,    -1,   172,     6,    48,    -1,    15,    -1,   174,
      15,    -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,
     174,    -1,   172,    44,   172,    46,   172,    45,    -1,   172,
      44,   172,    45,    -1,   172,   100,    -1,    90,    50,    27,
     172,    28,    -1,    90,    50,    27,   180,    28,    -1,    49,
       3,   172,    -1,   180,    87,    49,     3,   172,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    61,    62,    66,    67,    77,    79,    80,
      84,    85,    89,    90,    94,    95,    96,   100,   101,   105,
     106,   110,   111,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   137,   140,   144,   145,   150,   151,   155,   156,
     162,   166,   167,   171,   172,   179,   180,   184,   185,   189,
     190,   194,   196,   200,   201,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   218,   223,   224,   225,   229,   230,
     234,   239,   240,   243,   244,   251,   255,   256,   260,   261,
     265,   273,   277,   278,   289,   290,   291,   292,   293,   294,
     295,   299,   300,   304,   305,   306,   307,   308,   313,   321,
     325,   329,   330,   337,   341,   342,   343,   347,   348,   356,
     360,   368,   372,   373,   378,   383,   384,   385,   386,   394,
     396,   401,   402,   406,   407,   411,   412,   416,   421,   423,
     428,   429,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   456,   457,   461,   462,   470,   474,   475,   479,   480,
     484,   485,   489,   495,   496,   500,   501,   505,   506,   513,
     517,   518,   519,   523,   527,   528,   532,   533,   541,   544,
     548,   550,   555,   556,   557,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   609,   613,   614,
     618,   619,   620,   621,   622,   631,   639,   648,   654,   655,
     659,   660
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'.'", "AEQ", "ISOPT", "AND",
  "OR", "NOEQ", "EQ", "'<'", "'>'", "REQ", "LEQ", "STRING_LITERAL",
  "ARRAY", "URIGHTMOVE", "RIGHTMOVE", "LEFTMOVE", "'+'", "'-'", "'*'",
  "'/'", "'&'", "'|'", "'^'", "'('", "')'", "'~'", "'!'", "DEC", "INC",
  "BINARY", "EOL", "FEOF", "FUNC", "DOTS", "TYPE", "RGO", "WHEN_NULL",
  "'{'", "'}'", "';'", "'['", "']'", "':'", "'`'", "ITYPE", "L_IDENTIFIER",
  "U_IDENTIFIER", "INTEGER", "FLOAT", "INT64", "FLOAT64", "BOOLEAN",
  "CALL", "IF", "ELSE", "WHILE", "FOR", "RETURN", "CLASS", "INTERF",
  "PROTECTED", "PACKAGE", "IMPORT", "NULLPTR", "STATIC", "CONST", "ENUM",
  "SWITCH", "CASE", "DEFAULT", "SINGLETON", "TRY_TOKEN", "CATCH",
  "FINALLY", "GET_TOKEN", "SET_TOKEN", "OPERATOR", "NEW_TOKEN",
  "DELETE_TOKEN", "INIT_TOKEN", "FINALIZE_TOKEN", "GO_TOKEN", "BBRACKETS",
  "','", "'?'", "'%'", "'@'", "$accept", "package", "package_name",
  "package_name_line", "import", "import_line", "import_name_pre",
  "import_name", "import_names", "block", "lines", "line", "const",
  "equal", "exprs", "typeLet", "typeLets", "enum", "enum_list",
  "enum_assignment", "cls_inherit", "cls_template_list", "types", "cls",
  "cls_type", "cls_line", "cls_construct", "construct_block_or_none",
  "construct_block_lines", "cls_destory", "cls_lines", "cls_block",
  "interface", "interface_line", "interface_lines", "function_def", "get",
  "set", "def_type", "def_types", "def", "sequence", "tuple",
  "tupleResolve", "tupleResolveParams", "call", "call_args", "call_arg",
  "class_new", "object_delete", "function", "block_or_none",
  "function_variable", "function_parameters", "operator_overload",
  "function_ret", "return_tuple_elem", "return_tuple_elems", "lambda",
  "go", "rtn", "operator_binary", "operator_unary", "operator", "if_cond",
  "if_else", "if_expr", "block_or_line", "switch", "cases", "case",
  "case_exprs", "try", "try_catchs", "try_catch", "try_types",
  "try_finally", "while_loop", "for_loop", "for_line", "assignment",
  "expr", "type_expr", "string_lite", "expr_value", "splice", "index",
  "object_block", "annotation", "annotation_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,    46,   258,   259,   260,   261,   262,
     263,    60,    62,   264,   265,   266,   267,   268,   269,   270,
      43,    45,    42,    47,    38,   124,    94,    40,    41,   126,
      33,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   123,   125,    59,    91,    93,    58,    96,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,    44,    63,    37,
      64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    93,    94,    94,    95,    95,    95,
      96,    96,    97,    97,    98,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   104,   105,   105,   106,   106,   107,   107,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   117,   118,   118,   118,   119,   119,
     120,   121,   121,   122,   122,   123,   124,   124,   125,   125,
     126,   127,   128,   128,   129,   129,   129,   129,   129,   129,
     129,   130,   130,   131,   131,   131,   131,   131,   132,   133,
     134,   135,   135,   136,   137,   137,   137,   138,   138,   139,
     140,   141,   142,   142,   143,   144,   144,   144,   144,   145,
     145,   146,   146,   147,   147,   148,   148,   149,   150,   150,
     151,   151,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   153,   153,   154,   154,   155,   156,   156,   157,   157,
     158,   158,   159,   160,   160,   161,   161,   162,   162,   163,
     164,   164,   164,   165,   166,   166,   167,   167,   168,   169,
     170,   170,   171,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   173,   174,   174,
     175,   175,   175,   175,   175,   176,   177,   178,   179,   179,
     180,   180
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     3,     2,     0,     0,     1,     2,
       2,     4,     1,     3,     3,     3,     3,     1,     2,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     3,     2,     4,     1,     3,
       5,     1,     3,     3,     1,     0,     2,     0,     3,     1,
       3,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     5,     0,     2,     3,     4,     1,
       2,     1,     2,     3,     0,     5,     1,     1,     1,     2,
       6,     3,     7,     3,     1,     4,     1,     3,     4,     1,
       2,     1,     3,     1,     3,     5,     4,     6,     3,     5,
       3,     3,     3,     4,     0,     1,     3,     1,     1,     5,
       2,     2,     0,     1,     3,     0,     1,     3,     1,     7,
       8,     0,     2,     1,     1,     1,     3,     6,     3,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     1,     1,     1,
       1,     1,     5,     1,     2,     4,     3,     1,     3,     4,
       0,     1,     2,     6,     1,     3,     0,     2,     5,     9,
       0,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     1,     1,     1,     1,
       2,     2,     3,     5,     3,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     6,     4,     2,     5,     5,
       3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     7,     3,     5,     1,     0,     0,     8,
       0,     0,    12,     0,    10,   238,   161,     0,   162,    99,
       0,    96,   202,    94,   240,   241,   242,   243,     0,     0,
       0,   140,    63,     0,   201,     0,     0,     0,    64,     0,
       0,     0,   131,     0,     9,     2,    21,    35,   103,    36,
      24,     0,    25,   122,     0,    23,   196,   199,    26,     0,
      27,    41,    39,    34,    40,   197,   200,    30,     0,   167,
      33,    37,    38,    32,    31,    28,    29,   244,   195,   207,
     208,   209,     0,     4,    17,     0,     0,    99,   202,     0,
     198,   206,     0,   125,     0,     0,    44,     0,     0,   114,
       0,     0,     0,     0,     0,   190,   141,     0,     0,     0,
       0,     0,   180,   152,   160,   159,   149,   150,   157,   156,
     155,   154,   153,   142,   143,   144,   145,   146,   147,     0,
     148,   158,   151,   163,   164,     0,   120,     0,     0,   139,
       0,    22,    57,   123,   121,   114,     0,    46,   100,     0,
       0,     0,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   210,     0,     0,     0,     0,     0,   247,
     205,   239,    62,    11,    18,    14,    16,    15,   114,   203,
       0,    99,    94,    48,   126,     0,   128,     0,   125,   108,
       0,   193,   192,   194,   202,   118,     0,   115,   117,   111,
     214,   215,   101,     0,     0,   168,   169,     0,   191,     0,
       0,     0,     0,     0,     0,    19,     0,     0,   186,   181,
       0,   125,   133,   134,   135,   132,   138,     0,     0,    55,
     202,     0,     0,    97,     0,     0,     0,   114,   104,   110,
     112,   171,   170,   166,   226,   234,   236,   235,   233,   223,
     224,   231,   230,   229,   228,   227,   217,   218,   219,   220,
     221,   222,   232,   212,     0,     0,   225,     0,     0,     0,
      46,   131,     0,    45,     0,   113,     0,    95,     0,     0,
       0,     0,     0,    99,    88,     0,    87,     0,    86,    42,
      54,     0,    51,     0,     0,     0,   173,    20,     0,     0,
     182,   179,   125,     0,     0,   202,     0,     0,    59,     0,
       0,    84,     0,   216,    98,    47,   106,     0,     0,   246,
       0,     0,   109,    49,   127,   124,     0,   131,    43,   116,
     102,   165,   237,   188,     0,    85,    89,     0,    46,     0,
      50,     0,     0,   177,     0,   172,   174,   184,     0,   187,
       0,   131,   136,     0,   248,   249,     0,    58,     0,    56,
       0,    61,     0,   119,   105,     0,   213,   137,    90,     0,
       0,    53,    52,     0,     0,   176,     0,     0,   131,   122,
     192,     0,    60,     0,     0,     0,     0,   122,    70,    81,
      68,    69,     0,    66,    67,    65,    71,    73,   107,   245,
       0,   175,   178,     0,   185,   122,   129,     0,    72,     0,
       0,   125,    80,    83,    82,     0,   183,   130,   251,    91,
       0,    93,     0,   189,     0,    75,     0,     0,    74,     0,
      76,     0,    79,     0,    92,   114,    77,     0,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     3,     8,     9,    13,    14,    85,   179,
     226,    46,    47,   205,    95,    48,   194,    49,   301,   302,
     321,   239,   319,    50,    51,   399,   400,   438,   443,   401,
     402,   371,    52,   294,   295,    53,   403,   404,    89,   213,
      55,    56,    57,    58,    59,    90,   242,   207,    61,    62,
      63,   144,   196,   197,    64,   138,   234,   235,    65,    66,
      67,   133,    68,   135,    69,    70,   214,   253,    71,   305,
     306,   352,    72,   228,   229,   358,   311,    73,    74,   220,
      91,    76,   216,    77,    78,    79,    80,    81,    82,   317
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -343
static const yytype_int16 yypact[] =
{
     -30,    -6,    53,    10,  -343,    82,  -343,     7,  1604,  -343,
      40,    61,  -343,   109,  -343,  -343,  -343,   701,  -343,   133,
     701,  -343,    12,   157,  -343,  -343,  -343,  -343,   130,   162,
     167,   701,  -343,    67,  -343,   149,   151,   701,  -343,   163,
     113,   701,    21,   171,  -343,  1804,  -343,  -343,  -343,  -343,
    -343,   180,  -343,   163,     2,   146,  -343,  -343,  -343,     9,
    1387,  -343,  -343,  -343,  -343,  -343,  -343,  -343,   701,   176,
    -343,  -343,  -343,  -343,  -343,  1438,  1298,   250,  -343,  -343,
    -343,  -343,    89,  -343,  -343,     3,   165,   228,   153,    17,
    -343,  -343,   770,   242,   247,    35,  1298,   210,   701,  1854,
     220,   161,   242,   701,   701,   242,   188,   235,   276,   253,
    1349,  1654,   209,  -343,  -343,  -343,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,   260,
    -343,  -343,  -343,  -343,  -343,   269,  1298,   242,   163,  1298,
     271,  -343,   290,  -343,  -343,  1884,   505,   217,  -343,   254,
     701,   266,  1298,  1704,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,  -343,  -343,   701,   701,   701,   701,   701,  -343,
    -343,  -343,  -343,  -343,  -343,  -343,   298,  -343,  1854,  -343,
     701,  -343,   305,  -343,   230,   118,  -343,   291,   242,  -343,
     701,  -343,  1298,  1298,   240,  -343,    -4,  -343,  1298,  -343,
    -343,  -343,   -11,     8,   295,   900,  -343,   943,  -343,   100,
     275,   261,   701,   278,  1492,  -343,  1754,   294,   196,  -343,
     299,   242,  -343,   100,  -343,   238,  -343,  1914,   279,   285,
      13,    -3,     4,  -343,   989,   701,   701,  1854,   329,  1298,
    -343,  -343,  -343,  -343,  1298,  1298,   806,   806,  1469,   152,
     152,   152,   152,  1951,  1951,  1951,   478,   478,   586,   586,
     168,   168,  1298,  1298,   857,  1035,  1298,    27,   242,   284,
     334,   297,   311,  1298,   210,  -343,  1854,  -343,   242,  1704,
     292,  1704,   701,   296,  -343,   257,  -343,    14,   146,  1298,
     346,   -21,  -343,   701,   312,    36,  -343,  -343,   242,   163,
    -343,  -343,   242,   331,   242,   244,  1078,    31,  -343,    11,
     242,   316,   355,  -343,  -343,  1298,  1298,    54,   701,  -343,
     701,   701,  -343,  -343,  -343,  -343,   163,   297,  1298,  -343,
     -11,  -343,  -343,  -343,  1121,  -343,  -343,   314,   263,   701,
    -343,   278,    41,  1298,  1804,  -343,  -343,   -11,   -23,  -343,
     336,   297,  -343,   210,  -343,  -343,   317,  -343,   315,   -11,
     600,  -343,   701,  -343,  1298,  1167,  1298,  -343,  -343,   701,
     280,  1298,  -343,  1804,   701,  1804,   340,   242,   297,   163,
    1209,   366,  -343,   325,   323,   324,   347,   163,  -343,  -343,
    -343,  -343,   272,  -343,  -343,   146,  -343,  -343,  1298,  -343,
    1260,  1804,  1298,   163,   -11,   163,  -343,   701,  -343,   163,
     211,   242,  -343,  -343,  -343,  1704,  -343,  -343,  1298,  -343,
     242,  -343,   352,  -343,   115,   345,   353,  1554,  -343,   163,
    -343,   360,  1804,   351,  -343,  1854,  -343,    79,  -343
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -343,  -343,  -343,  -343,  -343,   380,  -343,    16,  -343,   189,
      -1,   -41,  -342,  -343,   -25,   -83,  -343,  -343,  -343,    38,
    -343,  -343,  -343,   313,  -343,    -2,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,   103,  -343,  -202,  -343,  -343,    -8,  -343,
    -216,  -343,  -343,  -343,  -142,    -7,   -97,   116,  -343,  -343,
    -340,  -162,   121,  -189,  -321,  -269,    91,  -343,  -343,  -343,
    -343,  -343,   432,  -343,  -343,  -343,  -343,  -278,  -343,  -343,
     101,  -343,  -343,  -343,   179,  -343,  -343,  -343,  -343,  -343,
       0,   293,  -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -251
static const yytype_int16 yytable[] =
{
      54,    60,   206,   241,   141,   298,   106,    45,    75,   282,
     193,   341,   336,   343,   150,    97,   284,    98,    98,   296,
     287,   350,   218,   367,   285,   322,   386,    84,   398,   145,
     406,   183,   323,   146,    11,     1,    15,    54,    60,    99,
      99,   347,   313,     4,   188,    75,   146,    16,    17,   407,
      18,   147,    12,     6,   232,   332,    12,    87,   146,   365,
     398,   146,   406,   348,   387,    20,   351,   137,   378,    21,
      88,    23,    24,    25,    26,    27,     7,   148,   355,   298,
     199,   407,   373,   286,   151,   195,    10,   383,    34,    83,
     148,   286,   389,   296,   212,   288,   151,   219,   368,   100,
     100,   184,   148,    54,    60,   148,    42,   448,   303,   304,
      12,    75,   252,    86,   200,   193,   107,   113,   366,   415,
     114,   115,   200,   360,   116,   117,   118,   119,   384,   233,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    16,
     129,   286,    18,   130,   146,    54,    60,   433,   193,   280,
     327,    32,   131,    75,   405,   279,    97,   103,    98,   146,
      93,   101,   146,    38,   436,   277,   286,   280,   102,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    16,    43,
      99,    18,    94,   172,   173,   141,   405,   185,   148,   104,
     195,   174,   175,   111,   105,   333,   176,    18,   108,   172,
     173,   109,   132,   148,   111,   241,   148,   174,   175,   111,
     210,   211,   176,   297,   186,   187,    54,    60,    54,    60,
     245,   140,   246,   195,    75,    15,    75,   416,   112,   193,
     142,   232,   432,   149,   153,   422,    16,    17,   430,    18,
     177,   178,   143,   284,   247,    98,    87,   363,   252,    98,
     252,   111,   111,   427,    20,    93,   177,   178,    21,    88,
      23,    24,    25,    26,    27,   181,   245,    99,   246,   209,
     195,    99,   227,   309,   198,   200,   221,    34,   191,   222,
     340,    54,    60,    54,    60,   227,   201,   297,   230,    75,
      21,    75,   192,   293,   223,    42,   231,   293,   237,   345,
     357,   238,   -13,   248,   195,    21,   233,   192,   293,    21,
      92,   192,   369,    96,   423,   250,   102,   278,   292,   281,
      21,   308,   192,   289,    96,   314,   312,   236,   300,   318,
     110,   320,   328,   335,   136,   139,   393,   245,   193,   337,
     342,    35,   251,   137,   141,    94,    54,    60,   447,   349,
     394,   395,    40,   385,    75,   396,   397,   370,   354,   361,
     372,   152,   297,   380,   388,   392,   391,   100,   413,   417,
     141,   418,   419,   420,   421,    54,    60,    54,    60,   414,
     435,   439,   411,    75,   252,    75,   437,   445,    44,   382,
     202,   203,   208,   446,   297,   182,   215,   217,   346,   334,
     424,   141,   339,    54,    60,   362,   356,   310,     0,     0,
       0,    75,     0,   195,     0,     0,     0,    54,    60,     0,
       0,     0,   434,     0,     0,    75,     0,     0,     0,    54,
      60,     0,     0,     0,    54,    60,   442,    75,   208,   244,
       0,     0,    75,   249,     0,     0,     0,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,     0,     0,   272,   273,   274,
     275,   276,   134,   201,     0,     0,     0,     0,   251,     0,
     251,   208,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   283,     0,     0,     0,     0,   359,     0,
     168,   169,   170,   171,    16,     0,     0,    18,   180,   172,
     173,     0,     0,     0,     0,   299,     0,   174,   175,   111,
      15,     0,   176,     0,   180,   377,     0,     0,   180,     0,
     316,    16,    17,     0,    18,     0,     0,     0,   325,   326,
     208,    87,   180,     0,     0,     0,     0,     0,     0,    20,
     243,     0,   201,    21,    88,    23,    24,    25,    26,    27,
       0,     0,     0,     0,     0,     0,   177,   178,   180,     0,
       0,   180,    34,     0,     0,     0,     0,   338,   143,   208,
       0,     0,     0,     0,   180,   344,   143,     0,     0,     0,
      42,     0,     0,     0,     0,     0,   353,     0,     0,     0,
       0,     0,   426,     0,   143,     0,     0,     0,   429,   431,
     170,   171,    16,     0,   251,    18,     0,   172,   173,     0,
       0,   374,     0,   375,   376,   174,   175,   111,   444,     0,
     176,     0,     0,     0,   180,   180,   293,     0,     0,     0,
     180,     0,   381,     0,     0,     0,     0,   180,    21,   180,
     192,     0,     0,     0,     0,     0,   390,     0,     0,     0,
       0,     0,     0,     0,   393,   408,     0,     0,     0,    35,
       0,     0,   410,     0,   177,   178,   180,   412,   394,   395,
      40,   180,     0,   396,   397,     0,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,     0,
     428,     0,     0,     0,     0,   180,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,     0,
      18,   180,     0,     0,     0,     0,     0,    87,   208,     0,
       0,     0,     0,     0,     0,    20,     0,     0,   180,    21,
      88,    23,    24,    25,    26,    27,     0,   180,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
     180,     0,     0,     0,   154,   155,   180,   156,   157,     0,
     158,   159,   160,   161,   162,   180,    42,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    16,     0,   189,    18,
       0,   172,   173,     0,     0,     0,   180,   180,   180,   174,
     175,   111,     0,   180,   176,     0,   158,   159,   160,   161,
     162,     0,   180,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    16,     0,     0,    18,     0,   172,   173,     0,
     180,     0,   180,     0,   180,   174,   175,   111,     0,     0,
     176,     0,     0,     0,     0,     0,     0,   190,   177,   178,
     180,   154,   155,     0,   156,   157,     0,   158,   159,   160,
     161,   162,     0,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    16,     0,     0,    18,     0,   172,   173,
       0,     0,     0,     0,   177,   178,   174,   175,   111,     0,
       0,   176,   329,   330,   154,   155,   290,   156,   157,     0,
     158,   159,   160,   161,   162,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    16,     0,     0,    18,
       0,   172,   173,     0,     0,     0,     0,     0,     0,   174,
     175,   111,     0,     0,   176,   177,   178,   154,   155,     0,
     156,   157,     0,   158,   159,   160,   161,   162,     0,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    16,
       0,   291,    18,     0,   172,   173,     0,     0,     0,     0,
       0,     0,   174,   175,   111,     0,     0,   176,   177,   178,
       0,     0,     0,   154,   155,     0,   156,   157,     0,   158,
     159,   160,   161,   162,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    16,     0,     0,    18,     0,
     172,   173,     0,     0,     0,     0,     0,     0,   174,   175,
     111,   177,   178,   176,   324,     0,     0,     0,     0,   154,
     155,     0,   156,   157,     0,   158,   159,   160,   161,   162,
       0,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    16,     0,     0,    18,     0,   172,   173,     0,     0,
       0,     0,     0,     0,   174,   175,   111,   177,   178,   176,
       0,   331,   154,   155,     0,   156,   157,     0,   158,   159,
     160,   161,   162,     0,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    16,     0,   364,    18,     0,   172,
     173,     0,     0,     0,     0,     0,     0,   174,   175,   111,
       0,     0,   176,   177,   178,   154,   155,     0,   156,   157,
       0,   158,   159,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    16,     0,     0,
      18,     0,   172,   173,     0,     0,     0,     0,     0,     0,
     174,   175,   111,     0,   379,   176,   177,   178,     0,     0,
       0,   154,   155,     0,   156,   157,     0,   158,   159,   160,
     161,   162,     0,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    16,     0,     0,    18,     0,   172,   173,
       0,     0,     0,     0,     0,     0,   174,   175,   111,   177,
     178,   176,   409,   154,   155,     0,   156,   157,     0,   158,
     159,   160,   161,   162,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    16,     0,     0,    18,     0,
     172,   173,     0,     0,     0,     0,     0,     0,   174,   175,
     111,     0,     0,   176,     0,   177,   178,     0,     0,     0,
       0,     0,     0,     0,   154,   155,     0,   156,   157,     0,
     158,   159,   160,   161,   162,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    16,     0,   425,    18,
       0,   172,   173,     0,     0,     0,  -250,   177,   178,   174,
     175,   111,   154,   155,   176,   156,   157,     0,   158,   159,
     160,   161,   162,     0,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    16,     0,     0,    18,     0,   172,
     173,     0,     0,     0,     0,     0,     0,   174,   175,   111,
       0,     0,   176,     0,     0,     0,     0,     0,   177,   178,
       0,     0,     0,   154,   155,     0,   156,   157,     0,   158,
     159,   160,   161,   162,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    16,     0,     0,    18,     0,
     172,   173,     0,     0,     0,     0,   177,   178,   174,   175,
     224,  -198,  -198,   176,  -198,  -198,     0,  -198,  -198,  -198,
    -198,  -198,     0,     0,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,     0,     0,     0,     0,     0,  -198,  -198,
       0,     0,     0,     0,     0,     0,  -198,  -198,  -198,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,     0,
       0,     0,  -206,  -206,     0,  -206,  -206,     0,  -206,  -206,
    -206,  -206,  -206,     0,     0,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,     0,     0,     0,     0,     0,  -206,
    -206,     0,     0,     0,     0,  -198,  -198,  -206,  -206,  -206,
     159,   160,   161,   162,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    16,     0,     0,    18,     0,
     172,   173,     0,     0,     0,     0,     0,    15,   174,   175,
     111,     0,     0,   176,     0,     0,     0,     0,    16,    17,
       0,    18,     0,     0,     0,     0,  -206,  -206,    19,     0,
       0,     0,     0,     0,   225,     0,    20,     0,     0,     0,
      21,    22,    23,    24,    25,    26,    27,     0,     0,    28,
       0,    29,    30,    31,    32,    33,     0,   177,   178,    34,
       0,    35,    36,    37,   303,   304,    38,    39,     0,    15,
       0,     0,    40,     0,    41,     0,     0,    42,     0,     0,
      16,    17,    43,    18,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,   440,     0,    20,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,    28,     0,    29,    30,    31,    32,    33,     0,    15,
       0,    34,     0,    35,    36,    37,     0,     0,    38,    39,
      16,    17,     0,    18,    40,     0,    41,   441,     0,    42,
      19,     0,     0,     0,    43,     0,     0,     0,    20,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,    28,     0,    29,    30,    31,    32,    33,     0,    15,
       7,    34,     0,    35,    36,    37,     0,     0,    38,    39,
      16,    17,     0,    18,    40,     0,    41,     0,     0,    42,
      19,     0,     0,     0,    43,     0,   225,     0,    20,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,    28,     0,    29,    30,    31,    32,    33,     0,    15,
       0,    34,     0,    35,    36,    37,     0,     0,    38,    39,
      16,    17,     0,    18,    40,     0,    41,     0,     0,    42,
      19,     0,     0,     0,    43,   111,     0,     0,    20,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,    28,     0,    29,    30,    31,    32,    33,     0,    15,
       0,    34,     0,    35,    36,    37,     0,     0,    38,    39,
      16,    17,     0,    18,    40,     0,    41,     0,     0,    42,
      19,     0,     0,     0,    43,     0,   307,     0,    20,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,    28,     0,    29,    30,    31,    32,    33,     0,    15,
       0,    34,     0,    35,    36,    37,     0,     0,    38,    39,
      16,    17,     0,    18,    40,     0,    41,     0,     0,    42,
      19,     0,     0,     0,    43,     0,     0,     0,    20,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,    28,     0,    29,    30,    31,    32,    33,     0,    15,
       0,    34,     0,    35,    36,    37,     0,     0,    38,    39,
      16,    17,     0,    18,    40,     0,    41,     0,     0,    42,
      87,     0,     0,     0,    43,     0,     0,     0,    20,    15,
       0,     0,    21,   204,    23,    24,    25,    26,    27,     0,
      16,    17,     0,    18,     0,     0,     0,     0,     0,     0,
      87,    34,     0,     0,     0,     0,     0,     0,    20,    15,
       0,     0,    21,   240,    23,    24,    25,    26,    27,    42,
      16,    17,     0,    18,     0,     0,     0,     0,     0,     0,
      87,    34,     0,     0,     0,     0,     0,     0,    20,     0,
       0,     0,    21,   315,    23,    24,    25,    26,    27,    42,
       0,   166,   167,   168,   169,   170,   171,    16,     0,     0,
      18,    34,   172,   173,     0,     0,     0,     0,     0,     0,
     174,   175,   111,     0,     0,   176,     0,     0,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178
};

static const yytype_int16 yycheck[] =
{
       8,     8,    99,   145,    45,   221,    31,     8,     8,   198,
      93,   289,   281,   291,     5,     3,     3,     5,     5,   221,
      12,    42,   105,    12,    28,    28,    49,    11,   370,    27,
     370,    28,    28,    44,    27,    65,    15,    45,    45,    27,
      27,    27,   231,    49,    27,    45,    44,    26,    27,   370,
      29,    49,    49,     0,   137,    28,    49,    36,    44,    28,
     402,    44,   402,    49,    87,    44,    87,    46,   337,    48,
      49,    50,    51,    52,    53,    54,    66,    88,    42,   295,
      45,   402,    28,    87,    87,    93,     4,    46,    67,    49,
      88,    87,   361,   295,   102,    87,    87,   105,    87,    87,
      87,    85,    88,   111,   111,    88,    85,    28,    72,    73,
      49,   111,   153,     4,    87,   198,    49,     4,    87,   388,
       7,     8,    87,   312,    11,    12,    13,    14,    87,   137,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    87,    29,    30,    44,   153,   153,   425,   231,    49,
     247,    62,    39,   153,   370,    37,     3,    27,     5,    44,
      27,     4,    44,    74,    49,   190,    87,    49,    11,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    90,
      27,    29,    49,    31,    32,   226,   402,    22,    88,    27,
     198,    39,    40,    41,    27,   278,    44,    29,    49,    31,
      32,    50,    89,    88,    41,   347,    88,    39,    40,    41,
      49,    50,    44,   221,    49,    50,   224,   224,   226,   226,
       3,    50,     5,   231,   224,    15,   226,   389,    39,   312,
      50,   314,   421,    87,    58,   397,    26,    27,    27,    29,
      88,    89,    53,     3,    27,     5,    36,     3,   289,     5,
     291,    41,    41,   415,    44,    27,    88,    89,    48,    49,
      50,    51,    52,    53,    54,    15,     3,    27,     5,    49,
     278,    27,    76,    77,    27,    87,    41,    67,    36,     3,
     288,   289,   289,   291,   291,    76,    97,   295,    28,   289,
      48,   291,    50,    36,    41,    85,    27,    36,    27,    42,
     308,    11,     4,    49,   312,    48,   314,    50,    36,    48,
      17,    50,   320,    20,    42,    49,    11,    87,    43,    28,
      48,    27,    50,    28,    31,    87,    27,   138,    50,    50,
      37,    46,     3,    49,    41,    42,    64,     3,   421,    28,
      48,    69,   153,    46,   385,    49,   354,   354,   445,     3,
      78,    79,    80,   354,   354,    83,    84,    41,    46,    28,
       5,    68,   370,    49,    28,    50,    49,    87,    28,     3,
     411,    46,    49,    49,    27,   383,   383,   385,   385,   387,
      28,    28,   383,   383,   425,   385,    41,    27,     8,   351,
      97,    98,    99,    42,   402,    82,   103,   104,   295,   278,
     402,   442,   286,   411,   411,   314,   305,   228,    -1,    -1,
      -1,   411,    -1,   421,    -1,    -1,    -1,   425,   425,    -1,
      -1,    -1,   430,    -1,    -1,   425,    -1,    -1,    -1,   437,
     437,    -1,    -1,    -1,   442,   442,   437,   437,   145,   146,
      -1,    -1,   442,   150,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,    40,   284,    -1,    -1,    -1,    -1,   289,    -1,
     291,   188,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,   309,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    29,    76,    31,
      32,    -1,    -1,    -1,    -1,   222,    -1,    39,    40,    41,
      15,    -1,    44,    -1,    92,   336,    -1,    -1,    96,    -1,
     237,    26,    27,    -1,    29,    -1,    -1,    -1,   245,   246,
     247,    36,   110,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,   363,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,   136,    -1,
      -1,   139,    67,    -1,    -1,    -1,    -1,   284,   389,   286,
      -1,    -1,    -1,    -1,   152,   292,   397,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,
      -1,    -1,   413,    -1,   415,    -1,    -1,    -1,   419,   420,
      24,    25,    26,    -1,   425,    29,    -1,    31,    32,    -1,
      -1,   328,    -1,   330,   331,    39,    40,    41,   439,    -1,
      44,    -1,    -1,    -1,   202,   203,    36,    -1,    -1,    -1,
     208,    -1,   349,    -1,    -1,    -1,    -1,   215,    48,   217,
      50,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,   372,    -1,    -1,    -1,    69,
      -1,    -1,   379,    -1,    88,    89,   244,   384,    78,    79,
      80,   249,    -1,    83,    84,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,    -1,
     417,    -1,    -1,    -1,    -1,   283,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
      29,   299,    -1,    -1,    -1,    -1,    -1,    36,   445,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,   316,    48,
      49,    50,    51,    52,    53,    54,    -1,   325,   326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
     338,    -1,    -1,    -1,     4,     5,   344,     7,     8,    -1,
      10,    11,    12,    13,    14,   353,    85,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,   374,   375,   376,    39,
      40,    41,    -1,   381,    44,    -1,    10,    11,    12,    13,
      14,    -1,   390,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
     408,    -1,   410,    -1,   412,    39,    40,    41,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
     428,     4,     5,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    -1,    -1,    88,    89,    39,    40,    41,    -1,
      -1,    44,    45,    46,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    -1,    -1,    44,    88,    89,     4,     5,    -1,
       7,     8,    -1,    10,    11,    12,    13,    14,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    -1,    -1,    44,    88,    89,
      -1,    -1,    -1,     4,     5,    -1,     7,     8,    -1,    10,
      11,    12,    13,    14,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    88,    89,    44,    45,    -1,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,    -1,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    88,    89,    44,
      -1,    46,     4,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    44,    88,    89,     4,     5,    -1,     7,     8,
      -1,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    -1,    43,    44,    88,    89,    -1,    -1,
      -1,     4,     5,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    88,
      89,    44,    45,     4,     5,    -1,     7,     8,    -1,    10,
      11,    12,    13,    14,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    -1,    44,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    87,    88,    89,    39,
      40,    41,     4,     5,    44,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    -1,    -1,     4,     5,    -1,     7,     8,    -1,    10,
      11,    12,    13,    14,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    88,    89,    39,    40,
      41,     4,     5,    44,     7,     8,    -1,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    88,    89,    39,    40,    41,
      11,    12,    13,    14,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    15,    39,    40,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    88,    89,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    -1,    88,    89,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    15,
      -1,    -1,    80,    -1,    82,    -1,    -1,    85,    -1,    -1,
      26,    27,    90,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    -1,    15,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      26,    27,    -1,    29,    80,    -1,    82,    83,    -1,    85,
      36,    -1,    -1,    -1,    90,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    -1,    15,
      66,    67,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      26,    27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,
      36,    -1,    -1,    -1,    90,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    -1,    15,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      26,    27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,
      36,    -1,    -1,    -1,    90,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    -1,    15,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      26,    27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,
      36,    -1,    -1,    -1,    90,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    -1,    15,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      26,    27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,
      36,    -1,    -1,    -1,    90,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    -1,    15,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      26,    27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,
      36,    -1,    -1,    -1,    90,    -1,    -1,    -1,    44,    15,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      26,    27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    67,    -1,    -1,    -1,    -1,    -1,    -1,    44,    15,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    85,
      26,    27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    67,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    85,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    67,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    92,    94,    49,    93,     0,    66,    95,    96,
       4,    27,    49,    97,    98,    15,    26,    27,    29,    36,
      44,    48,    49,    50,    51,    52,    53,    54,    57,    59,
      60,    61,    62,    63,    67,    69,    70,    71,    74,    75,
      80,    82,    85,    90,    96,   101,   102,   103,   106,   108,
     114,   115,   123,   126,   129,   131,   132,   133,   134,   135,
     136,   139,   140,   141,   145,   149,   150,   151,   153,   155,
     156,   159,   163,   168,   169,   171,   172,   174,   175,   176,
     177,   178,   179,    49,    98,    99,     4,    36,    49,   129,
     136,   171,   172,    27,    49,   105,   172,     3,     5,    27,
      87,     4,    11,    27,    27,    27,   105,    49,    49,    50,
     172,    41,   100,     4,     7,     8,    11,    12,    13,    14,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    27,
      30,    39,    89,   152,   153,   154,   172,    46,   146,   172,
      50,   102,    50,   100,   142,    27,    44,    49,    88,    87,
       5,    87,   172,    58,     4,     5,     7,     8,    10,    11,
      12,    13,    14,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    31,    32,    39,    40,    44,    88,    89,   100,
     153,    15,   114,    28,    98,    22,    49,    50,    27,    28,
      87,    36,    50,   106,   107,   129,   143,   144,    27,    45,
      87,   100,   172,   172,    49,   104,   137,   138,   172,    49,
      49,    50,   129,   130,   157,   172,   173,   172,   106,   129,
     170,    41,     3,    41,    41,    42,   101,    76,   164,   165,
      28,    27,   106,   129,   147,   148,   100,    27,    11,   112,
      49,   135,   137,    45,   172,     3,     5,    27,    49,   172,
      49,   100,   102,   158,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   105,    87,    37,
      49,    28,   144,   172,     3,    28,    87,    12,    87,    28,
       6,    28,    43,    36,   124,   125,   126,   129,   131,   172,
      50,   109,   110,    72,    73,   160,   161,    42,    27,    77,
     165,   167,    27,   144,    87,    49,   172,   180,    50,   113,
      46,   111,    28,    28,    45,   172,   172,   137,     3,    45,
      46,    46,    28,   106,   143,    49,   146,    28,   172,   138,
     129,   158,    48,   158,   172,    42,   124,    27,    49,     3,
      42,    87,   162,   172,    46,    42,   161,   129,   166,   100,
     144,    28,   147,     3,    28,    28,    87,    12,    87,   129,
      41,   122,     5,    28,   172,   172,   172,   100,   146,    43,
      49,   172,   110,    46,    87,   101,    49,    87,    28,   146,
     172,    49,    50,    64,    78,    79,    83,    84,   103,   116,
     117,   120,   121,   127,   128,   131,   141,   145,   172,    45,
     172,   101,   172,    28,   129,   146,   142,     3,    46,    49,
      49,    27,   142,    42,   116,    28,   100,   142,   172,   100,
      27,   100,   144,   158,   129,    28,    49,    41,   118,    28,
      42,    83,   101,   119,   100,    27,    42,   137,    28
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

  case 16:

/* Line 1455 of yacc.c  */
#line 96 "lex\\silang.yxx"
    { (yyval.expr)=importName((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str), true); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 101 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 105 "lex\\silang.yxx"
    { (yyval.expr)=makeEmpty(); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 106 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 111 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 137 "lex\\silang.yxx"
    { (yyval.expr)=makeConst((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].expr)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 140 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 145 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 150 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (2)].tp), (yyvsp[(2) - (2)].str)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 151 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (4)].tp), (yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 156 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 162 "lex\\silang.yxx"
    { (yyval.expr)=createEnum((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 167 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 171 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 172 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str),nullptr); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 179 "lex\\silang.yxx"
    { (yyval.tp)=nullptr; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 180 "lex\\silang.yxx"
    { (yyval.tp)=(yyvsp[(2) - (2)].tp); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 184 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 185 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 189 "lex\\silang.yxx"
    { (yyval.expr)=createNode((yyvsp[(1) - (1)].str)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 190 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), createNode((yyvsp[(3) - (3)].str))); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 195 "lex\\silang.yxx"
    { (yyval.expr)=makeClass((yyvsp[(1) - (5)].type),(yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].expr), (yyvsp[(4) - (5)].tp), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 196 "lex\\silang.yxx"
    { (yyval.expr)=annotationdClass((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 200 "lex\\silang.yxx"
    { (yyval.type)=0; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 201 "lex\\silang.yxx"
    { (yyval.type)=1; ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 212 "lex\\silang.yxx"
    { (yyval.expr)=setProtected(); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 219 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(2, "Init", (yyvsp[(3) - (5)].expr), nullptr, (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 223 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 224 "lex\\silang.yxx"
    { (yyval.expr)=makeEmpty(); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 225 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 229 "lex\\silang.yxx"
    { (yyval.expr)=makeCall("Init", (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 235 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(3, ":finalize", nullptr, nullptr, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 240 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 243 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 251 "lex\\silang.yxx"
    { (yyval.tp)=createInterface((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 261 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 266 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(0, (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].expr), (yyvsp[(6) - (6)].expr), nullptr); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 273 "lex\\silang.yxx"
    { (yyval.expr)=makeGet((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 277 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].tp), (yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 278 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (3)].str), nullptr, nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 289 "lex\\silang.yxx"
    { (yyval.tp)=getClassType((yyvsp[(1) - (1)].str)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 290 "lex\\silang.yxx"
    { (yyval.tp)=getClassType((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].tp)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 291 "lex\\silang.yxx"
    { (yyval.tp)=getType((yyvsp[(1) - (1)].type)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 292 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (3)].tp)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 293 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (4)].tp),(yyvsp[(3) - (4)].expr)); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 294 "lex\\silang.yxx"
    { (yyval.tp)=getFuncType(); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 295 "lex\\silang.yxx"
    { (yyval.tp)=nullAble((yyvsp[(1) - (2)].tp)); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 300 "lex\\silang.yxx"
    { (yyval.tp)=link((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].tp)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 304 "lex\\silang.yxx"
    { (yyval.expr)=createDef((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 305 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 306 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 307 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve(let((yyvsp[(2) - (4)].str)), (yyvsp[(4) - (4)].expr), true); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 308 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), true); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 313 "lex\\silang.yxx"
    { (yyval.expr)=makeSequence( (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 321 "lex\\silang.yxx"
    { (yyval.expr)=makeTuple((yyvsp[(4) - (5)].expr), (yyvsp[(2) - (5)].expr)); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 325 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 329 "lex\\silang.yxx"
    { (yyval.expr)=link(let((yyvsp[(1) - (3)].str)), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 330 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 337 "lex\\silang.yxx"
    { (yyval.expr)=makeCall((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 341 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 343 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 356 "lex\\silang.yxx"
    { (yyval.expr)=createNew((yyvsp[(1) - (5)].tp), (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 360 "lex\\silang.yxx"
    { (yyval.expr)=makeDelete((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 368 "lex\\silang.yxx"
    { (yyval.expr)=addFunctionBlock((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 372 "lex\\silang.yxx"
    { (yyval.expr)=NULL; ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 378 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].str), nullptr, 1); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 383 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 385 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 395 "lex\\silang.yxx"
    { (yyval.expr)=createOperator((yyvsp[(2) - (7)].type), (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 397 "lex\\silang.yxx"
    { (yyval.expr)=createOperator(BBRACKETS, (yyvsp[(5) - (8)].expr), (yyvsp[(7) - (8)].expr), (yyvsp[(8) - (8)].expr)); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 401 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 402 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 407 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 412 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 417 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(6, "", (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 422 "lex\\silang.yxx"
    { (yyval.expr)=createGo(createFunction(6, "", nullptr, (yyvsp[(2) - (3)].expr), (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 423 "lex\\silang.yxx"
    { (yyval.expr)=createGo((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 428 "lex\\silang.yxx"
    { (yyval.expr)=callReturn(); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 429 "lex\\silang.yxx"
    { (yyval.expr)=callReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 434 "lex\\silang.yxx"
    { (yyval.type)='+'; ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 435 "lex\\silang.yxx"
    { (yyval.type)='-'; ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 436 "lex\\silang.yxx"
    { (yyval.type)='*'; ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 437 "lex\\silang.yxx"
    { (yyval.type)='/'; ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 438 "lex\\silang.yxx"
    { (yyval.type)='&'; ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 439 "lex\\silang.yxx"
    { (yyval.type)='|'; ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 440 "lex\\silang.yxx"
    { (yyval.type)='!'; ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 441 "lex\\silang.yxx"
    { (yyval.type)='<'; ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 442 "lex\\silang.yxx"
    { (yyval.type)='>'; ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 443 "lex\\silang.yxx"
    { (yyval.type)='%'; ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 444 "lex\\silang.yxx"
    { (yyval.type)='.'; ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 445 "lex\\silang.yxx"
    { (yyval.type)=LEFTMOVE; ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 446 "lex\\silang.yxx"
    { (yyval.type)=RIGHTMOVE; ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 447 "lex\\silang.yxx"
    { (yyval.type)=URIGHTMOVE; ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 448 "lex\\silang.yxx"
    { (yyval.type)=LEQ; ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 449 "lex\\silang.yxx"
    { (yyval.type)=REQ; ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 450 "lex\\silang.yxx"
    { (yyval.type)=RGO; ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 451 "lex\\silang.yxx"
    { (yyval.type)=OR; ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 452 "lex\\silang.yxx"
    { (yyval.type)=AND; ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 456 "lex\\silang.yxx"
    { (yyval.type)='^'; ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 457 "lex\\silang.yxx"
    { (yyval.type)='~'; ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 470 "lex\\silang.yxx"
    { (yyval.expr)=makeIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 474 "lex\\silang.yxx"
    { (yyval.expr)=setElse((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 491 "lex\\silang.yxx"
    { (yyval.expr)=createSwitch((yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 496 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 500 "lex\\silang.yxx"
    { (yyval.expr)=createCase((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 501 "lex\\silang.yxx"
    { (yyval.expr)=createCase(nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 506 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 513 "lex\\silang.yxx"
    { (yyval.expr)=createTry( (yyvsp[(2) - (4)].expr), (yyvsp[(3) - (4)].expr), (yyvsp[(4) - (4)].expr) ); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 517 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 519 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 523 "lex\\silang.yxx"
    { (yyval.expr)=makeCatch((yyvsp[(3) - (6)].expr), (yyvsp[(4) - (6)].str), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 527 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 528 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),let((yyvsp[(3) - (3)].tp))); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 532 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 533 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 541 "lex\\silang.yxx"
    { (yyval.expr)=makeWhile((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 545 "lex\\silang.yxx"
    { (yyval.expr)=makeFor( (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].expr)); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 555 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 556 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), createFunction(6, "", nullptr, nullptr, (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 557 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 570 "lex\\silang.yxx"
    { (yyval.expr)=makeNull(); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 571 "lex\\silang.yxx"
    { (yyval.expr)=getVar((yyvsp[(1) - (1)].str)); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 572 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 573 "lex\\silang.yxx"
    { (yyval.expr)=unary((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 574 "lex\\silang.yxx"
    { (yyval.expr)=unaryAfter((yyvsp[(2) - (2)].type), (yyvsp[(1) - (2)].expr)); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 579 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 580 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr), false); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 581 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF(makeIsNull((yyvsp[(1) - (3)].expr)), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 582 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 583 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 584 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 585 "lex\\silang.yxx"
    { (yyval.expr)=createNew((yyvsp[(1) - (4)].tp), NULL, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 586 "lex\\silang.yxx"
    { (yyval.expr)=binary('+', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 587 "lex\\silang.yxx"
    { (yyval.expr)=binary('-', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 588 "lex\\silang.yxx"
    { (yyval.expr)=binary('*', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 589 "lex\\silang.yxx"
    { (yyval.expr)=binary('/', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 590 "lex\\silang.yxx"
    { (yyval.expr)=binary('&', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 591 "lex\\silang.yxx"
    { (yyval.expr)=binary('|', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 592 "lex\\silang.yxx"
    { (yyval.expr)=binary('<', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 593 "lex\\silang.yxx"
    { (yyval.expr)=binary('>', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 594 "lex\\silang.yxx"
    { (yyval.expr)=binary('%', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 595 "lex\\silang.yxx"
    { (yyval.expr)=binary('.', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 596 "lex\\silang.yxx"
    { (yyval.expr)=binary(LEFTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 597 "lex\\silang.yxx"
    { (yyval.expr)=binary(RIGHTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 598 "lex\\silang.yxx"
    { (yyval.expr)=binary(URIGHTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 599 "lex\\silang.yxx"
    { (yyval.expr)=binary(LEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 600 "lex\\silang.yxx"
    { (yyval.expr)=binary(REQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 601 "lex\\silang.yxx"
    { (yyval.expr)=binary(RGO, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 602 "lex\\silang.yxx"
    { (yyval.expr)=binary(EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 603 "lex\\silang.yxx"
    { (yyval.expr)=binary(AEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 604 "lex\\silang.yxx"
    { (yyval.expr)=binary(OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 605 "lex\\silang.yxx"
    { (yyval.expr)=binary(AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 609 "lex\\silang.yxx"
    { (yyval.expr)=binaryIs((yyvsp[(1) - (3)].expr), getType((yyvsp[(3) - (3)].type)));  ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 614 "lex\\silang.yxx"
    {(yyval.expr)=stringCat((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr));;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 622 "lex\\silang.yxx"
    { (yyval.expr)=(yyval.expr); ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 631 "lex\\silang.yxx"
    { (yyval.expr)=makeSplice((yyvsp[(1) - (6)].expr), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr)); ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 639 "lex\\silang.yxx"
    { (yyval.expr)=makeIndex((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 648 "lex\\silang.yxx"
    { (yyval.expr)=makeBased((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 654 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 655 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 659 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 660 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (5)].expr), let((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].expr))); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3373 "intermediate/silang.tab.cpp"
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
#line 663 "lex\\silang.yxx"


