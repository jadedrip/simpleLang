
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
#define YYLAST   1525

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  206
/* YYNRULES -- Number of states.  */
#define YYNSTATES  353

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
     100,   104,   106,   110,   113,   118,   120,   124,   130,   132,
     136,   138,   140,   144,   150,   153,   155,   157,   159,   161,
     163,   165,   167,   169,   172,   175,   181,   184,   186,   189,
     193,   194,   200,   202,   204,   206,   209,   216,   220,   228,
     232,   234,   236,   240,   245,   247,   250,   252,   256,   262,
     266,   272,   276,   280,   282,   286,   291,   292,   294,   298,
     300,   302,   305,   308,   312,   313,   315,   319,   321,   329,
     330,   333,   335,   337,   339,   343,   350,   352,   355,   358,
     360,   362,   364,   366,   368,   370,   372,   374,   376,   378,
     380,   382,   384,   386,   388,   390,   392,   394,   396,   398,
     400,   402,   404,   406,   408,   410,   416,   420,   422,   424,
     426,   428,   430,   436,   438,   441,   446,   450,   452,   456,
     461,   462,   464,   467,   474,   476,   480,   481,   484,   490,
     500,   501,   503,   507,   511,   513,   515,   517,   519,   521,
     523,   525,   529,   533,   537,   540,   543,   545,   547,   549,
     551,   554,   557,   561,   567,   571,   573,   575,   577,   579,
     581,   588,   593,   596,   602,   608,   612
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
      -1,   109,    -1,   116,    -1,   126,    -1,   128,    -1,   160,
      -1,   161,    -1,   140,    -1,   158,    -1,   157,    -1,   145,
      -1,   132,    -1,   101,    -1,   106,    -1,   148,    -1,   152,
      -1,   131,    -1,   135,    -1,    69,    48,     3,   161,    -1,
      48,     3,   161,    -1,   161,    -1,   103,    85,   161,    -1,
     122,    48,    -1,   122,    48,     3,   161,    -1,   104,    -1,
     105,    85,   104,    -1,    70,    48,    40,   107,    41,    -1,
     108,    -1,   107,    85,   108,    -1,   102,    -1,    48,    -1,
     110,    49,   115,    -1,   110,    49,    45,   122,   115,    -1,
     167,   109,    -1,    62,    -1,    74,    -1,   123,    -1,   120,
      -1,   121,    -1,   112,    -1,   113,    -1,   132,    -1,   119,
      42,    -1,    64,    45,    -1,    83,    26,   134,    27,    98,
      -1,    84,    98,    -1,   111,    -1,   114,   111,    -1,    40,
     114,    41,    -1,    -1,    63,    48,    40,   118,    41,    -1,
     123,    -1,   119,    -1,   117,    -1,   118,   117,    -1,    35,
      48,    26,   134,    27,   136,    -1,    78,    48,    98,    -1,
      79,    48,    26,   122,    48,    27,    98,    -1,    79,    48,
      98,    -1,    49,    -1,    47,    -1,   122,    43,    44,    -1,
     122,    43,   161,    44,    -1,    35,    -1,   122,    86,    -1,
     104,    -1,   123,    85,    48,    -1,   123,    85,    48,     3,
     161,    -1,    43,   103,    44,    -1,    26,   161,    85,   103,
      27,    -1,   127,     5,   161,    -1,   123,     5,   161,    -1,
      48,    -1,   127,    85,    48,    -1,    48,    26,   129,    27,
      -1,    -1,   130,    -1,   129,    85,   130,    -1,   161,    -1,
     102,    -1,    82,   161,    -1,   119,    98,    -1,   122,    36,
      48,    -1,    -1,   105,    -1,   105,    85,   133,    -1,   133,
      -1,    80,   143,    26,   134,    27,   136,    98,    -1,    -1,
      45,   138,    -1,   104,    -1,   122,    -1,   137,    -1,   138,
      85,   137,    -1,    35,    26,   105,    27,   136,    98,    -1,
      61,    -1,    61,   161,    -1,    61,   103,    -1,    19,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      29,    -1,    11,    -1,    12,    -1,    87,    -1,     4,    -1,
      18,    -1,    17,    -1,    16,    -1,    14,    -1,    13,    -1,
      38,    -1,    10,    -1,     5,    -1,     9,    -1,     8,    -1,
       7,    -1,    25,    -1,    28,    -1,   141,    -1,   142,    -1,
      57,    26,   146,    27,   147,    -1,   144,    58,   147,    -1,
     144,    -1,   161,    -1,   162,    -1,   100,    -1,    98,    -1,
      71,   161,    40,   149,    41,    -1,   150,    -1,   149,   150,
      -1,    72,   151,    45,    99,    -1,    73,    45,    99,    -1,
     161,    -1,   151,    85,   161,    -1,    75,    98,   153,   156,
      -1,    -1,   154,    -1,   153,   154,    -1,    76,    26,   155,
      48,    27,    98,    -1,   122,    -1,   155,    85,   122,    -1,
      -1,    77,    98,    -1,    59,    26,   161,    27,   147,    -1,
      60,    26,   159,    42,   161,    42,   161,    27,   147,    -1,
      -1,   104,    -1,    48,     3,   161,    -1,    48,     3,    98,
      -1,   163,    -1,   124,    -1,   139,    -1,   128,    -1,   125,
      -1,    67,    -1,    48,    -1,    26,   161,    27,    -1,   161,
     141,   161,    -1,   161,    11,   161,    -1,   142,   161,    -1,
     161,   142,    -1,   160,    -1,   164,    -1,   165,    -1,   166,
      -1,   161,    31,    -1,   161,    30,    -1,   161,    39,   161,
      -1,   161,    86,   161,    45,   161,    -1,   161,     6,    47,
      -1,    50,    -1,    51,    -1,    52,    -1,    53,    -1,    55,
      -1,   161,    43,   161,    45,   161,    44,    -1,   161,    43,
     161,    44,    -1,   161,    98,    -1,    88,    49,    26,   161,
      27,    -1,    88,    49,    26,   168,    27,    -1,    48,     3,
     161,    -1,   168,    85,    48,     3,   161,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    61,    62,    66,    67,    78,    79,    82,
      84,    85,    89,    90,    94,    95,    99,   100,   104,   108,
     109,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   134,
     137,   141,   142,   147,   148,   152,   153,   159,   163,   164,
     169,   170,   177,   179,   181,   185,   186,   190,   191,   192,
     193,   194,   195,   196,   197,   202,   207,   212,   213,   216,
     217,   224,   228,   229,   233,   234,   238,   246,   250,   251,
     262,   263,   264,   265,   266,   267,   272,   273,   274,   278,
     286,   290,   291,   295,   296,   303,   307,   308,   309,   313,
     314,   321,   329,   334,   339,   340,   341,   342,   350,   355,
     356,   360,   361,   365,   366,   370,   376,   377,   378,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   408,   409,   413,   414,   422,   426,   427,   431,   432,
     436,   437,   441,   447,   448,   452,   453,   457,   458,   465,
     469,   470,   471,   475,   479,   480,   484,   485,   493,   496,
     500,   502,   507,   508,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   538,   542,   543,   544,   545,   546,
     555,   563,   572,   578,   579,   583,   584
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
  "tupleResolveDef", "call", "call_args", "call_arg", "object_delete",
  "function", "function_variable", "function_parameters",
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
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     102,   103,   103,   104,   104,   105,   105,   106,   107,   107,
     108,   108,   109,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   113,   114,   114,   115,
     115,   116,   117,   117,   118,   118,   119,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   123,   123,   123,   124,
     125,   126,   126,   127,   127,   128,   129,   129,   129,   130,
     130,   131,   132,   133,   134,   134,   134,   134,   135,   136,
     136,   137,   137,   138,   138,   139,   140,   140,   140,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   142,   142,   143,   143,   144,   145,   145,   146,   146,
     147,   147,   148,   149,   149,   150,   150,   151,   151,   152,
     153,   153,   153,   154,   155,   155,   156,   156,   157,   158,
     159,   159,   160,   160,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   163,   163,   163,   163,   163,
     164,   165,   166,   167,   167,   168,   168
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     3,     2,     0,     1,     2,     0,
       2,     4,     1,     3,     3,     3,     1,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     1,     3,     2,     4,     1,     3,     5,     1,     3,
       1,     1,     3,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     5,     2,     1,     2,     3,
       0,     5,     1,     1,     1,     2,     6,     3,     7,     3,
       1,     1,     3,     4,     1,     2,     1,     3,     5,     3,
       5,     3,     3,     1,     3,     4,     0,     1,     3,     1,
       1,     2,     2,     3,     0,     1,     3,     1,     7,     0,
       2,     1,     1,     1,     3,     6,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     1,     1,     1,
       1,     1,     5,     1,     2,     4,     3,     1,     3,     4,
       0,     1,     2,     6,     1,     3,     0,     2,     5,     9,
       0,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     2,     2,     1,     1,     1,     1,
       2,     2,     3,     5,     3,     1,     1,     1,     1,     1,
       6,     4,     2,     5,     5,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     9,     3,     5,     1,     0,     0,     7,
       0,     0,    12,     0,    10,   141,     0,   142,    84,     0,
      81,   180,    80,   195,   196,   197,   198,   199,     0,     0,
       0,   116,    55,     0,   179,     0,     0,     0,    56,     0,
       0,     0,     0,     8,     2,    19,    33,    86,    34,    22,
       0,    23,     0,     0,    21,   175,   178,    24,     0,    25,
      37,    32,    38,   176,    28,     0,   147,    31,    35,    36,
      30,    29,    26,    27,   174,   187,   188,   189,     0,     4,
      16,     0,     0,     0,   180,   177,   186,     0,     0,     0,
       0,    41,     0,    96,     0,     0,   170,   118,    41,     0,
       0,     0,     0,     0,   160,   129,   137,   140,   139,   138,
     136,   126,   127,   134,   133,   132,   131,   130,   119,   120,
     121,   122,   123,   124,   125,   135,   128,   143,   144,     0,
     101,     0,    20,    70,   102,     0,    43,    85,     0,     0,
       0,     0,   184,     0,     0,   191,   190,     0,     0,     0,
     202,     0,   185,    54,    11,    17,    14,    13,    15,   181,
       0,    84,    45,     0,   104,    89,     0,   173,   172,   180,
     100,     0,    97,    99,     0,   148,   149,     0,   171,     0,
       0,     0,     0,     0,     0,     0,   166,   161,   104,     0,
       0,     0,    52,    82,     0,     0,    92,    87,    91,    94,
     151,   150,   146,   183,   192,     0,     0,   182,     0,   109,
       0,   105,     0,   107,     0,    42,     0,    95,     0,     0,
       0,     0,     0,    84,    74,     0,    73,    72,    39,    51,
      50,     0,    48,     0,     0,     0,   153,    18,     0,     0,
     162,   159,     0,   180,     0,     0,     0,     0,     0,     0,
       0,    67,    60,    61,     0,     0,    58,    59,    57,    62,
      70,    83,    44,     0,   201,     0,     0,    90,     0,     0,
      46,     0,     0,   109,    40,    98,   145,   194,   168,     0,
      71,    75,     0,    47,     0,     0,   157,     0,   152,   154,
     164,     0,   167,   109,     0,   203,   204,     0,    64,     0,
       0,   104,    66,    69,    68,    63,    53,    88,     0,   193,
     111,   112,   113,   110,   115,   106,   103,    76,     0,    40,
      49,     0,     0,   156,     0,     0,     0,   172,     0,    77,
       0,    79,     0,   200,     0,     0,   155,   158,     0,   165,
     108,     0,     0,     0,   114,     0,   163,   206,     0,    65,
     169,     0,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     3,     8,     9,    13,    14,    81,   150,
     184,    45,    46,   170,    90,    47,   211,    48,   231,   232,
      49,    50,   251,   252,   253,   254,   192,    51,   224,   225,
      52,   256,   257,    53,    54,    55,    56,    57,    58,    85,
     171,   172,    60,    61,   213,   214,    62,   269,   312,   313,
      63,    64,   151,    65,   129,    66,    67,   174,   202,    68,
     235,   236,   285,    69,   186,   187,   291,   241,    70,    71,
     179,    86,    73,   176,    74,    75,    76,    77,    78,   245
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -214
static const yytype_int16 yypact[] =
{
     -30,    67,    49,   -20,  -214,    48,  -214,    66,  1202,  -214,
      76,    77,  -214,   132,  -214,  -214,  1406,  -214,   118,  1406,
    -214,     6,  -214,  -214,  -214,  -214,  -214,  -214,   126,   146,
     148,  1406,  -214,   123,  -214,   142,   143,  1406,  -214,   160,
      46,  1406,   157,  -214,  1355,  -214,  -214,  -214,  -214,  -214,
     159,  -214,   160,    64,     8,  -214,  -214,  -214,    12,  1055,
    -214,  -214,  -214,  -214,  -214,  1406,   151,  -214,  -214,  -214,
    -214,  -214,  1105,   968,  -214,  -214,  -214,  -214,    75,  -214,
    -214,    62,    92,   189,    16,  -214,  -214,   425,   134,   193,
      44,   968,   441,  1427,  1406,  1406,   134,   135,   968,   181,
     219,   184,  1018,  1355,   150,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   202,
     968,   204,  -214,   119,  -214,   331,   228,  -214,  1406,   186,
    1406,   187,   968,  1253,  1406,  -214,  -214,  1406,  1406,  1406,
    -214,  1406,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    1406,  -214,  -214,    -6,   134,  -214,  1406,  -214,   968,    19,
    -214,    -2,  -214,   968,   212,   579,  -214,   621,  -214,   201,
     145,  1406,   197,  1151,  1304,   218,   -43,  -214,   134,  1458,
     154,   134,  -214,  -214,   666,  1406,   968,   245,   968,  -214,
    -214,  -214,  -214,  1130,   968,   537,   711,   968,     1,   206,
     134,   164,    60,  -214,   225,   968,   441,  -214,  1427,  1253,
     207,  1253,  1406,   205,  -214,   158,  -214,   170,   968,   253,
    -214,    36,  -214,  1406,   214,    89,  -214,  -214,   134,   160,
    -214,  -214,   230,   113,   753,     2,   215,   216,   217,   236,
     160,  -214,  -214,  -214,   163,   128,  -214,  -214,   170,  -214,
     -13,  -214,   968,  1406,  -214,  1406,  1406,  -214,   134,   160,
    -214,   134,   220,   206,   968,  -214,  -214,  -214,  -214,   795,
    -214,  -214,  1406,  -214,   197,    72,   968,  1355,  -214,  -214,
     -25,    58,  -214,   206,   441,  -214,  -214,   223,  -214,   160,
     -16,   134,  -214,  -214,  -214,  -214,  -214,   968,   840,   968,
    -214,    64,  -214,   182,  -214,  -214,  -214,  -214,  1406,   968,
    -214,  1355,  1406,  1355,   239,   134,   160,   881,   271,  -214,
     134,  -214,   248,  -214,   134,   931,  1355,   968,   160,   -25,
    -214,  1406,    79,   160,  -214,  1253,  -214,   968,   249,  -214,
    -214,   160,  -214
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,  -214,  -214,   269,  -214,     4,  -214,    42,
      -7,   -24,  -214,  -175,   -29,   -84,   190,  -214,  -214,     0,
     208,  -214,    31,  -214,  -214,  -214,    28,  -214,    65,  -214,
    -149,  -214,  -214,  -148,  -143,  -214,  -214,  -214,  -214,    -8,
    -214,    73,  -214,  -176,    22,  -183,  -214,  -145,   -39,  -214,
    -214,  -214,   256,   196,  -214,  -214,  -214,  -214,  -213,  -214,
    -214,    68,  -214,  -214,  -214,   114,  -214,  -214,  -214,  -214,
    -214,    -5,     7,  -214,  -214,  -214,  -214,  -214,  -214,  -214
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -206
static const yytype_int16 yytable[] =
{
      59,    44,    97,    72,   162,   242,   276,   230,   278,    92,
     330,   -93,   178,   138,   259,    80,   212,   140,   135,    92,
     132,   209,   216,    87,   103,   217,    91,   190,   267,   296,
     135,   226,    93,   185,   239,     1,    59,   227,    98,    72,
     212,   255,    93,   260,   102,    93,     7,   258,   130,     6,
     105,   106,    10,   107,   108,   109,   110,   111,   112,   113,
     114,   137,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    15,   142,   137,    17,   124,   226,   283,   259,   210,
     162,   104,   227,   218,   125,   155,   166,   297,   165,   154,
     290,   -93,    11,   139,   134,    59,   272,   141,    72,   168,
     173,   175,   177,   135,   162,   255,   324,   135,   136,   230,
      12,   258,   136,   156,    12,     4,   294,   321,   332,   201,
     311,   284,   135,   212,    79,    12,   270,   348,   317,   166,
     288,   208,   350,   126,   167,    59,    82,    32,    72,    93,
     157,   158,   194,   325,    88,   196,   137,   198,   326,    38,
     137,   203,    94,   212,   204,   205,   206,   322,   207,   190,
     132,   233,   234,    42,   191,   137,    89,    91,   103,   161,
     305,    99,    95,   215,    96,    59,    59,   339,    72,    72,
     223,    20,   342,    22,   310,   200,   311,   270,   228,   223,
     100,   101,    20,   223,    22,   201,   244,   201,   223,   280,
     103,    20,   262,    22,   303,    20,   131,    22,   133,   143,
      20,    59,    22,    59,    72,    88,    72,   162,   246,   164,
     166,   180,   181,   274,   182,   173,   185,   246,   188,   279,
     189,   195,   247,   248,   197,   199,   128,   249,   250,   219,
     286,   247,   248,   222,   238,   229,   249,   250,   263,   271,
     310,   268,   273,    89,   277,   139,   282,   293,   167,   287,
     298,   200,   301,   200,   299,   300,   338,   334,   316,   152,
     307,   328,   308,   309,   341,   343,   351,    43,   163,    59,
     323,   292,    72,   152,   320,   304,   153,   152,   306,   319,
     281,   275,   302,   315,   152,   344,   127,   134,   152,   132,
     240,   327,     0,   289,     0,     0,     0,     0,     0,     0,
       0,   314,   132,    59,   336,    59,    72,     0,    72,     0,
       0,   201,     0,     0,     0,   335,   152,     0,    59,   337,
       0,    72,     0,     0,     0,     0,   167,    59,   152,     0,
      72,   329,   331,     0,     0,     0,     0,     0,   347,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,    17,
       0,     0,     0,     0,   152,     0,    83,     0,   340,   152,
       0,   152,     0,   152,    19,   193,     0,     0,     0,    84,
     346,    23,    24,    25,    26,   349,    27,   200,     0,     0,
     152,     0,   152,   352,   152,     0,     0,     0,    34,   152,
     152,   152,   152,   152,     0,     0,     0,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,     0,     0,     0,   105,
     106,     0,   107,   108,   109,   110,   144,   112,   113,   114,
     152,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      15,     0,   159,    17,   124,   145,   146,     0,   152,     0,
       0,     0,     0,   125,   147,   103,    15,    16,   148,    17,
     152,     0,     0,     0,     0,   152,    83,     0,     0,     0,
       0,   103,   152,     0,    19,     0,     0,     0,     0,    84,
       0,    23,    24,    25,    26,     0,    27,     0,     0,     0,
       0,     0,     0,   152,   152,   152,     0,     0,    34,     0,
     160,   149,   126,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   152,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   152,   107,   108,   109,   110,   144,   112,
     113,   114,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    15,     0,     0,    17,   124,   145,   146,     0,
       0,     0,     0,     0,     0,   125,   147,   103,     0,     0,
     148,   264,   265,   105,   106,   220,   107,   108,   109,   110,
     144,   112,   113,   114,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    15,     0,     0,    17,   124,   145,
     146,     0,     0,     0,     0,     0,     0,   125,   147,   103,
       0,     0,   148,   149,   126,   105,   106,     0,   107,   108,
     109,   110,   144,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    15,     0,   221,    17,
     124,   145,   146,     0,     0,     0,     0,     0,     0,   125,
     147,   103,     0,     0,   148,   149,   126,     0,     0,     0,
     105,   106,     0,   107,   108,   109,   110,   144,   112,   113,
     114,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    15,     0,     0,    17,   124,   145,   146,     0,     0,
       0,     0,     0,     0,   125,   147,   103,   149,   126,   148,
     261,     0,     0,     0,     0,   105,   106,     0,   107,   108,
     109,   110,   144,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    15,     0,     0,    17,
     124,   145,   146,     0,     0,     0,     0,     0,     0,   125,
     147,   103,   149,   126,   148,     0,   266,   105,   106,     0,
     107,   108,   109,   110,   144,   112,   113,   114,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    15,     0,
     295,    17,   124,   145,   146,     0,     0,     0,     0,     0,
       0,   125,   147,   103,     0,     0,   148,   149,   126,   105,
     106,     0,   107,   108,   109,   110,   144,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      15,     0,     0,    17,   124,   145,   146,     0,     0,     0,
       0,     0,     0,   125,   147,   103,     0,   318,   148,   149,
     126,     0,     0,     0,   105,   106,     0,   107,   108,   109,
     110,   144,   112,   113,   114,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    15,     0,     0,    17,   124,
     145,   146,     0,     0,     0,     0,     0,     0,   125,   147,
     103,   149,   126,   148,   333,   105,   106,     0,   107,   108,
     109,   110,   144,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    15,     0,     0,    17,
     124,   145,   146,     0,     0,     0,     0,     0,     0,   125,
     147,   103,     0,     0,   148,     0,   149,   126,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,   107,   108,
     109,   110,   144,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    15,     0,   345,    17,
     124,   145,   146,     0,     0,     0,  -205,   149,   126,   125,
     147,   103,   105,   106,   148,   107,   108,   109,   110,   144,
     112,   113,   114,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    15,     0,     0,    17,   124,   145,   146,
       0,     0,     0,     0,     0,     0,   125,   147,   103,     0,
       0,   148,     0,     0,     0,     0,     0,   149,   126,     0,
       0,     0,   105,   106,     0,   107,   108,   109,   110,   144,
     112,   113,   114,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    15,     0,     0,    17,   124,   145,   146,
       0,     0,     0,     0,   149,   126,   125,   147,   183,  -177,
    -177,   148,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
       0,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
       0,     0,     0,     0,  -177,  -177,  -177,     0,     0,     0,
       0,     0,     0,  -177,  -177,  -177,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   126,     0,     0,     0,  -186,
    -186,     0,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
       0,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
       0,     0,     0,     0,  -186,  -186,  -186,     0,     0,     0,
       0,  -177,  -177,  -186,  -186,  -186,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    15,     0,     0,    17,   124,
     145,   146,     0,     0,     0,     0,     0,     0,   125,   147,
     103,     0,     0,   148,     0,     0,    15,    16,     0,    17,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,  -186,  -186,     0,    19,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,    27,     0,    28,     0,
      29,    30,    31,    32,    33,     0,   149,   126,    34,     0,
      35,    36,    37,   233,   234,    38,    39,    15,    16,     0,
      17,    40,     0,    41,     0,     0,     0,    18,     0,    42,
       0,     0,     0,     0,     0,    19,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,    27,     0,    28,
       0,    29,    30,    31,    32,    33,     0,     0,     7,    34,
       0,    35,    36,    37,     0,     0,    38,    39,    15,    16,
       0,    17,    40,     0,    41,     0,     0,     0,    18,     0,
      42,     0,     0,   103,     0,     0,    19,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,    27,     0,
      28,     0,    29,    30,    31,    32,    33,     0,     0,     0,
      34,     0,    35,    36,    37,     0,     0,    38,    39,    15,
      16,     0,    17,    40,     0,    41,     0,     0,     0,    18,
       0,    42,     0,     0,     0,   237,     0,    19,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,    27,
       0,    28,     0,    29,    30,    31,    32,    33,     0,     0,
       0,    34,     0,    35,    36,    37,     0,     0,    38,    39,
      15,    16,     0,    17,    40,     0,    41,     0,     0,     0,
      18,     0,    42,     0,     0,     0,     0,     0,    19,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
      27,     0,    28,     0,    29,    30,    31,    32,    33,     0,
       0,     0,    34,     0,    35,    36,    37,     0,     0,    38,
      39,    15,    16,     0,    17,    40,     0,    41,     0,     0,
       0,    83,     0,    42,     0,     0,     0,     0,     0,    19,
       0,     0,    15,    16,    84,    17,    23,    24,    25,    26,
       0,    27,    83,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,    34,     0,   169,     0,    23,    24,    25,
      26,     0,    27,    15,    16,     0,    17,     0,     0,     0,
       0,     0,     0,    83,    34,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,   243,     0,    23,    24,
      25,    26,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34
};

static const yytype_int16 yycheck[] =
{
       8,     8,    31,     8,    88,   188,   219,   182,   221,     3,
      26,     5,    96,     5,   190,    11,   164,     5,    43,     3,
      44,    27,     3,    16,    40,    27,    19,    40,    27,    27,
      43,   180,    26,    76,    77,    65,    44,   180,    31,    44,
     188,   190,    26,   191,    37,    26,    66,   190,    41,     0,
       4,     5,     4,     7,     8,     9,    10,    11,    12,    13,
      14,    86,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    65,    86,    28,    29,   225,    41,   254,    85,
     164,    39,   225,    85,    38,    81,    85,    85,    44,    27,
     238,    85,    26,    85,    52,   103,    36,    85,   103,    92,
      93,    94,    95,    43,   188,   254,    48,    43,    48,   284,
      48,   254,    48,    21,    48,    48,     3,    45,   301,   143,
     268,    85,    43,   271,    48,    48,   210,    48,   273,    85,
      41,   160,   345,    87,    92,   143,     4,    62,   143,    26,
      48,    49,   135,    85,    26,   138,    86,   140,   293,    74,
      86,   144,    26,   301,   147,   148,   149,    85,   151,    40,
     184,    72,    73,    88,    45,    86,    48,   160,    40,    35,
      42,    48,    26,   166,    26,   183,   184,   325,   183,   184,
      35,    47,   330,    49,   268,   143,   334,   271,   181,    35,
      48,    48,    47,    35,    49,   219,   189,   221,    35,    41,
      40,    47,   195,    49,    41,    47,    49,    49,    49,    58,
      47,   219,    49,   221,   219,    26,   221,   301,    64,    26,
      85,    40,     3,   216,    40,   218,    76,    64,    26,   222,
      26,     3,    78,    79,    48,    48,    40,    83,    84,    27,
     233,    78,    79,    42,    26,    48,    83,    84,     3,    85,
     334,    45,    27,    48,    47,    85,     3,    27,   216,    45,
      45,   219,    26,   221,    48,    48,    27,    85,    48,    73,
     263,    48,   265,   266,     3,    27,    27,     8,    88,   287,
     287,   239,   287,    87,   284,   254,    78,    91,   260,   282,
     225,   218,   250,   271,    98,   334,    40,   255,   102,   323,
     186,   294,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,   336,   321,   321,   323,   321,    -1,   323,    -1,
      -1,   345,    -1,    -1,    -1,   318,   130,    -1,   336,   322,
      -1,   336,    -1,    -1,    -1,    -1,   294,   345,   142,    -1,
     345,   299,   300,    -1,    -1,    -1,    -1,    -1,   341,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,   168,    -1,    35,    -1,   326,   173,
      -1,   175,    -1,   177,    43,    44,    -1,    -1,    -1,    48,
     338,    50,    51,    52,    53,   343,    55,   345,    -1,    -1,
     194,    -1,   196,   351,   198,    -1,    -1,    -1,    67,   203,
     204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
     244,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,   262,    -1,
      -1,    -1,    -1,    38,    39,    40,    25,    26,    43,    28,
     274,    -1,    -1,    -1,    -1,   279,    35,    -1,    -1,    -1,
      -1,    40,   286,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,   307,   308,   309,    -1,    -1,    67,    -1,
      85,    86,    87,    -1,    -1,   319,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   335,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,   347,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      43,    44,    45,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    43,    86,    87,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    43,    86,    87,    -1,    -1,    -1,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    86,    87,    43,
      44,    -1,    -1,    -1,    -1,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    86,    87,    43,    -1,    45,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    43,    86,    87,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    -1,    42,    43,    86,
      87,    -1,    -1,    -1,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    86,    87,    43,    44,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    43,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    85,    86,    87,    38,
      39,    40,     4,     5,    43,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    86,    87,    38,    39,    40,     4,
       5,    43,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    86,    87,    38,    39,    40,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    43,    -1,    -1,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    86,    87,    -1,    43,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    -1,    86,    87,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    25,    26,    -1,
      28,    80,    -1,    82,    -1,    -1,    -1,    35,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    57,
      -1,    59,    60,    61,    62,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    71,    -1,    -1,    74,    75,    25,    26,
      -1,    28,    80,    -1,    82,    -1,    -1,    -1,    35,    -1,
      88,    -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      57,    -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    25,
      26,    -1,    28,    80,    -1,    82,    -1,    -1,    -1,    35,
      -1,    88,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      -1,    57,    -1,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      25,    26,    -1,    28,    80,    -1,    82,    -1,    -1,    -1,
      35,    -1,    88,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    57,    -1,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    74,
      75,    25,    26,    -1,    28,    80,    -1,    82,    -1,    -1,
      -1,    35,    -1,    88,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    25,    26,    48,    28,    50,    51,    52,    53,
      -1,    55,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    67,    -1,    48,    -1,    50,    51,    52,
      53,    -1,    55,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67
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
     131,   132,   135,   139,   140,   142,   144,   145,   148,   152,
     157,   158,   160,   161,   163,   164,   165,   166,   167,    48,
      96,    97,     4,    35,    48,   128,   160,   161,    26,    48,
     103,   161,     3,    26,    26,    26,    26,   103,   161,    48,
      48,    48,   161,    40,    98,     4,     5,     7,     8,     9,
      10,    11,    12,    13,    14,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    29,    38,    87,   141,   142,   143,
     161,    49,   100,    49,    98,    43,    48,    86,     5,    85,
       5,    85,   161,    58,    11,    30,    31,    39,    43,    86,
      98,   141,   142,   109,    27,    96,    21,    48,    49,    27,
      85,    35,   104,   105,    26,    44,    85,    98,   161,    48,
     102,   129,   130,   161,   146,   161,   162,   161,   104,   159,
      40,     3,    40,    40,    99,    76,   153,   154,    26,    26,
      40,    45,   115,    44,   161,     3,   161,    48,   161,    48,
      98,   100,   147,   161,   161,   161,   161,   161,   103,    27,
      85,   105,   122,   133,   134,   161,     3,    27,    85,    27,
       6,    27,    42,    35,   117,   118,   119,   123,   161,    48,
     102,   107,   108,    72,    73,   149,   150,    41,    26,    77,
     154,   156,   134,    48,   161,   168,    64,    78,    79,    83,
      84,   111,   112,   113,   114,   119,   120,   121,   123,   132,
     122,    44,   161,     3,    44,    45,    45,    27,    45,   136,
     104,    85,    36,    27,   161,   130,   147,    47,   147,   161,
      41,   117,     3,    41,    85,   151,   161,    45,    41,   150,
     122,   155,    98,    27,     3,    27,    27,    85,    45,    48,
      48,    26,    98,    41,   111,    42,   115,   161,   161,   161,
     104,   122,   137,   138,    98,   133,    48,   136,    42,   161,
     108,    45,    85,    99,    48,    85,   136,   161,    48,    98,
      26,    98,   134,    44,    85,   161,    99,   161,    27,   122,
      98,     3,   122,    27,   137,    27,    98,   161,    48,    98,
     147,    27,    98
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

  case 21:

/* Line 1455 of yacc.c  */
#line 113 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 114 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 115 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 116 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 117 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 118 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 119 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 120 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 121 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 122 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 123 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 124 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 125 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 126 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 127 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 128 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 129 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 130 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 134 "lex\\silang.yxx"
    { (yyval.expr)=makeConst((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].expr)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 137 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 142 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 147 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (2)].tp), (yyvsp[(2) - (2)].str)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 148 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (4)].tp), (yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 153 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 159 "lex\\silang.yxx"
    { (yyval.expr)=createEnum((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 164 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 170 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str),nullptr); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 178 "lex\\silang.yxx"
    { (yyval.expr)=makeClass((yyvsp[(1) - (3)].type),(yyvsp[(2) - (3)].str), nullptr, (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 180 "lex\\silang.yxx"
    { (yyval.expr)=makeClass((yyvsp[(1) - (5)].type),(yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].tp), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 181 "lex\\silang.yxx"
    { (yyval.expr)=annotationdClass((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 185 "lex\\silang.yxx"
    { (yyval.type)=0; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 186 "lex\\silang.yxx"
    { (yyval.type)=1; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 197 "lex\\silang.yxx"
    { (yyval.expr)=setProtected(); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 203 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(2, ":init", (yyvsp[(3) - (5)].expr), nullptr, (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 208 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(3, ":finalize", nullptr, nullptr, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 213 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 216 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 224 "lex\\silang.yxx"
    { (yyval.tp)=createInterface((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 228 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 229 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 234 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 239 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(0, (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].expr), (yyvsp[(6) - (6)].expr), nullptr); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 246 "lex\\silang.yxx"
    { (yyval.expr)=makeGet((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 250 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].tp), (yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 251 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (3)].str), nullptr, nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 262 "lex\\silang.yxx"
    { (yyval.tp)=getClassType((yyvsp[(1) - (1)].str)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 263 "lex\\silang.yxx"
    { (yyval.tp)=getType((yyvsp[(1) - (1)].type)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 264 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (3)].tp)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 265 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (4)].tp),(yyvsp[(3) - (4)].expr)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 266 "lex\\silang.yxx"
    { (yyval.tp)=getFuncType(); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 267 "lex\\silang.yxx"
    { (yyval.tp)=nullAble((yyvsp[(1) - (2)].tp)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 272 "lex\\silang.yxx"
    { (yyval.expr)=createDef((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 273 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 274 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 278 "lex\\silang.yxx"
    { (yyval.expr)=makeSequence( (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 286 "lex\\silang.yxx"
    { (yyval.expr)=makeTuple((yyvsp[(4) - (5)].expr), (yyvsp[(2) - (5)].expr)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 290 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 291 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 295 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 296 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 303 "lex\\silang.yxx"
    { (yyval.expr)=makeCall((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 307 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 309 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 321 "lex\\silang.yxx"
    { (yyval.expr)=makeDelete((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 329 "lex\\silang.yxx"
    { (yyval.expr)=addFunctionBlock((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 334 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].str), nullptr, 1); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 339 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 341 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 351 "lex\\silang.yxx"
    { (yyval.expr)=createOperator((yyvsp[(2) - (7)].type), (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 355 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 356 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 361 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 366 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 371 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(6, "", (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 376 "lex\\silang.yxx"
    { (yyval.expr)=callReturn(); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 377 "lex\\silang.yxx"
    { (yyval.expr)=callReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 378 "lex\\silang.yxx"
    { (yyval.expr)=callReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 383 "lex\\silang.yxx"
    { (yyval.type)='+'; ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 384 "lex\\silang.yxx"
    { (yyval.type)='-'; ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 385 "lex\\silang.yxx"
    { (yyval.type)='*'; ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 386 "lex\\silang.yxx"
    { (yyval.type)='/'; ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 387 "lex\\silang.yxx"
    { (yyval.type)='&'; ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 388 "lex\\silang.yxx"
    { (yyval.type)='|'; ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 389 "lex\\silang.yxx"
    { (yyval.type)='!'; ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 390 "lex\\silang.yxx"
    { (yyval.type)='<'; ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 391 "lex\\silang.yxx"
    { (yyval.type)='>'; ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 392 "lex\\silang.yxx"
    { (yyval.type)='%'; ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 393 "lex\\silang.yxx"
    { (yyval.type)='.'; ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 394 "lex\\silang.yxx"
    { (yyval.type)=LEFTMOVE; ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 395 "lex\\silang.yxx"
    { (yyval.type)=RIGHTMOVE; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 396 "lex\\silang.yxx"
    { (yyval.type)=URIGHTMOVE; ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 397 "lex\\silang.yxx"
    { (yyval.type)=LEQ; ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 398 "lex\\silang.yxx"
    { (yyval.type)=REQ; ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 399 "lex\\silang.yxx"
    { (yyval.type)=RGO; ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 400 "lex\\silang.yxx"
    { (yyval.type)=EQ; ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 401 "lex\\silang.yxx"
    { (yyval.type)=AEQ; ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 402 "lex\\silang.yxx"
    { (yyval.type)=NOEQ; ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 403 "lex\\silang.yxx"
    { (yyval.type)=OR; ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 404 "lex\\silang.yxx"
    { (yyval.type)=AND; ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 408 "lex\\silang.yxx"
    { (yyval.type)='^'; ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 409 "lex\\silang.yxx"
    { (yyval.type)='~'; ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 422 "lex\\silang.yxx"
    { (yyval.expr)=makeIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 426 "lex\\silang.yxx"
    { (yyval.expr)=setElse((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 443 "lex\\silang.yxx"
    { (yyval.expr)=createSwitch((yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 448 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 452 "lex\\silang.yxx"
    { (yyval.expr)=createCase((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 453 "lex\\silang.yxx"
    { (yyval.expr)=createCase(nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 458 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 465 "lex\\silang.yxx"
    { (yyval.expr)=createTry( (yyvsp[(2) - (4)].expr), (yyvsp[(3) - (4)].expr), (yyvsp[(4) - (4)].expr) ); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 469 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 471 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 475 "lex\\silang.yxx"
    { (yyval.expr)=makeCatch((yyvsp[(3) - (6)].expr), (yyvsp[(4) - (6)].str), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 479 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 480 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),let((yyvsp[(3) - (3)].tp))); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 484 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 485 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 493 "lex\\silang.yxx"
    { (yyval.expr)=makeWhile((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 497 "lex\\silang.yxx"
    { (yyval.expr)=makeFor( (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].expr)); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 507 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 508 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 520 "lex\\silang.yxx"
    { (yyval.expr)=makeNull(); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 521 "lex\\silang.yxx"
    { (yyval.expr)=getVar((yyvsp[(1) - (1)].str)); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 522 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 523 "lex\\silang.yxx"
    { (yyval.expr)=binary((yyvsp[(2) - (3)].type), (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 524 "lex\\silang.yxx"
    { (yyval.expr)=binary('<', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 525 "lex\\silang.yxx"
    { (yyval.expr)=unary((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 526 "lex\\silang.yxx"
    { (yyval.expr)=unaryAfter((yyvsp[(2) - (2)].type), (yyvsp[(1) - (2)].expr)); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 531 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 532 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr), false); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 533 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF(makeIsNull((yyvsp[(1) - (3)].expr)), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 534 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 538 "lex\\silang.yxx"
    { (yyval.expr)=binaryIs((yyvsp[(1) - (3)].expr), getType((yyvsp[(3) - (3)].type)));  ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 555 "lex\\silang.yxx"
    { (yyval.expr)=makeSplice((yyvsp[(1) - (6)].expr), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr)); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 563 "lex\\silang.yxx"
    { (yyval.expr)=makeIndex((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 572 "lex\\silang.yxx"
    { (yyval.expr)=makeBased((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 578 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 579 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 583 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 584 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (5)].expr), let((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].expr))); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3057 "intermediate/silang.tab.cpp"
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
#line 587 "lex\\silang.yxx"


