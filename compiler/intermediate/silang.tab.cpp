
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
#define YYLAST   2138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  260
/* YYNRULES -- Number of states.  */
#define YYNSTATES  475

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
     100,   102,   104,   109,   113,   115,   119,   122,   127,   130,
     132,   136,   142,   144,   148,   152,   154,   155,   158,   159,
     163,   165,   169,   175,   178,   180,   182,   184,   186,   188,
     190,   192,   194,   196,   199,   201,   207,   208,   211,   215,
     220,   222,   225,   227,   230,   234,   235,   241,   243,   245,
     247,   250,   257,   261,   269,   273,   275,   280,   282,   286,
     291,   294,   296,   300,   305,   312,   314,   316,   320,   322,
     326,   332,   337,   344,   348,   354,   358,   362,   366,   371,
     372,   374,   378,   380,   382,   388,   391,   394,   395,   397,
     401,   402,   404,   408,   410,   418,   427,   435,   436,   439,
     441,   443,   445,   449,   456,   460,   468,   472,   475,   477,
     480,   482,   484,   486,   488,   490,   492,   494,   496,   498,
     500,   502,   504,   506,   508,   510,   512,   514,   516,   518,
     520,   522,   524,   526,   532,   536,   538,   540,   542,   544,
     546,   552,   554,   557,   562,   566,   568,   572,   577,   578,
     580,   583,   590,   592,   596,   597,   600,   606,   616,   617,
     619,   623,   627,   631,   633,   635,   637,   639,   641,   643,
     645,   647,   651,   654,   657,   659,   661,   663,   665,   668,
     671,   675,   681,   685,   689,   694,   698,   702,   706,   710,
     714,   718,   722,   726,   730,   734,   738,   742,   746,   750,
     754,   758,   762,   766,   770,   774,   776,   780,   782,   785,
     787,   789,   791,   793,   795,   802,   807,   810,   816,   822,
     826
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
      -1,   102,    -1,   101,   102,    -1,   132,    -1,   114,    -1,
     123,    -1,   135,    -1,   137,    -1,   173,    -1,   174,    -1,
     153,    -1,   171,    -1,   170,    -1,   158,    -1,   142,    -1,
     103,    -1,   108,    -1,   161,    -1,   165,    -1,   141,    -1,
     146,    -1,   140,    -1,    69,    49,     3,   174,    -1,    49,
       3,   174,    -1,   174,    -1,   105,    87,   174,    -1,   129,
      49,    -1,   129,    49,     3,   174,    -1,   130,    49,    -1,
     106,    -1,   107,    87,   106,    -1,    70,    50,    41,   109,
      42,    -1,   110,    -1,   109,    87,   110,    -1,    50,     3,
     174,    -1,    50,    -1,    -1,    46,   129,    -1,    -1,    11,
     113,    12,    -1,    50,    -1,   113,    87,    50,    -1,   115,
      50,   112,   111,   122,    -1,   181,   114,    -1,    62,    -1,
      74,    -1,   132,    -1,   127,    -1,   128,    -1,   117,    -1,
     120,    -1,   103,    -1,   142,    -1,    64,    46,    -1,   146,
      -1,    83,    27,   145,    28,   118,    -1,    -1,    41,    42,
      -1,    41,   119,    42,    -1,    83,    27,   138,    28,    -1,
     101,    -1,    84,   143,    -1,   116,    -1,   121,   116,    -1,
      41,   121,    42,    -1,    -1,    63,    49,    41,   125,    42,
      -1,   132,    -1,   126,    -1,   124,    -1,   125,   124,    -1,
      36,    49,    27,   145,    28,   147,    -1,    78,    49,   100,
      -1,    79,    49,    27,   129,    49,    28,   100,    -1,    79,
      49,   100,    -1,    50,    -1,    50,    11,   131,    12,    -1,
      48,    -1,   129,    44,    45,    -1,   129,    44,   174,    45,
      -1,   129,    88,    -1,    36,    -1,    36,    27,    28,    -1,
      36,    27,   131,    28,    -1,    36,    27,   131,    28,    46,
     129,    -1,   129,    -1,   130,    -1,   131,    87,   129,    -1,
     106,    -1,   132,    87,    49,    -1,   132,    87,    49,     3,
     174,    -1,   129,    49,     5,   174,    -1,   129,    27,   136,
      28,     5,   174,    -1,    44,   105,    45,    -1,    27,   174,
      87,   105,    28,    -1,   136,     5,   174,    -1,    49,    87,
      49,    -1,   136,    87,    49,    -1,    49,    27,   138,    28,
      -1,    -1,   139,    -1,   138,    87,   139,    -1,   174,    -1,
     104,    -1,   129,    49,    27,   138,    28,    -1,    82,   174,
      -1,   126,   143,    -1,    -1,   100,    -1,   129,    37,    49,
      -1,    -1,   107,    -1,   107,    87,   144,    -1,   144,    -1,
      80,   156,    27,   145,    28,   147,   143,    -1,    80,    27,
      28,    27,   145,    28,   147,   143,    -1,    80,    16,    27,
     145,    28,   147,   143,    -1,    -1,    46,   149,    -1,   106,
      -1,   129,    -1,   148,    -1,   149,    87,   148,    -1,    36,
      27,   145,    28,   147,   100,    -1,   174,    16,   100,    -1,
     174,    16,    27,   145,    28,   147,   100,    -1,    85,   147,
     100,    -1,    85,   174,    -1,    61,    -1,    61,   105,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    30,    -1,    11,    -1,    12,    -1,    89,    -1,
       4,    -1,    19,    -1,    18,    -1,    17,    -1,    14,    -1,
      13,    -1,    39,    -1,     8,    -1,     7,    -1,    26,    -1,
      29,    -1,   154,    -1,   155,    -1,    57,    27,   159,    28,
     160,    -1,   157,    58,   160,    -1,   157,    -1,   174,    -1,
     175,    -1,   102,    -1,   100,    -1,    71,   174,    41,   162,
      42,    -1,   163,    -1,   162,   163,    -1,    72,   164,    46,
     101,    -1,    73,    46,   101,    -1,   174,    -1,   164,    87,
     174,    -1,    75,   100,   166,   169,    -1,    -1,   167,    -1,
     166,   167,    -1,    76,    27,   168,    49,    28,   100,    -1,
     129,    -1,   168,    87,   129,    -1,    -1,    77,   100,    -1,
      59,    27,   174,    28,   160,    -1,    60,    27,   172,    43,
     174,    43,   174,    28,   160,    -1,    -1,   106,    -1,    49,
       3,   174,    -1,    49,     3,   100,    -1,    49,     5,   174,
      -1,   177,    -1,   133,    -1,   150,    -1,   137,    -1,   134,
      -1,   152,    -1,    67,    -1,    49,    -1,    27,   174,    28,
      -1,   155,   174,    -1,   174,   155,    -1,   173,    -1,   178,
      -1,   179,    -1,   180,    -1,   174,    32,    -1,   174,    31,
      -1,   174,    40,   174,    -1,   174,    88,   174,    46,   174,
      -1,    50,     4,    49,    -1,    50,     4,    50,    -1,   129,
      27,   138,    28,    -1,   174,    20,   174,    -1,   174,    21,
     174,    -1,   174,    22,   174,    -1,   174,    23,   174,    -1,
     174,    24,   174,    -1,   174,    25,   174,    -1,   174,    11,
     174,    -1,   174,    12,   174,    -1,   174,    89,   174,    -1,
     174,     4,   174,    -1,   174,    19,   174,    -1,   174,    18,
     174,    -1,   174,    17,   174,    -1,   174,    14,   174,    -1,
     174,    13,   174,    -1,   174,    39,   174,    -1,   174,    10,
     174,    -1,   174,     5,   174,    -1,   174,     8,   174,    -1,
     174,     7,   174,    -1,   151,    -1,   174,     6,    48,    -1,
      15,    -1,   176,    15,    -1,    51,    -1,    52,    -1,    53,
      -1,    54,    -1,   176,    -1,   174,    44,   174,    46,   174,
      45,    -1,   174,    44,   174,    45,    -1,   174,   100,    -1,
      90,    50,    27,   174,    28,    -1,    90,    50,    27,   182,
      28,    -1,    49,     3,   174,    -1,   182,    87,    49,     3,
     174,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    61,    62,    66,    67,    77,    79,    80,
      84,    85,    89,    90,    94,    95,    96,   100,   101,   105,
     106,   110,   111,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   137,   140,   144,   145,   150,   151,   152,   156,
     157,   163,   167,   168,   172,   173,   180,   181,   185,   186,
     190,   191,   195,   197,   201,   202,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   219,   224,   225,   226,   230,
     231,   235,   240,   241,   244,   245,   252,   256,   257,   261,
     262,   266,   274,   278,   279,   292,   293,   294,   295,   296,
     297,   301,   302,   303,   304,   308,   309,   310,   314,   315,
     316,   317,   318,   322,   330,   334,   338,   339,   346,   350,
     351,   352,   356,   357,   367,   371,   379,   383,   384,   389,
     394,   395,   396,   397,   405,   407,   409,   414,   415,   419,
     420,   424,   425,   429,   438,   440,   445,   447,   452,   453,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   480,
     481,   485,   486,   494,   498,   499,   503,   504,   508,   509,
     513,   519,   520,   524,   525,   529,   530,   537,   541,   542,
     543,   547,   551,   552,   556,   557,   565,   568,   572,   574,
     579,   580,   581,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   634,   638,   639,   643,
     644,   645,   646,   647,   656,   664,   673,   679,   680,   684,
     685
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
  "set", "def_type", "func_type", "def_types", "def", "sequence", "tuple",
  "tupleResolve", "tupleResolveParams", "call", "call_args", "call_arg",
  "class_new", "object_delete", "function", "block_or_none",
  "function_variable", "function_parameters", "operator_overload",
  "function_ret", "return_tuple_elem", "return_tuple_elems", "lambda",
  "array_call", "go", "rtn", "operator_binary", "operator_unary",
  "operator", "if_cond", "if_else", "if_expr", "block_or_line", "switch",
  "cases", "case", "case_exprs", "try", "try_catchs", "try_catch",
  "try_types", "try_finally", "while_loop", "for_loop", "for_line",
  "assignment", "expr", "type_expr", "string_lite", "expr_value", "splice",
  "index", "object_block", "annotation", "annotation_list", 0
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
     102,   102,   103,   104,   105,   105,   106,   106,   106,   107,
     107,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   118,   118,   118,   119,
     119,   120,   121,   121,   122,   122,   123,   124,   124,   125,
     125,   126,   127,   128,   128,   129,   129,   129,   129,   129,
     129,   130,   130,   130,   130,   131,   131,   131,   132,   132,
     132,   132,   132,   133,   134,   135,   136,   136,   137,   138,
     138,   138,   139,   139,   140,   141,   142,   143,   143,   144,
     145,   145,   145,   145,   146,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   155,
     155,   156,   156,   157,   158,   158,   159,   159,   160,   160,
     161,   162,   162,   163,   163,   164,   164,   165,   166,   166,
     166,   167,   168,   168,   169,   169,   170,   171,   172,   172,
     173,   173,   173,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   175,   176,   176,   177,
     177,   177,   177,   177,   178,   179,   180,   181,   181,   182,
     182
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     3,     2,     0,     0,     1,     2,
       2,     4,     1,     3,     3,     3,     3,     1,     2,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     3,     2,     4,     2,     1,
       3,     5,     1,     3,     3,     1,     0,     2,     0,     3,
       1,     3,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     5,     0,     2,     3,     4,
       1,     2,     1,     2,     3,     0,     5,     1,     1,     1,
       2,     6,     3,     7,     3,     1,     4,     1,     3,     4,
       2,     1,     3,     4,     6,     1,     1,     3,     1,     3,
       5,     4,     6,     3,     5,     3,     3,     3,     4,     0,
       1,     3,     1,     1,     5,     2,     2,     0,     1,     3,
       0,     1,     3,     1,     7,     8,     7,     0,     2,     1,
       1,     1,     3,     6,     3,     7,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     3,     1,     1,     1,     1,     1,
       5,     1,     2,     4,     3,     1,     3,     4,     0,     1,
       2,     6,     1,     3,     0,     2,     5,     9,     0,     1,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     2,     2,
       3,     5,     3,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     6,     4,     2,     5,     5,     3,
       5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       6,     0,     0,     7,     3,     5,     1,     0,     0,     8,
       0,     0,    12,     0,    10,   247,   169,     0,   170,     0,
       0,    97,   210,    95,   249,   250,   251,   252,     0,     0,
       0,   148,    64,     0,   209,     0,     0,     0,    65,     0,
       0,     0,   137,     0,     9,     2,    21,    35,   108,    36,
      24,     0,    25,   127,     0,     0,    23,   204,   207,    26,
       0,    27,    41,    39,    34,    40,   205,   245,   208,    30,
       0,   175,    33,    37,    38,    32,    31,    28,    29,   253,
     203,   215,   216,   217,     0,     4,    17,     0,     0,     0,
     210,     0,   206,   214,     0,     0,     0,     0,    44,     0,
       0,   119,     0,     0,     0,     0,     0,   198,   149,     0,
       0,     0,     0,     0,   188,   160,   168,   167,   157,   158,
     165,   164,     0,   163,   162,   161,   150,   151,   152,   153,
     154,   155,     0,   156,   166,   159,   171,   172,     0,   125,
       0,     0,   147,     0,    22,    58,   128,   126,   119,     0,
      46,   100,    48,     0,     0,     0,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   218,     0,
       0,     0,     0,     0,   256,   213,   248,    63,    11,    18,
      14,    16,    15,   130,   119,   211,     0,   102,   101,    95,
      49,   131,   105,   106,     0,   133,     0,   130,   113,     0,
     201,   200,   202,   210,   123,     0,   120,   122,   116,   222,
     223,   105,   106,     0,     0,   176,   177,     0,   199,     0,
       0,     0,     0,     0,     0,    19,     0,     0,   194,   189,
     130,     0,   130,   139,   140,   141,   138,   146,     0,     0,
      56,   210,     0,     0,    98,     0,     0,     0,   119,   109,
     115,   117,   179,   178,   174,   234,   242,   244,   243,   241,
     231,   232,   239,   238,   130,   144,   237,   236,   235,   225,
     226,   227,   228,   229,   230,   240,   220,     0,     0,   233,
       0,     0,     0,     0,     0,    46,   103,     0,   137,     0,
      45,     0,   118,     0,    96,     0,     0,     0,     0,     0,
      89,     0,    88,     0,    87,    42,    55,     0,    52,     0,
       0,     0,   181,    20,     0,     0,   190,   187,     0,   130,
       0,     0,   210,     0,     0,    60,     0,     0,    85,     0,
     224,    99,    47,   111,     0,     0,     0,   255,     0,     0,
     114,    50,   132,   129,     0,   107,     0,   137,    43,   121,
     173,   246,   196,     0,    86,    90,     0,    46,     0,    51,
       0,     0,   185,     0,   180,   182,   192,     0,   195,   137,
       0,   137,   142,     0,   257,   258,     0,    59,     0,    57,
       0,    62,     0,   124,   110,   137,     0,   221,   104,   143,
      91,     0,     0,    54,    53,     0,     0,   184,     0,     0,
     127,   137,   127,   200,     0,    61,     0,     0,     0,     0,
     127,    71,    82,    69,    70,     0,    67,    68,    66,    72,
      74,   112,     0,   254,     0,   183,   186,     0,   193,   136,
     127,   134,     0,    73,     0,     0,   130,    81,    84,    83,
     145,     0,   191,   135,   260,    92,     0,    94,     0,   197,
       0,    76,     0,     0,    75,     0,    77,     0,    80,     0,
      93,   119,    78,     0,    79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     3,     8,     9,    13,    14,    87,   184,
     236,    46,    47,   214,    97,    48,   201,    49,   317,   318,
     338,   250,   336,    50,    51,   422,   423,   464,   469,   424,
     425,   391,    52,   310,   311,    53,   426,   427,    91,    55,
     204,    56,    57,    58,    59,    60,    92,   253,   216,    62,
      63,    64,   147,   205,   206,    65,   141,   245,   246,    66,
      67,    68,    69,   136,    70,   138,    71,    72,   224,   264,
      73,   321,   322,   371,    74,   238,   239,   377,   327,    75,
      76,   230,    93,    78,   226,    79,    80,    81,    82,    83,
      84,   334
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -340
static const yytype_int16 yypact[] =
{
     -29,    33,   138,   -24,  -340,   147,  -340,    -6,  1743,  -340,
     114,   117,  -340,   172,  -340,  -340,  -340,   863,  -340,    91,
     863,  -340,     8,    23,  -340,  -340,  -340,  -340,   178,   182,
     189,   863,  -340,   169,  -340,   171,   188,   863,  -340,   208,
      42,   863,    93,   194,  -340,  1943,  -340,  -340,  -340,  -340,
    -340,   201,  -340,   208,   109,   211,   170,  -340,  -340,  -340,
      10,  1476,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,
     863,   228,  -340,  -340,  -340,  -340,  -340,  1527,  1387,   275,
    -340,  -340,  -340,  -340,   157,  -340,  -340,    81,   190,   264,
     195,     4,  -340,  -340,   807,   259,   265,   -17,  1387,   227,
     863,  1993,   244,    41,   222,   863,   863,   222,   214,   270,
     302,   272,  1438,  1793,   239,  -340,  -340,  -340,  -340,  -340,
    -340,  -340,   287,  -340,  -340,  -340,  -340,  -340,  -340,  -340,
    -340,  -340,   289,  -340,  -340,  -340,  -340,  -340,   291,  1387,
     222,   208,  1387,   293,  -340,   311,  -340,  -340,  2023,   646,
     203,  -340,  -340,   276,   863,   277,  1387,  1843,   863,   863,
     863,   863,   863,   863,   863,   863,   863,   174,   863,   863,
     863,   863,   863,   863,   863,   863,   863,  -340,  -340,   863,
     863,   863,   863,   863,  -340,  -340,  -340,  -340,  -340,  -340,
    -340,   320,  -340,   222,  1993,  -340,   863,  -340,   301,   321,
    -340,   246,    -4,   211,    -2,  -340,   303,   222,  -340,   863,
    -340,  1387,  1387,   238,  -340,    24,  -340,  1387,  -340,  -340,
    -340,   -14,  -340,     7,   307,   989,  -340,  1032,  -340,    39,
     294,   260,   863,   284,  1643,  -340,  1893,   309,   206,  -340,
     222,   312,   222,  -340,    39,  -340,   251,  -340,  2053,   290,
     297,    20,    47,    48,  -340,  1078,   863,   863,  1993,   341,
    1387,  -340,  -340,  -340,  -340,  1387,  1387,  1559,  1559,  1610,
     491,   491,   491,   491,   222,  -340,   715,   715,   715,   148,
     148,   843,   843,   509,   509,  1387,  1387,   946,  1124,  1387,
      -4,    95,   259,   222,   296,   346,   304,    50,   313,   325,
    1387,   227,  -340,  1993,  -340,  1843,   314,  1843,   863,   168,
    -340,   219,  -340,   137,   170,  1387,   352,   -10,  -340,   863,
     322,   141,  -340,  -340,    50,   208,  -340,  -340,   329,   222,
     330,   222,   247,  1167,    97,  -340,    17,    50,   319,   362,
    -340,  -340,  1387,  1387,   120,   863,   343,  -340,   863,   863,
    -340,  -340,  -340,  -340,    50,   -14,   208,   313,  1387,  -340,
    -340,  -340,  -340,  1210,  -340,  -340,   327,   164,   863,  -340,
     284,    67,  1387,  1943,  -340,  -340,   -14,    29,  -340,   313,
     350,   313,  -340,   227,  -340,  -340,   332,  -340,   333,   -14,
     558,  -340,   863,  -340,  1387,   313,  1256,  1387,   -14,  -340,
    -340,   863,   282,  1387,  -340,  1943,   863,  1943,   351,    50,
     208,   313,   208,  1298,   385,  -340,   345,   344,   347,   367,
     208,  -340,  -340,  -340,  -340,   306,  -340,  -340,   170,  -340,
    -340,  1387,   208,  -340,  1349,  1943,  1387,   208,   -14,  -340,
     208,  -340,   863,  -340,   208,   261,   222,  -340,  -340,  -340,
    -340,  1843,  -340,  -340,  1387,  -340,    50,  -340,   374,  -340,
      77,   354,   375,  1693,  -340,   208,  -340,   380,  1943,   370,
    -340,  1993,  -340,   124,  -340
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -340,  -340,  -340,  -340,  -340,   405,  -340,     6,  -340,   220,
       0,   -43,  -339,  -340,   -21,   -83,  -340,  -340,  -340,    44,
    -340,  -340,  -340,   334,  -340,    -5,  -340,  -340,  -340,  -340,
    -340,  -340,  -340,   108,  -340,  -209,  -340,  -340,    -8,   -90,
     317,  -222,  -340,  -340,  -340,  -145,    -7,   -97,   119,  -340,
    -340,  -310,  -216,   130,  -201,  -235,  -278,    98,  -340,  -340,
    -340,  -340,  -340,  -340,   507,  -340,  -340,  -340,  -340,  -289,
    -340,  -340,   103,  -340,  -340,  -340,   192,  -340,  -340,  -340,
    -340,  -340,    -1,   310,  -340,  -340,  -340,  -340,  -340,  -340,
    -340,  -340
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -260
static const yytype_int16 yytable[] =
{
      54,    61,   144,   252,   215,   203,   299,    77,    45,   314,
     108,    99,   200,   100,   222,   154,   360,    86,   362,   304,
     356,    11,   312,   301,   228,   100,   296,   103,   208,   387,
     149,   194,   369,   294,   104,   101,     1,    54,    61,   328,
     149,   330,     7,    12,    77,   295,   115,   101,   149,   116,
     117,   421,   302,   118,   119,   120,   121,   243,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    16,   132,
     209,    18,   133,   346,   151,   339,   340,   370,   408,   400,
     429,   134,     4,   149,   151,   297,   421,   202,   295,   314,
     219,   220,   151,   189,   297,   102,   221,   155,    21,   229,
     199,   410,   312,   412,   388,    54,    61,   102,    15,   188,
     200,   303,    77,   405,   263,   429,   409,   432,    95,    16,
      17,   149,    18,   350,   200,   385,   462,   151,   380,    89,
      12,   135,   244,   440,   155,   303,   148,    20,     6,   140,
      96,    21,    90,    23,    24,    25,    26,    27,   393,    54,
      61,    10,   474,   149,   406,   430,    77,   200,   150,   200,
      34,   344,   459,    85,   366,   151,    12,   256,   428,   257,
     173,   174,   175,   176,    16,   291,    88,    18,    42,   177,
     178,   149,   209,   374,   386,   290,   367,   179,   180,   113,
     430,   200,   181,   144,   439,   292,   441,   151,    99,   290,
     100,   274,   222,   428,   447,   105,   256,   303,   257,   106,
     351,   303,   190,   319,   320,   113,   107,    96,   109,    32,
     110,   252,   101,   313,   453,   151,    54,    61,    54,    61,
     258,    38,   290,    77,   290,    77,   182,   183,   111,   191,
     192,   301,    15,   100,   143,   458,   200,    43,   243,   113,
     383,   145,   100,    16,    17,   309,    18,   153,   198,   114,
     152,   364,   263,    89,   263,   101,   290,    21,   113,   199,
      21,    20,   199,   146,   101,    21,    90,    23,    24,    25,
      26,    27,   237,   325,   221,   290,   157,   197,   456,   355,
     186,   193,   207,   218,    34,   198,   309,    54,    61,    54,
      61,   209,   113,   313,    77,   232,    77,    21,    21,   199,
     199,   231,    42,   233,   240,   237,   376,   241,   242,   210,
     248,   290,   249,   244,   -13,   259,   261,    94,   292,   389,
      98,   298,   104,   293,   316,   305,   324,   308,   331,   329,
     335,    98,   309,   337,   345,   353,   398,   112,   448,   256,
     354,   139,   142,   357,    21,   368,   199,   379,   381,   140,
     390,   247,   361,   200,   144,    54,    61,   392,   373,   102,
     416,   395,    77,   407,   473,    35,   402,   262,   411,   437,
     156,   414,   313,   415,   417,   418,    40,   275,   442,   419,
     420,   443,   144,   444,   446,   463,   445,    54,    61,    54,
      61,   438,   461,   465,    77,   435,    77,   471,   263,   211,
     212,   217,   472,    44,   404,   225,   227,   313,   187,   365,
     449,   223,   359,   352,   375,   144,     0,    54,    61,   382,
     326,     0,     0,     0,    77,     0,     0,     0,   290,     0,
       0,     0,     0,    54,    61,     0,     0,     0,   460,     0,
      77,     0,     0,     0,     0,    54,    61,     0,   217,   255,
      54,    61,    77,   468,   260,     0,     0,    77,   265,   266,
     267,   268,   269,   270,   271,   272,   273,     0,   276,   277,
     278,   279,   280,   281,   282,   283,   284,     0,     0,   285,
     286,   287,   288,   289,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   217,     0,    98,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    16,     0,   300,
      18,   210,   177,   178,     0,   262,     0,   262,     0,     0,
     179,   180,   113,     0,     0,   181,     0,     0,    18,     0,
     177,   178,   315,     0,     0,   378,     0,   137,   179,   180,
     113,     0,     0,   181,     0,     0,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     0,   342,   343,   217,     0,
       0,     0,     0,     0,     0,     0,   399,     0,     0,   182,
     183,     0,     0,     0,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,   309,     0,     0,   182,   183,     0,
       0,   185,     0,   210,     0,   185,    21,     0,   199,     0,
       0,   358,     0,   217,     0,     0,     0,     0,   363,   185,
       0,     0,   416,     0,     0,     0,     0,    35,     0,   372,
     146,     0,   146,     0,     0,     0,   417,   418,    40,     0,
     146,   419,   420,     0,     0,     0,   185,     0,     0,   185,
       0,     0,   450,     0,     0,   394,     0,   452,   396,   397,
     146,    15,     0,   185,   455,   457,     0,     0,     0,     0,
       0,   262,    16,    17,     0,    18,     0,     0,   403,     0,
       0,     0,    89,     0,     0,   470,     0,     0,     0,     0,
      20,   254,     0,   413,    21,    90,    23,    24,    25,    26,
      27,     0,   431,     0,     0,     0,     0,     0,     0,     0,
       0,   434,     0,    34,     0,     0,   436,     0,   185,   185,
       0,     0,     0,     0,   185,     0,     0,     0,     0,     0,
       0,    42,   185,     0,   185,   171,   172,   173,   174,   175,
     176,    16,     0,     0,    18,     0,   177,   178,     0,     0,
       0,     0,   454,     0,   179,   180,   113,     0,     0,   181,
       0,     0,   185,     0,     0,     0,     0,   185,     0,     0,
       0,     0,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   217,     0,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,     0,     0,     0,
       0,     0,     0,   182,   183,     0,     0,   185,     0,     0,
       0,   158,   159,     0,   160,   161,     0,   162,   163,   164,
     165,   166,   185,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    16,     0,   195,    18,     0,   177,   178,
     185,     0,     0,     0,     0,     0,   179,   180,   113,   185,
     185,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,     0,   175,   176,    16,
     185,     0,    18,     0,   177,   178,     0,     0,    15,   185,
       0,     0,   179,   180,   113,     0,     0,   181,     0,    16,
      17,     0,    18,     0,   196,   182,   183,     0,     0,    89,
       0,   185,     0,   185,   185,     0,     0,    20,     0,     0,
     185,    21,    90,    23,    24,    25,    26,    27,     0,     0,
     185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,   182,   183,     0,     0,     0,     0,     0,   185,     0,
       0,   185,     0,   185,     0,     0,     0,     0,    42,     0,
     158,   159,     0,   160,   161,     0,   162,   163,   164,   165,
     166,   185,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    16,     0,     0,    18,     0,   177,   178,     0,
       0,     0,     0,     0,     0,   179,   180,   113,     0,     0,
     181,   347,   348,   158,   159,   306,   160,   161,     0,   162,
     163,   164,   165,   166,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    16,     0,     0,    18,     0,
     177,   178,     0,     0,     0,     0,     0,     0,   179,   180,
     113,     0,     0,   181,   182,   183,   158,   159,     0,   160,
     161,     0,   162,   163,   164,   165,   166,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    16,     0,
     307,    18,     0,   177,   178,     0,     0,     0,     0,     0,
       0,   179,   180,   113,     0,     0,   181,   182,   183,     0,
       0,     0,   158,   159,     0,   160,   161,     0,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    16,     0,     0,    18,     0,   177,
     178,     0,     0,     0,     0,     0,     0,   179,   180,   113,
     182,   183,   181,   341,     0,     0,     0,     0,   158,   159,
       0,   160,   161,     0,   162,   163,   164,   165,   166,     0,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      16,     0,     0,    18,     0,   177,   178,     0,     0,     0,
       0,     0,     0,   179,   180,   113,   182,   183,   181,     0,
     349,   158,   159,     0,   160,   161,     0,   162,   163,   164,
     165,   166,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    16,     0,   384,    18,     0,   177,   178,
       0,     0,     0,     0,     0,     0,   179,   180,   113,     0,
       0,   181,   182,   183,   158,   159,     0,   160,   161,     0,
     162,   163,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    16,     0,     0,    18,
       0,   177,   178,     0,     0,     0,     0,     0,     0,   179,
     180,   113,     0,   401,   181,   182,   183,     0,     0,     0,
     158,   159,     0,   160,   161,     0,   162,   163,   164,   165,
     166,     0,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    16,     0,     0,    18,     0,   177,   178,     0,
       0,     0,     0,     0,     0,   179,   180,   113,   182,   183,
     181,   433,   158,   159,     0,   160,   161,     0,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    16,     0,     0,    18,     0,   177,
     178,     0,     0,     0,     0,     0,     0,   179,   180,   113,
       0,     0,   181,     0,   182,   183,     0,     0,     0,     0,
       0,     0,     0,   158,   159,     0,   160,   161,     0,   162,
     163,   164,   165,   166,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    16,     0,   451,    18,     0,
     177,   178,     0,     0,     0,  -259,   182,   183,   179,   180,
     113,   158,   159,   181,   160,   161,     0,   162,   163,   164,
     165,   166,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    16,     0,     0,    18,     0,   177,   178,
       0,     0,     0,     0,     0,     0,   179,   180,   113,     0,
       0,   181,     0,     0,     0,     0,     0,   182,   183,     0,
       0,     0,   158,   159,     0,   160,   161,     0,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    16,     0,     0,    18,     0,   177,
     178,     0,     0,     0,     0,   182,   183,   179,   180,   234,
    -206,  -206,   181,  -206,  -206,     0,  -206,  -206,  -206,  -206,
    -206,     0,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,     0,     0,     0,     0,     0,  -206,  -206,     0,
       0,     0,     0,     0,     0,  -206,  -206,  -206,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   183,     0,     0,
       0,  -214,  -214,     0,  -214,  -214,     0,  -214,  -214,  -214,
    -214,  -214,     0,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,     0,     0,     0,     0,     0,  -214,  -214,
       0,     0,     0,     0,  -206,  -206,  -214,  -214,  -214,   162,
     163,   164,   165,   166,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    16,     0,     0,    18,     0,
     177,   178,     0,     0,     0,     0,     0,     0,   179,   180,
     113,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -214,  -214,     0,     0,     0,
       0,   163,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    16,     0,     0,    18,
       0,   177,   178,     0,     0,     0,     0,   182,   183,   179,
     180,   113,     0,     0,   181,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,    18,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,   235,     0,    20,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,   182,   183,
      28,     0,    29,    30,    31,    32,    33,     0,    15,     0,
      34,     0,    35,    36,    37,   319,   320,    38,    39,    16,
      17,     0,    18,    40,     0,    41,     0,     0,    42,    19,
       0,     0,     0,    43,     0,   466,     0,    20,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,    29,    30,    31,    32,    33,     0,    15,     0,
      34,     0,    35,    36,    37,     0,     0,    38,    39,    16,
      17,     0,    18,    40,     0,    41,   467,     0,    42,    19,
       0,     0,     0,    43,     0,     0,     0,    20,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,    29,    30,    31,    32,    33,     0,    15,     7,
      34,     0,    35,    36,    37,     0,     0,    38,    39,    16,
      17,     0,    18,    40,     0,    41,     0,     0,    42,    19,
       0,     0,     0,    43,     0,   235,     0,    20,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,    29,    30,    31,    32,    33,     0,    15,     0,
      34,     0,    35,    36,    37,     0,     0,    38,    39,    16,
      17,     0,    18,    40,     0,    41,     0,     0,    42,    19,
       0,     0,     0,    43,   113,     0,     0,    20,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,    29,    30,    31,    32,    33,     0,    15,     0,
      34,     0,    35,    36,    37,     0,     0,    38,    39,    16,
      17,     0,    18,    40,     0,    41,     0,     0,    42,    19,
       0,     0,     0,    43,     0,   323,     0,    20,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,    29,    30,    31,    32,    33,     0,    15,     0,
      34,     0,    35,    36,    37,     0,     0,    38,    39,    16,
      17,     0,    18,    40,     0,    41,     0,     0,    42,    19,
       0,     0,     0,    43,     0,     0,     0,    20,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,    29,    30,    31,    32,    33,     0,    15,     0,
      34,     0,    35,    36,    37,     0,     0,    38,    39,    16,
      17,     0,    18,    40,     0,    41,     0,     0,    42,    89,
       0,     0,     0,    43,     0,     0,     0,    20,    15,     0,
       0,    21,   213,    23,    24,    25,    26,    27,     0,    16,
      17,     0,    18,     0,     0,     0,     0,     0,     0,    89,
      34,     0,     0,     0,     0,     0,     0,    20,    15,     0,
       0,    21,   251,    23,    24,    25,    26,    27,    42,    16,
      17,     0,    18,     0,     0,     0,     0,     0,     0,    89,
      34,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,    21,   332,    23,    24,    25,    26,    27,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42
};

static const yytype_int16 yycheck[] =
{
       8,     8,    45,   148,   101,    95,   207,     8,     8,   231,
      31,     3,    95,     5,   104,     5,   305,    11,   307,    12,
     298,    27,   231,     3,   107,     5,    28,     4,    45,    12,
      44,    27,    42,    37,    11,    27,    65,    45,    45,   240,
      44,   242,    66,    49,    45,    49,     4,    27,    44,     7,
       8,   390,    28,    11,    12,    13,    14,   140,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      87,    29,    30,   274,    88,    28,    28,    87,    49,   357,
     390,    39,    49,    44,    88,    87,   425,    95,    49,   311,
      49,    50,    88,    87,    87,    87,   104,    87,    48,   107,
      50,   379,   311,   381,    87,   113,   113,    87,    15,    28,
     193,    87,   113,    46,   157,   425,    87,   395,    27,    26,
      27,    44,    29,    28,   207,    28,    49,    88,   329,    36,
      49,    89,   140,   411,    87,    87,    27,    44,     0,    46,
      49,    48,    49,    50,    51,    52,    53,    54,    28,   157,
     157,     4,    28,    44,    87,   390,   157,   240,    49,   242,
      67,   258,   451,    49,    27,    88,    49,     3,   390,     5,
      22,    23,    24,    25,    26,   196,     4,    29,    85,    31,
      32,    44,    87,    42,    87,   193,    49,    39,    40,    41,
     425,   274,    44,   236,   410,    27,   412,    88,     3,   207,
       5,    27,   292,   425,   420,    27,     3,    87,     5,    27,
     293,    87,    22,    72,    73,    41,    27,    49,    49,    62,
      49,   366,    27,   231,   440,    88,   234,   234,   236,   236,
      27,    74,   240,   234,   242,   236,    88,    89,    50,    49,
      50,     3,    15,     5,    50,   446,   329,    90,   331,    41,
       3,    50,     5,    26,    27,    36,    29,    87,    36,    39,
      49,    42,   305,    36,   307,    27,   274,    48,    41,    50,
      48,    44,    50,    53,    27,    48,    49,    50,    51,    52,
      53,    54,    76,    77,   292,   293,    58,    28,    27,   297,
      15,    27,    27,    49,    67,    36,    36,   305,   305,   307,
     307,    87,    41,   311,   305,     3,   307,    48,    48,    50,
      50,    41,    85,    41,    27,    76,   324,    28,    27,    99,
      27,   329,    11,   331,     4,    49,    49,    17,    27,   337,
      20,    28,    11,    87,    50,    28,    27,    43,    87,    27,
      50,    31,    36,    46,     3,    49,   354,    37,    42,     3,
      46,    41,    42,    28,    48,     3,    50,    28,    28,    46,
      41,   141,    48,   446,   407,   373,   373,     5,    46,    87,
      64,    28,   373,   373,   471,    69,    49,   157,    28,    28,
      70,    49,   390,    50,    78,    79,    80,   167,     3,    83,
      84,    46,   435,    49,    27,    41,    49,   405,   405,   407,
     407,   409,    28,    28,   405,   405,   407,    27,   451,    99,
     100,   101,    42,     8,   370,   105,   106,   425,    84,   311,
     425,   104,   303,   293,   321,   468,    -1,   435,   435,   331,
     238,    -1,    -1,    -1,   435,    -1,    -1,    -1,   446,    -1,
      -1,    -1,    -1,   451,   451,    -1,    -1,    -1,   456,    -1,
     451,    -1,    -1,    -1,    -1,   463,   463,    -1,   148,   149,
     468,   468,   463,   463,   154,    -1,    -1,   468,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,   209,
      29,   301,    31,    32,    -1,   305,    -1,   307,    -1,    -1,
      39,    40,    41,    -1,    -1,    44,    -1,    -1,    29,    -1,
      31,    32,   232,    -1,    -1,   325,    -1,    40,    39,    40,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,    -1,    88,
      89,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    88,    89,    -1,
      -1,    94,    -1,   383,    -1,    98,    48,    -1,    50,    -1,
      -1,   301,    -1,   303,    -1,    -1,    -1,    -1,   308,   112,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    69,    -1,   319,
     410,    -1,   412,    -1,    -1,    -1,    78,    79,    80,    -1,
     420,    83,    84,    -1,    -1,    -1,   139,    -1,    -1,   142,
      -1,    -1,   432,    -1,    -1,   345,    -1,   437,   348,   349,
     440,    15,    -1,   156,   444,   445,    -1,    -1,    -1,    -1,
      -1,   451,    26,    27,    -1,    29,    -1,    -1,   368,    -1,
      -1,    -1,    36,    -1,    -1,   465,    -1,    -1,    -1,    -1,
      44,    45,    -1,   383,    48,    49,    50,    51,    52,    53,
      54,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   401,    -1,    67,    -1,    -1,   406,    -1,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,    85,   225,    -1,   227,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,   442,    -1,    39,    40,    41,    -1,    -1,    44,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   471,    -1,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    -1,   300,    -1,    -1,
      -1,     4,     5,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,   315,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    -1,    31,    32,
     333,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,   342,
     343,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,    -1,    24,    25,    26,
     363,    -1,    29,    -1,    31,    32,    -1,    -1,    15,   372,
      -1,    -1,    39,    40,    41,    -1,    -1,    44,    -1,    26,
      27,    -1,    29,    -1,    87,    88,    89,    -1,    -1,    36,
      -1,   394,    -1,   396,   397,    -1,    -1,    44,    -1,    -1,
     403,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
     413,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    88,    89,    -1,    -1,    -1,    -1,    -1,   431,    -1,
      -1,   434,    -1,   436,    -1,    -1,    -1,    -1,    85,    -1,
       4,     5,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,   454,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      44,    45,    46,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    -1,    44,    88,    89,     4,     5,    -1,     7,
       8,    -1,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    -1,    -1,    44,    88,    89,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      88,    89,    44,    45,    -1,    -1,    -1,    -1,     4,     5,
      -1,     7,     8,    -1,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    88,    89,    44,    -1,
      46,     4,     5,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
      -1,    44,    88,    89,     4,     5,    -1,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    -1,    43,    44,    88,    89,    -1,    -1,    -1,
       4,     5,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    88,    89,
      44,    45,     4,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    44,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,     7,     8,    -1,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    -1,
      31,    32,    -1,    -1,    -1,    87,    88,    89,    39,    40,
      41,     4,     5,    44,     7,     8,    -1,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    88,    89,    39,    40,    41,
       4,     5,    44,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    -1,
      -1,     4,     5,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    88,    89,    39,    40,    41,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    88,    89,    39,
      40,    41,    -1,    -1,    44,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    88,    89,
      57,    -1,    59,    60,    61,    62,    63,    -1,    15,    -1,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    26,
      27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,    36,
      -1,    -1,    -1,    90,    -1,    42,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    15,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    26,
      27,    -1,    29,    80,    -1,    82,    83,    -1,    85,    36,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    15,    66,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    26,
      27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,    36,
      -1,    -1,    -1,    90,    -1,    42,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    15,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    26,
      27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,    36,
      -1,    -1,    -1,    90,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    15,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    26,
      27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,    36,
      -1,    -1,    -1,    90,    -1,    42,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    15,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    26,
      27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,    36,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    15,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    26,
      27,    -1,    29,    80,    -1,    82,    -1,    -1,    85,    36,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    44,    15,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    26,
      27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    44,    15,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    85,    26,
      27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85
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
     114,   115,   123,   126,   129,   130,   132,   133,   134,   135,
     136,   137,   140,   141,   142,   146,   150,   151,   152,   153,
     155,   157,   158,   161,   165,   170,   171,   173,   174,   176,
     177,   178,   179,   180,   181,    49,    98,    99,     4,    36,
      49,   129,   137,   173,   174,    27,    49,   105,   174,     3,
       5,    27,    87,     4,    11,    27,    27,    27,   105,    49,
      49,    50,   174,    41,   100,     4,     7,     8,    11,    12,
      13,    14,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    27,    30,    39,    89,   154,   155,   156,   174,
      46,   147,   174,    50,   102,    50,   100,   143,    27,    44,
      49,    88,    49,    87,     5,    87,   174,    58,     4,     5,
       7,     8,    10,    11,    12,    13,    14,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    31,    32,    39,
      40,    44,    88,    89,   100,   155,    15,   114,    28,    98,
      22,    49,    50,    27,    27,    28,    87,    28,    36,    50,
     106,   107,   129,   130,   131,   144,   145,    27,    45,    87,
     100,   174,   174,    49,   104,   138,   139,   174,    49,    49,
      50,   129,   130,   131,   159,   174,   175,   174,   106,   129,
     172,    41,     3,    41,    41,    42,   101,    76,   166,   167,
      27,    28,    27,   106,   129,   148,   149,   100,    27,    11,
     112,    49,   136,   138,    45,   174,     3,     5,    27,    49,
     174,    49,   100,   102,   160,   174,   174,   174,   174,   174,
     174,   174,   174,   174,    27,   100,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     129,   105,    27,    87,    37,    49,    28,    87,    28,   145,
     174,     3,    28,    87,    12,    28,     6,    28,    43,    36,
     124,   125,   126,   129,   132,   174,    50,   109,   110,    72,
      73,   162,   163,    42,    27,    77,   167,   169,   145,    27,
     145,    87,    49,   174,   182,    50,   113,    46,   111,    28,
      28,    45,   174,   174,   138,     3,   145,    45,    46,    46,
      28,   106,   144,    49,    46,   129,   147,    28,   174,   139,
     160,    48,   160,   174,    42,   124,    27,    49,     3,    42,
      87,   164,   174,    46,    42,   163,   129,   168,   100,    28,
     145,    28,   148,     3,    28,    28,    87,    12,    87,   129,
      41,   122,     5,    28,   174,    28,   174,   174,   129,   100,
     147,    43,    49,   174,   110,    46,    87,   101,    49,    87,
     147,    28,   147,   174,    49,    50,    64,    78,    79,    83,
      84,   103,   116,   117,   120,   121,   127,   128,   132,   142,
     146,   174,   147,    45,   174,   101,   174,    28,   129,   143,
     147,   143,     3,    46,    49,    49,    27,   143,    42,   116,
     100,    28,   100,   143,   174,   100,    27,   100,   145,   160,
     129,    28,    49,    41,   118,    28,    42,    83,   101,   119,
     100,    27,    42,   138,    28
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

  case 48:

/* Line 1455 of yacc.c  */
#line 152 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (2)].tp), (yyvsp[(2) - (2)].str)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 157 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 163 "lex\\silang.yxx"
    { (yyval.expr)=createEnum((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 168 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 172 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 173 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str),nullptr); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 180 "lex\\silang.yxx"
    { (yyval.tp)=nullptr; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 181 "lex\\silang.yxx"
    { (yyval.tp)=(yyvsp[(2) - (2)].tp); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 185 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 186 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 190 "lex\\silang.yxx"
    { (yyval.expr)=createNode((yyvsp[(1) - (1)].str)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 191 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), createNode((yyvsp[(3) - (3)].str))); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 196 "lex\\silang.yxx"
    { (yyval.expr)=makeClass((yyvsp[(1) - (5)].type),(yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].expr), (yyvsp[(4) - (5)].tp), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 197 "lex\\silang.yxx"
    { (yyval.expr)=annotationdClass((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 201 "lex\\silang.yxx"
    { (yyval.type)=0; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 202 "lex\\silang.yxx"
    { (yyval.type)=1; ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 213 "lex\\silang.yxx"
    { (yyval.expr)=setProtected(); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 220 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(2, "Init", (yyvsp[(3) - (5)].expr), nullptr, (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 224 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 225 "lex\\silang.yxx"
    { (yyval.expr)=makeEmpty(); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 226 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 230 "lex\\silang.yxx"
    { (yyval.expr)=makeCall("Init", (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 236 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(3, ":finalize", nullptr, nullptr, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 241 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 244 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 252 "lex\\silang.yxx"
    { (yyval.tp)=createInterface((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 262 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 267 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(0, (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].expr), (yyvsp[(6) - (6)].expr), nullptr); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 274 "lex\\silang.yxx"
    { (yyval.expr)=makeGet((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 278 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].tp), (yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 279 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (3)].str), nullptr, nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 292 "lex\\silang.yxx"
    { (yyval.tp)=getClassType((yyvsp[(1) - (1)].str)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 293 "lex\\silang.yxx"
    { (yyval.tp)=getClassType((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].tp)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 294 "lex\\silang.yxx"
    { (yyval.tp)=getType((yyvsp[(1) - (1)].type)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 295 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (3)].tp)); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 296 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (4)].tp),(yyvsp[(3) - (4)].expr)); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 297 "lex\\silang.yxx"
    { (yyval.tp)=nullAble((yyvsp[(1) - (2)].tp)); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 301 "lex\\silang.yxx"
    { (yyval.tp)=getFuncType(); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 302 "lex\\silang.yxx"
    { (yyval.tp)=getFuncType(NULL); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 303 "lex\\silang.yxx"
    { (yyval.tp)=getFuncType((yyvsp[(3) - (4)].tp), NULL); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 304 "lex\\silang.yxx"
    { (yyval.tp)=getFuncType((yyvsp[(3) - (6)].tp), (yyvsp[(6) - (6)].tp)); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 310 "lex\\silang.yxx"
    { (yyval.tp)=link((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].tp)); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 314 "lex\\silang.yxx"
    { (yyval.expr)=createDef((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 315 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str)); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 316 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 317 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve(let((yyvsp[(2) - (4)].str)), (yyvsp[(4) - (4)].expr), true); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 318 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), true); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 322 "lex\\silang.yxx"
    { (yyval.expr)=makeSequence( (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 330 "lex\\silang.yxx"
    { (yyval.expr)=makeTuple((yyvsp[(4) - (5)].expr), (yyvsp[(2) - (5)].expr)); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 334 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 338 "lex\\silang.yxx"
    { (yyval.expr)=link(let((yyvsp[(1) - (3)].str)), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 339 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 346 "lex\\silang.yxx"
    { (yyval.expr)=makeCall((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 350 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 352 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 367 "lex\\silang.yxx"
    { (yyval.expr)=createNew((yyvsp[(1) - (5)].tp), (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 371 "lex\\silang.yxx"
    { (yyval.expr)=makeDelete((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 379 "lex\\silang.yxx"
    { (yyval.expr)=addFunctionBlock((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 383 "lex\\silang.yxx"
    { (yyval.expr)=NULL; ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 389 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].str), nullptr, 1); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 394 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 396 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 406 "lex\\silang.yxx"
    { (yyval.expr)=createOperator((yyvsp[(2) - (7)].type), (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 408 "lex\\silang.yxx"
    { (yyval.expr)=createOperator(BBRACKETS, (yyvsp[(5) - (8)].expr), (yyvsp[(7) - (8)].expr), (yyvsp[(8) - (8)].expr)); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 410 "lex\\silang.yxx"
    { (yyval.expr)=createOperator(ARRAY, (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 414 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 415 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 420 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 425 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 430 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(6, "", (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 439 "lex\\silang.yxx"
    { (yyval.expr)=makeArrayCall((yyvsp[(1) - (3)].expr), createFunction(6, "", NULL, NULL, (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 441 "lex\\silang.yxx"
    { (yyval.expr)=makeArrayCall((yyvsp[(1) - (7)].expr), createFunction(6, "", (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr))); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 446 "lex\\silang.yxx"
    { (yyval.expr)=createGo(createFunction(6, "", nullptr, (yyvsp[(2) - (3)].expr), (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 447 "lex\\silang.yxx"
    { (yyval.expr)=createGo((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 452 "lex\\silang.yxx"
    { (yyval.expr)=callReturn(); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 453 "lex\\silang.yxx"
    { (yyval.expr)=callReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 458 "lex\\silang.yxx"
    { (yyval.type)='+'; ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 459 "lex\\silang.yxx"
    { (yyval.type)='-'; ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 460 "lex\\silang.yxx"
    { (yyval.type)='*'; ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 461 "lex\\silang.yxx"
    { (yyval.type)='/'; ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 462 "lex\\silang.yxx"
    { (yyval.type)='&'; ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 463 "lex\\silang.yxx"
    { (yyval.type)='|'; ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 464 "lex\\silang.yxx"
    { (yyval.type)='!'; ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 465 "lex\\silang.yxx"
    { (yyval.type)='<'; ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 466 "lex\\silang.yxx"
    { (yyval.type)='>'; ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 467 "lex\\silang.yxx"
    { (yyval.type)='%'; ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 468 "lex\\silang.yxx"
    { (yyval.type)='.'; ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 469 "lex\\silang.yxx"
    { (yyval.type)=LEFTMOVE; ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 470 "lex\\silang.yxx"
    { (yyval.type)=RIGHTMOVE; ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 471 "lex\\silang.yxx"
    { (yyval.type)=URIGHTMOVE; ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 472 "lex\\silang.yxx"
    { (yyval.type)=LEQ; ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 473 "lex\\silang.yxx"
    { (yyval.type)=REQ; ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 474 "lex\\silang.yxx"
    { (yyval.type)=RGO; ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 475 "lex\\silang.yxx"
    { (yyval.type)=OR; ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 476 "lex\\silang.yxx"
    { (yyval.type)=AND; ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 480 "lex\\silang.yxx"
    { (yyval.type)='^'; ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 481 "lex\\silang.yxx"
    { (yyval.type)='~'; ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 494 "lex\\silang.yxx"
    { (yyval.expr)=makeIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 498 "lex\\silang.yxx"
    { (yyval.expr)=setElse((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 515 "lex\\silang.yxx"
    { (yyval.expr)=createSwitch((yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 520 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 524 "lex\\silang.yxx"
    { (yyval.expr)=createCase((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 525 "lex\\silang.yxx"
    { (yyval.expr)=createCase(nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 530 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 537 "lex\\silang.yxx"
    { (yyval.expr)=createTry( (yyvsp[(2) - (4)].expr), (yyvsp[(3) - (4)].expr), (yyvsp[(4) - (4)].expr) ); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 541 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 543 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 547 "lex\\silang.yxx"
    { (yyval.expr)=makeCatch((yyvsp[(3) - (6)].expr), (yyvsp[(4) - (6)].str), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 551 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 552 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),let((yyvsp[(3) - (3)].tp))); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 556 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 557 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 565 "lex\\silang.yxx"
    { (yyval.expr)=makeWhile((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 569 "lex\\silang.yxx"
    { (yyval.expr)=makeFor( (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].expr)); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 579 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 580 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), createFunction(6, "", nullptr, nullptr, (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 581 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 594 "lex\\silang.yxx"
    { (yyval.expr)=makeNull(); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 595 "lex\\silang.yxx"
    { (yyval.expr)=getVar((yyvsp[(1) - (1)].str)); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 596 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 597 "lex\\silang.yxx"
    { (yyval.expr)=unary((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 598 "lex\\silang.yxx"
    { (yyval.expr)=unaryAfter((yyvsp[(2) - (2)].type), (yyvsp[(1) - (2)].expr)); ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 603 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 604 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr), false); ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 605 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF(makeIsNull((yyvsp[(1) - (3)].expr)), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 606 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 607 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 608 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 609 "lex\\silang.yxx"
    { (yyval.expr)=createNew((yyvsp[(1) - (4)].tp), NULL, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 610 "lex\\silang.yxx"
    { (yyval.expr)=binary('+', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 611 "lex\\silang.yxx"
    { (yyval.expr)=binary('-', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 612 "lex\\silang.yxx"
    { (yyval.expr)=binary('*', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 613 "lex\\silang.yxx"
    { (yyval.expr)=binary('/', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 614 "lex\\silang.yxx"
    { (yyval.expr)=binary('&', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 615 "lex\\silang.yxx"
    { (yyval.expr)=binary('|', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 616 "lex\\silang.yxx"
    { (yyval.expr)=binary('<', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 617 "lex\\silang.yxx"
    { (yyval.expr)=binary('>', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 618 "lex\\silang.yxx"
    { (yyval.expr)=binary('%', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 619 "lex\\silang.yxx"
    { (yyval.expr)=binary('.', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 620 "lex\\silang.yxx"
    { (yyval.expr)=binary(LEFTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 621 "lex\\silang.yxx"
    { (yyval.expr)=binary(RIGHTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 622 "lex\\silang.yxx"
    { (yyval.expr)=binary(URIGHTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 623 "lex\\silang.yxx"
    { (yyval.expr)=binary(LEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 624 "lex\\silang.yxx"
    { (yyval.expr)=binary(REQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 625 "lex\\silang.yxx"
    { (yyval.expr)=binary(RGO, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 626 "lex\\silang.yxx"
    { (yyval.expr)=binary(EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 627 "lex\\silang.yxx"
    { (yyval.expr)=binary(AEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 628 "lex\\silang.yxx"
    { (yyval.expr)=binary(OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 629 "lex\\silang.yxx"
    { (yyval.expr)=binary(AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 630 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 634 "lex\\silang.yxx"
    { (yyval.expr)=binaryIs((yyvsp[(1) - (3)].expr), getType((yyvsp[(3) - (3)].type)));  ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 639 "lex\\silang.yxx"
    {(yyval.expr)=stringCat((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr));;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 647 "lex\\silang.yxx"
    { (yyval.expr)=(yyval.expr); ;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 656 "lex\\silang.yxx"
    { (yyval.expr)=makeSplice((yyvsp[(1) - (6)].expr), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr)); ;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 664 "lex\\silang.yxx"
    { (yyval.expr)=makeIndex((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 673 "lex\\silang.yxx"
    { (yyval.expr)=makeBased((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 679 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 680 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 684 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 685 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (5)].expr), let((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].expr))); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3467 "intermediate/silang.tab.cpp"
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
#line 688 "lex\\silang.yxx"


