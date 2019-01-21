
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
#define YYLAST   1594

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNRULES -- Number of states.  */
#define YYNSTATES  366

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
      23,    26,    31,    33,    37,    41,    45,    49,    51,    54,
      58,    60,    63,    65,    67,    69,    71,    73,    75,    77,
      79,    81,    83,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   106,   110,   112,   116,   119,   124,   126,   130,
     136,   138,   142,   146,   148,   152,   158,   161,   163,   165,
     167,   169,   171,   173,   175,   177,   179,   182,   188,   191,
     193,   196,   200,   201,   207,   209,   211,   213,   216,   223,
     227,   235,   239,   241,   243,   247,   252,   254,   257,   259,
     263,   269,   273,   279,   283,   288,   290,   294,   299,   300,
     302,   306,   308,   310,   316,   319,   322,   323,   325,   329,
     330,   332,   336,   338,   346,   347,   350,   352,   354,   356,
     360,   367,   369,   372,   374,   376,   378,   380,   382,   384,
     386,   388,   390,   392,   394,   396,   398,   400,   402,   404,
     406,   408,   410,   412,   414,   416,   418,   420,   422,   424,
     430,   434,   436,   438,   440,   442,   444,   450,   452,   455,
     460,   464,   466,   470,   475,   476,   478,   481,   488,   490,
     494,   495,   498,   504,   514,   515,   517,   521,   525,   527,
     529,   531,   533,   535,   537,   539,   543,   547,   550,   553,
     555,   557,   559,   561,   564,   567,   571,   577,   581,   585,
     590,   594,   596,   598,   600,   602,   604,   611,   616,   619,
     625,   631,   635
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,    92,    93,    99,    -1,    48,    -1,    91,
       4,    48,    -1,    65,    91,    -1,    -1,    94,    -1,    93,
      94,    -1,    -1,    66,    96,    -1,    66,    26,    97,    27,
      -1,    48,    -1,    95,     4,    48,    -1,    95,     4,    21,
      -1,    95,     4,    49,    -1,    95,     4,    48,    -1,    96,
      -1,    97,    96,    -1,    40,    99,    41,    -1,   100,    -1,
      99,   100,    -1,   123,    -1,   109,    -1,   116,    -1,   126,
      -1,   128,    -1,   162,    -1,   163,    -1,   142,    -1,   160,
      -1,   159,    -1,   147,    -1,   133,    -1,   101,    -1,   106,
      -1,   150,    -1,   154,    -1,   132,    -1,   137,    -1,   131,
      -1,    69,    48,     3,   163,    -1,    48,     3,   163,    -1,
     163,    -1,   103,    85,   163,    -1,   122,    48,    -1,   122,
      48,     3,   163,    -1,   104,    -1,   105,    85,   104,    -1,
      70,    49,    40,   107,    41,    -1,   108,    -1,   107,    85,
     108,    -1,    49,     3,   163,    -1,    49,    -1,   110,    49,
     115,    -1,   110,    49,    45,   122,   115,    -1,   169,   109,
      -1,    62,    -1,    74,    -1,   123,    -1,   120,    -1,   121,
      -1,   112,    -1,   113,    -1,   101,    -1,   133,    -1,    64,
      45,    -1,    83,    26,   136,    27,   134,    -1,    84,   134,
      -1,   111,    -1,   114,   111,    -1,    40,   114,    41,    -1,
      -1,    63,    48,    40,   118,    41,    -1,   123,    -1,   119,
      -1,   117,    -1,   118,   117,    -1,    35,    48,    26,   136,
      27,   138,    -1,    78,    48,    98,    -1,    79,    48,    26,
     122,    48,    27,    98,    -1,    79,    48,    98,    -1,    49,
      -1,    47,    -1,   122,    43,    44,    -1,   122,    43,   163,
      44,    -1,    35,    -1,   122,    86,    -1,   104,    -1,   123,
      85,    48,    -1,   123,    85,    48,     3,   163,    -1,    43,
     103,    44,    -1,    26,   163,    85,   103,    27,    -1,   127,
       5,   163,    -1,    47,   127,     5,   163,    -1,    48,    -1,
     127,    85,    48,    -1,    48,    26,   129,    27,    -1,    -1,
     130,    -1,   129,    85,   130,    -1,   163,    -1,   102,    -1,
     122,    48,    26,   129,    27,    -1,    82,   163,    -1,   119,
     134,    -1,    -1,    98,    -1,   122,    36,    48,    -1,    -1,
     105,    -1,   105,    85,   135,    -1,   135,    -1,    80,   145,
      26,   136,    27,   138,    98,    -1,    -1,    45,   140,    -1,
     104,    -1,   122,    -1,   139,    -1,   140,    85,   139,    -1,
      35,    26,   105,    27,   138,    98,    -1,    61,    -1,    61,
     103,    -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    29,    -1,    11,    -1,    12,    -1,
      87,    -1,     4,    -1,    18,    -1,    17,    -1,    16,    -1,
      14,    -1,    13,    -1,    38,    -1,    10,    -1,     5,    -1,
       9,    -1,     8,    -1,     7,    -1,    25,    -1,    28,    -1,
     143,    -1,   144,    -1,    57,    26,   148,    27,   149,    -1,
     146,    58,   149,    -1,   146,    -1,   163,    -1,   164,    -1,
     100,    -1,    98,    -1,    71,   163,    40,   151,    41,    -1,
     152,    -1,   151,   152,    -1,    72,   153,    45,    99,    -1,
      73,    45,    99,    -1,   163,    -1,   153,    85,   163,    -1,
      75,    98,   155,   158,    -1,    -1,   156,    -1,   155,   156,
      -1,    76,    26,   157,    48,    27,    98,    -1,   122,    -1,
     157,    85,   122,    -1,    -1,    77,    98,    -1,    59,    26,
     163,    27,   149,    -1,    60,    26,   161,    42,   163,    42,
     163,    27,   149,    -1,    -1,   104,    -1,    48,     3,   163,
      -1,    48,     3,    98,    -1,   165,    -1,   124,    -1,   141,
      -1,   128,    -1,   125,    -1,    67,    -1,    48,    -1,    26,
     163,    27,    -1,   163,   143,   163,    -1,   144,   163,    -1,
     163,   144,    -1,   162,    -1,   166,    -1,   167,    -1,   168,
      -1,   163,    31,    -1,   163,    30,    -1,   163,    39,   163,
      -1,   163,    86,   163,    45,   163,    -1,    49,     4,    48,
      -1,    49,     4,    49,    -1,   122,    26,   129,    27,    -1,
     163,     6,    47,    -1,    50,    -1,    51,    -1,    52,    -1,
      53,    -1,    55,    -1,   163,    43,   163,    45,   163,    44,
      -1,   163,    43,   163,    44,    -1,   163,    98,    -1,    88,
      49,    26,   163,    27,    -1,    88,    49,    26,   170,    27,
      -1,    48,     3,   163,    -1,   170,    85,    48,     3,   163,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    61,    62,    66,    67,    78,    79,    82,
      84,    85,    89,    90,    94,    95,    96,   100,   101,   105,
     109,   110,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   136,   139,   143,   144,   149,   150,   154,   155,   161,
     165,   166,   170,   171,   178,   180,   182,   186,   187,   191,
     192,   193,   194,   195,   196,   197,   198,   203,   208,   213,
     214,   217,   218,   225,   229,   230,   234,   235,   239,   247,
     251,   252,   263,   264,   265,   266,   267,   268,   272,   273,
     274,   278,   286,   290,   291,   295,   296,   303,   307,   308,
     309,   313,   314,   322,   326,   334,   338,   339,   344,   349,
     350,   351,   352,   360,   365,   366,   370,   371,   375,   376,
     380,   386,   387,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   417,   418,   422,   423,   431,
     435,   436,   440,   441,   445,   446,   450,   456,   457,   461,
     462,   466,   467,   474,   478,   479,   480,   484,   488,   489,
     493,   494,   502,   505,   509,   511,   516,   517,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     549,   553,   554,   555,   556,   557,   566,   574,   583,   589,
     590,   594,   595
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
  "object_delete", "function", "block_or_none", "function_variable",
  "function_parameters", "operator_overload", "function_ret",
  "return_tuple_elem", "return_tuple_elems", "lambda", "rtn",
  "operator_binary", "operator_unary", "operator", "if_cond", "if_else",
  "if_expr", "block_or_line", "switch", "cases", "case", "case_exprs",
  "try", "try_catchs", "try_catch", "try_types", "try_finally",
  "while_loop", "for_loop", "for_line", "assignment", "expr", "type_expr",
  "expr_value", "splice", "index", "object_block", "annotation",
  "annotation_list", 0
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
      94,    94,    95,    95,    96,    96,    96,    97,    97,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   102,   103,   103,   104,   104,   105,   105,   106,
     107,   107,   108,   108,   109,   109,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   111,   112,   113,   114,
     114,   115,   115,   116,   117,   117,   118,   118,   119,   120,
     121,   121,   122,   122,   122,   122,   122,   122,   123,   123,
     123,   124,   125,   126,   126,   127,   127,   128,   129,   129,
     129,   130,   130,   131,   132,   133,   134,   134,   135,   136,
     136,   136,   136,   137,   138,   138,   139,   139,   140,   140,
     141,   142,   142,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   144,   144,   145,   145,   146,
     147,   147,   148,   148,   149,   149,   150,   151,   151,   152,
     152,   153,   153,   154,   155,   155,   155,   156,   157,   157,
     158,   158,   159,   160,   161,   161,   162,   162,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     164,   165,   165,   165,   165,   165,   166,   167,   168,   169,
     169,   170,   170
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     3,     2,     0,     1,     2,     0,
       2,     4,     1,     3,     3,     3,     3,     1,     2,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     1,     3,     2,     4,     1,     3,     5,
       1,     3,     3,     1,     3,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     2,     1,
       2,     3,     0,     5,     1,     1,     1,     2,     6,     3,
       7,     3,     1,     1,     3,     4,     1,     2,     1,     3,
       5,     3,     5,     3,     4,     1,     3,     4,     0,     1,
       3,     1,     1,     5,     2,     2,     0,     1,     3,     0,
       1,     3,     1,     7,     0,     2,     1,     1,     1,     3,
       6,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     1,     1,     1,     1,     1,     5,     1,     2,     4,
       3,     1,     3,     4,     0,     1,     2,     6,     1,     3,
       0,     2,     5,     9,     0,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     2,     1,
       1,     1,     1,     2,     2,     3,     5,     3,     3,     4,
       3,     1,     1,     1,     1,     1,     6,     4,     2,     5,
       5,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     9,     3,     5,     1,     0,     0,     7,
       0,     0,    12,     0,    10,   145,     0,   146,    86,     0,
      83,   184,    82,   201,   202,   203,   204,   205,     0,     0,
       0,   121,    57,     0,   183,     0,     0,     0,    58,     0,
       0,     0,     0,     8,     2,    20,    34,    88,    35,    23,
       0,    24,   106,     0,    22,   179,   182,    25,     0,    26,
      40,    38,    33,    39,   180,    29,     0,   151,    32,    36,
      37,    31,    30,    27,    28,   178,   190,   191,   192,     0,
       4,    17,     0,     0,    86,    83,   184,     0,   181,   189,
       0,     0,     0,     0,    43,    95,     0,     0,    98,     0,
       0,     0,   174,   122,     0,     0,     0,     0,     0,   164,
     133,   141,   144,   143,   142,   140,   130,   131,   138,   137,
     136,   135,   134,   123,   124,   125,   126,   127,   128,   129,
     139,   132,   147,   148,     0,   104,     0,    21,    72,   107,
     105,    98,     0,    45,    87,     0,     0,     0,   187,     0,
     194,   193,     0,     0,     0,   208,     0,   188,    56,    11,
      18,    14,    16,    15,   185,     0,    86,    82,    47,     0,
       0,   109,    91,     0,     0,   177,   176,   184,   102,     0,
      99,   101,   197,   198,     0,   152,   153,     0,   175,     0,
       0,     0,     0,     0,     0,     0,   170,   165,   109,     0,
       0,     0,    54,     0,    84,     0,     0,    98,    89,    93,
      96,   155,   154,   150,   195,     0,     0,   186,     0,   114,
       0,    45,   110,     0,   112,     0,    44,    94,     0,    97,
       0,     0,     0,     0,     0,    86,    76,     0,    75,    74,
      41,    53,     0,    50,     0,     0,     0,   157,    19,     0,
       0,   166,   163,     0,   184,     0,     0,     0,     0,     0,
       0,   106,    64,    69,    62,    63,     0,    60,    61,    59,
      65,    72,   199,    85,    46,     0,     0,   207,     0,     0,
      92,     0,     0,    48,     0,     0,   114,    42,   100,   149,
     200,   172,     0,    73,    77,     0,    49,     0,     0,   161,
       0,   156,   158,   168,     0,   171,   114,     0,   209,   210,
       0,    66,     0,     0,   109,    68,    71,    70,    55,   103,
      90,     0,   196,   116,   117,   118,   115,   120,   111,   108,
      78,     0,    52,    51,     0,     0,   160,     0,     0,     0,
     176,     0,    79,     0,    81,     0,   206,     0,     0,   159,
     162,     0,   169,   113,     0,     0,   106,   119,     0,   167,
     212,     0,    67,   173,     0,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     3,     8,     9,    13,    14,    82,   155,
     194,    45,    46,   178,    93,    47,   222,    48,   242,   243,
      49,    50,   263,   264,   265,   266,   202,    51,   236,   237,
      52,   267,   268,    87,    54,    55,    56,    57,    58,    88,
     179,   180,    60,    61,    62,   140,   224,   225,    63,   282,
     325,   326,    64,    65,   156,    66,   134,    67,    68,   184,
     213,    69,   246,   247,   298,    70,   196,   197,   304,   252,
      71,    72,   189,    89,    74,   186,    75,    76,    77,    78,
      79,   256
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -256
static const yytype_int16 yypact[] =
{
     -32,   -11,    43,    53,  -256,   167,  -256,   132,  1292,  -256,
     124,   125,  -256,   170,  -256,  -256,   582,  -256,   133,   582,
     135,     8,   187,  -256,  -256,  -256,  -256,  -256,   172,   175,
     176,   582,  -256,   155,  -256,   156,   157,   582,  -256,   168,
    1286,   582,   160,  -256,  1445,  -256,  -256,  -256,  -256,  -256,
     161,  -256,   168,    29,   131,  -256,  -256,  -256,     3,    40,
    -256,  -256,  -256,  -256,  -256,  -256,   582,   159,  -256,  -256,
    -256,  -256,  -256,  1239,  1152,  -256,  -256,  -256,  -256,    54,
    -256,  -256,   -13,   108,   189,  -256,   111,    -1,  -256,  -256,
     676,   130,   192,   -18,  1152,  -256,     7,   383,  1496,   113,
     582,   582,   130,   134,   180,   218,   182,  1202,  1445,   148,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,   204,  1152,   206,  -256,    85,  -256,
    -256,  1496,   428,   140,  -256,   188,   582,   190,  1152,  1343,
    -256,  -256,   582,   582,   582,  -256,   582,  -256,  -256,  -256,
    -256,  -256,   233,  -256,  -256,   582,  -256,  -256,  -256,   -10,
     -21,   130,  -256,   582,   582,  -256,  1152,   143,  -256,     1,
    -256,  1152,  -256,  -256,   212,   763,  -256,   800,  -256,   198,
     164,   582,   193,   531,  1394,   217,   -46,  -256,   130,  1527,
     220,   130,  -256,    11,  -256,   850,   582,  1496,   241,  1152,
    -256,  -256,  -256,  -256,  1152,   713,   895,  1152,    13,   200,
     130,   244,   163,    61,  -256,   222,  1152,  1152,   383,  -256,
    1496,  1343,   203,  1343,   582,   205,  -256,   129,  -256,   131,
    1152,   248,    -9,  -256,   582,   209,    66,  -256,  -256,   130,
     168,  -256,  -256,   230,   149,   937,    14,   214,   213,   216,
     236,   168,  -256,  -256,  -256,  -256,    71,  -256,  -256,   131,
    -256,    62,  -256,  -256,  1152,    46,   582,  -256,   582,   582,
    -256,   130,   168,  -256,   130,   223,   200,  1152,  -256,  -256,
    -256,  -256,   979,  -256,  -256,   582,  -256,   193,    68,  1152,
    1445,  -256,  -256,    38,    60,  -256,   200,   383,  -256,  -256,
     224,  -256,   168,   174,   130,  -256,  -256,  -256,  -256,  -256,
    1152,  1024,  1152,  -256,   -21,  -256,   185,  -256,  -256,  -256,
    -256,   582,  1152,  -256,  1445,   582,  1445,   238,   130,   168,
    1065,   271,  -256,   130,  -256,   250,  -256,   130,  1115,  1445,
    1152,   168,    38,  -256,   582,    74,   168,  -256,  1343,  -256,
    1152,   251,  -256,  -256,   168,  -256
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,  -256,  -256,  -256,   267,  -256,     9,  -256,    35,
      -7,   -26,  -184,  -256,   -29,   -87,   191,  -256,  -256,   -17,
     207,  -256,    17,  -256,  -256,  -256,    16,  -256,    42,  -256,
    -169,  -256,  -256,    -8,  -171,  -256,  -256,  -256,   268,    -5,
    -118,    64,  -256,  -256,  -176,  -255,     6,  -193,  -256,  -119,
     -56,  -256,  -256,  -256,   257,   322,  -256,  -256,  -256,  -256,
    -224,  -256,  -256,    55,  -256,  -256,  -256,   104,  -256,  -256,
    -256,  -256,  -256,     2,   215,  -256,  -256,  -256,  -256,  -256,
    -256,  -256
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -212
static const yytype_int16 yytable[] =
{
      53,    44,   103,    59,   168,   253,   315,   289,   146,   291,
      73,    97,   174,   -95,   159,   188,   262,   219,   137,   239,
      81,   238,   142,   203,   270,   141,   172,   221,   229,   269,
     195,   250,   296,     1,    98,    12,    53,     4,   272,    59,
     280,   309,   142,     6,  -181,  -181,    73,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,   141,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,   144,   239,   173,   238,  -181,
    -181,  -181,   142,   319,   109,   220,   297,   143,  -181,  -181,
    -181,   142,   262,   170,   168,   144,   230,   139,   147,   275,
     270,   160,   147,   -95,   170,   269,   230,   285,   173,   310,
      53,   362,   200,    59,   142,   142,   235,   301,   337,   221,
      73,   168,   316,   334,    97,   144,    32,   142,    85,     7,
     167,   345,   361,   212,   144,   200,  -181,  -181,    38,   161,
     201,   230,   175,   283,   363,   257,   218,    98,   244,   245,
      35,    53,    42,   206,    59,   338,   228,   144,   144,   258,
     259,    73,   307,   335,   260,   261,   162,   163,    11,    91,
     144,   182,   183,   223,   235,   166,   207,   330,   137,    98,
     293,    10,    80,    12,    83,    98,    85,    85,   167,   167,
      12,    92,   170,    95,   211,    53,    53,   339,    59,    59,
     223,    99,   170,   271,   323,    73,    73,   283,   100,   235,
     343,   101,   102,   104,   105,   212,   106,   212,   108,   136,
     138,    85,   170,   167,   108,    91,   145,   149,   171,   173,
     190,   191,   192,    53,   195,    53,    59,   168,    59,   170,
     198,    90,   199,    73,    94,    73,   208,   -13,   210,   231,
     234,   303,   241,   249,   276,   281,    94,   206,   284,   286,
     290,   295,   107,    92,   300,   235,   135,   306,   170,   311,
     323,   312,   314,   175,   313,   351,   211,    85,   211,   167,
     347,   329,   341,   324,   354,    43,   223,   356,   364,   294,
     333,   148,   169,   317,   257,   305,   158,   318,    96,    35,
     328,   357,    53,   336,   288,    59,   139,   132,   258,   259,
     251,   302,    73,   260,   261,     0,   223,     0,     0,     0,
     137,     0,   176,   181,     0,   185,   187,   327,     0,     0,
       0,     0,     0,   137,     0,     0,    53,   349,    53,    59,
     352,    59,   212,     0,     0,   355,    73,     0,    73,   324,
       0,    53,   175,     0,    59,     0,     0,   342,   344,     0,
      53,    73,     0,    59,     0,     0,   181,   205,     0,     0,
      73,   209,   133,     0,     0,     0,     0,   214,   215,   216,
       0,   217,     0,     0,   353,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,   359,     0,   226,   227,
       0,   139,     0,   211,     0,     0,   157,     0,     0,   365,
       0,     0,     0,     0,     0,     0,   240,     0,    15,    16,
       0,    17,   157,     0,   255,     0,   157,     0,    84,     0,
       0,   274,   181,   108,     0,     0,    19,     0,     0,   157,
      85,    86,    22,    23,    24,    25,    26,     0,    27,     0,
       0,     0,     0,   287,     0,   181,     0,     0,     0,   292,
      34,     0,     0,    15,    16,     0,    17,   157,     0,   299,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
     157,    19,   204,     0,     0,    85,    86,    22,    23,    24,
      25,    26,     0,    27,     0,     0,     0,     0,     0,     0,
       0,   320,     0,   321,   322,    34,     0,     0,   157,     0,
       0,     0,     0,   157,     0,     0,     0,   157,     0,   157,
     332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   340,     0,     0,     0,     0,   157,     0,     0,
       0,   157,     0,     0,     0,     0,   157,   157,   157,   157,
       0,     0,     0,     0,     0,     0,   348,     0,   157,   157,
     350,     0,     0,     0,     0,     0,    15,    16,     0,    17,
       0,     0,   157,     0,     0,     0,    18,     0,     0,   360,
       0,     0,     0,     0,    19,     0,     0,   157,    20,    21,
      22,    23,    24,    25,    26,     0,    27,     0,    28,     0,
      29,    30,    31,    32,    33,     0,   157,     0,    34,     0,
      35,    36,    37,   244,   245,    38,    39,    15,    16,   157,
      17,    40,     0,    41,   157,     0,     0,    84,     0,    42,
       0,   157,     0,     0,     0,    19,     0,     0,     0,    85,
      86,    22,    23,    24,    25,    26,     0,    27,     0,     0,
       0,     0,   157,   157,   157,     0,     0,     0,     0,    34,
       0,     0,     0,     0,   157,     0,     0,     0,     0,     0,
       0,     0,   157,     0,     0,     0,     0,     0,     0,     0,
     157,     0,   157,     0,     0,     0,     0,     0,     0,     0,
     110,   111,   157,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    15,     0,   164,    17,   129,   150,   151,     0,     0,
       0,     0,     0,     0,   130,   152,   108,   110,   111,   153,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    15,     0,
       0,    17,   129,   150,   151,     0,     0,     0,     0,     0,
       0,   130,   152,   108,     0,     0,   153,   277,   278,     0,
       0,   165,   154,   131,     0,     0,     0,   110,   111,   232,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    15,     0,
       0,    17,   129,   150,   151,     0,     0,     0,     0,   154,
     131,   130,   152,   108,   110,   111,   153,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    15,     0,   233,    17,   129,
     150,   151,     0,     0,     0,     0,     0,     0,   130,   152,
     108,     0,     0,   153,     0,     0,     0,     0,     0,   154,
     131,     0,     0,     0,   110,   111,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    15,     0,     0,    17,   129,
     150,   151,     0,     0,     0,     0,   154,   131,   130,   152,
     108,     0,     0,   153,   273,     0,     0,     0,     0,   110,
     111,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      15,     0,     0,    17,   129,   150,   151,     0,     0,     0,
       0,     0,     0,   130,   152,   108,   154,   131,   153,     0,
     279,   110,   111,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    15,     0,   308,    17,   129,   150,   151,     0,
       0,     0,     0,     0,     0,   130,   152,   108,     0,     0,
     153,   154,   131,   110,   111,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    15,     0,     0,    17,   129,   150,
     151,     0,     0,     0,     0,     0,     0,   130,   152,   108,
       0,   331,   153,   154,   131,     0,     0,     0,   110,   111,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    15,
       0,     0,    17,   129,   150,   151,     0,     0,     0,     0,
       0,     0,   130,   152,   108,   154,   131,   153,   346,   110,
     111,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      15,     0,     0,    17,   129,   150,   151,     0,     0,     0,
       0,     0,     0,   130,   152,   108,     0,     0,   153,     0,
     154,   131,     0,     0,     0,     0,     0,     0,     0,   110,
     111,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      15,     0,   358,    17,   129,   150,   151,     0,     0,     0,
    -211,   154,   131,   130,   152,   108,   110,   111,   153,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    15,     0,     0,
      17,   129,   150,   151,     0,     0,     0,     0,     0,     0,
     130,   152,   108,     0,     0,   153,     0,     0,     0,     0,
       0,   154,   131,     0,     0,     0,   110,   111,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    15,     0,     0,
      17,   129,   150,   151,     0,     0,     0,     0,   154,   131,
     130,   152,   193,  -189,  -189,   153,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,     0,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,     0,     0,     0,     0,  -189,  -189,
    -189,     0,     0,     0,     0,     0,     0,  -189,  -189,  -189,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   131,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    15,     0,     0,    17,   129,     0,    15,    16,     0,
      17,     0,     0,     0,   130,  -189,  -189,    18,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,    27,     0,    28,
       0,    29,    30,    31,    32,    33,     0,     0,     7,    34,
       0,    35,    36,    37,     0,     0,    38,    39,    15,    16,
       0,    17,    40,   131,    41,     0,     0,     0,    18,     0,
      42,     0,     0,   108,     0,     0,    19,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,    27,     0,
      28,     0,    29,    30,    31,    32,    33,     0,     0,     0,
      34,     0,    35,    36,    37,     0,     0,    38,    39,    15,
      16,     0,    17,    40,     0,    41,     0,     0,     0,    18,
       0,    42,     0,     0,     0,   248,     0,    19,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,    27,
       0,    28,     0,    29,    30,    31,    32,    33,     0,     0,
       0,    34,     0,    35,    36,    37,     0,     0,    38,    39,
      15,    16,     0,    17,    40,     0,    41,     0,     0,     0,
      18,     0,    42,     0,     0,     0,     0,     0,    19,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
      27,     0,    28,     0,    29,    30,    31,    32,    33,     0,
       0,     0,    34,     0,    35,    36,    37,     0,     0,    38,
      39,    15,    16,     0,    17,    40,     0,    41,     0,     0,
       0,    84,     0,    42,     0,     0,     0,     0,     0,    19,
       0,     0,     0,    85,   177,    22,    23,    24,    25,    26,
       0,    27,    15,    16,     0,    17,     0,     0,     0,     0,
       0,     0,    84,    34,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,    85,   254,    22,    23,    24,    25,
      26,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34
};

static const yytype_int16 yycheck[] =
{
       8,     8,    31,     8,    91,   198,   261,   231,     5,   233,
       8,     3,     5,     5,    27,   102,   200,    27,    44,   190,
      11,   190,    43,   141,   200,    26,    44,    48,    27,   200,
      76,    77,    41,    65,    26,    48,    44,    48,    27,    44,
      27,    27,    43,     0,     4,     5,    44,     7,     8,     9,
      10,    11,    12,    13,    14,    26,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    86,   237,    85,   237,    29,
      30,    31,    43,    27,    39,    85,    85,    48,    38,    39,
      40,    43,   266,    91,   171,    86,    85,    52,    85,   207,
     266,    82,    85,    85,   102,   266,    85,    36,    85,    85,
     108,   356,    40,   108,    43,    43,    35,    41,    48,    48,
     108,   198,    41,    45,     3,    86,    62,    43,    47,    66,
      49,   314,    48,   149,    86,    40,    86,    87,    74,    21,
      45,    85,    97,   220,   358,    64,   165,    26,    72,    73,
      69,   149,    88,     3,   149,    85,     3,    86,    86,    78,
      79,   149,     3,    85,    83,    84,    48,    49,    26,    26,
      86,    48,    49,   171,    35,    35,    26,   286,   194,    26,
      41,     4,    48,    48,     4,    26,    47,    47,    49,    49,
      48,    48,   190,    48,   149,   193,   194,   306,   193,   194,
     198,     4,   200,   201,   281,   193,   194,   284,    26,    35,
      26,    26,    26,    48,    48,   231,    49,   233,    40,    49,
      49,    47,   220,    49,    40,    26,    85,    58,    26,    85,
      40,     3,    40,   231,    76,   233,   231,   314,   233,   237,
      26,    16,    26,   231,    19,   233,    48,     4,    48,    27,
      42,   249,    49,    26,     3,    45,    31,     3,    85,    27,
      47,     3,    37,    48,    45,    35,    41,    27,   266,    45,
     347,    48,    26,   228,    48,    27,   231,    47,   233,    49,
      85,    48,    48,   281,     3,     8,   284,    27,    27,   237,
     297,    66,    91,   266,    64,   250,    79,   271,    20,    69,
     284,   347,   300,   300,   230,   300,   261,    40,    78,    79,
     196,   246,   300,    83,    84,    -1,   314,    -1,    -1,    -1,
     336,    -1,    97,    98,    -1,   100,   101,   282,    -1,    -1,
      -1,    -1,    -1,   349,    -1,    -1,   334,   334,   336,   334,
     338,   336,   358,    -1,    -1,   343,   334,    -1,   336,   347,
      -1,   349,   307,    -1,   349,    -1,    -1,   312,   313,    -1,
     358,   349,    -1,   358,    -1,    -1,   141,   142,    -1,    -1,
     358,   146,    40,    -1,    -1,    -1,    -1,   152,   153,   154,
      -1,   156,    -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,   351,    -1,   173,   174,
      -1,   356,    -1,   358,    -1,    -1,    74,    -1,    -1,   364,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    25,    26,
      -1,    28,    90,    -1,   199,    -1,    94,    -1,    35,    -1,
      -1,   206,   207,    40,    -1,    -1,    43,    -1,    -1,   107,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      -1,    -1,    -1,   228,    -1,   230,    -1,    -1,    -1,   234,
      67,    -1,    -1,    25,    26,    -1,    28,   135,    -1,   244,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   276,    -1,   278,   279,    67,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,   187,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   307,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,    -1,    -1,   331,    -1,   226,   227,
     335,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      -1,    -1,   240,    -1,    -1,    -1,    35,    -1,    -1,   354,
      -1,    -1,    -1,    -1,    43,    -1,    -1,   255,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    -1,   274,    -1,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    25,    26,   287,
      28,    80,    -1,    82,   292,    -1,    -1,    35,    -1,    88,
      -1,   299,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,   320,   321,   322,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     348,    -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,   360,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,     4,     5,    43,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    43,    44,    45,    -1,
      -1,    85,    86,    87,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    86,
      87,    38,    39,    40,     4,     5,    43,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    86,    87,    38,    39,
      40,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    86,    87,    43,    -1,
      45,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      43,    86,    87,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    42,    43,    86,    87,    -1,    -1,    -1,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    86,    87,    43,    44,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    43,    -1,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      85,    86,    87,    38,    39,    40,     4,     5,    43,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,    -1,     4,     5,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    86,    87,
      38,    39,    40,     4,     5,    43,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    -1,    25,    26,    -1,
      28,    -1,    -1,    -1,    38,    86,    87,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    57,
      -1,    59,    60,    61,    62,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    71,    -1,    -1,    74,    75,    25,    26,
      -1,    28,    80,    87,    82,    -1,    -1,    -1,    35,    -1,
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
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67
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
     131,   132,   133,   137,   141,   142,   144,   146,   147,   150,
     154,   159,   160,   162,   163,   165,   166,   167,   168,   169,
      48,    96,    97,     4,    35,    47,    48,   122,   128,   162,
     163,    26,    48,   103,   163,    48,   127,     3,    26,     4,
      26,    26,    26,   103,    48,    48,    49,   163,    40,    98,
       4,     5,     7,     8,     9,    10,    11,    12,    13,    14,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    29,
      38,    87,   143,   144,   145,   163,    49,   100,    49,    98,
     134,    26,    43,    48,    86,    85,     5,    85,   163,    58,
      30,    31,    39,    43,    86,    98,   143,   144,   109,    27,
      96,    21,    48,    49,    27,    85,    35,    49,   104,   105,
     122,    26,    44,    85,     5,    98,   163,    48,   102,   129,
     130,   163,    48,    49,   148,   163,   164,   163,   104,   161,
      40,     3,    40,    40,    99,    76,   155,   156,    26,    26,
      40,    45,   115,   129,    44,   163,     3,    26,    48,   163,
      48,    98,   100,   149,   163,   163,   163,   163,   103,    27,
      85,    48,   105,   122,   135,   136,   163,   163,     3,    27,
      85,    27,     6,    27,    42,    35,   117,   118,   119,   123,
     163,    49,   107,   108,    72,    73,   151,   152,    41,    26,
      77,   156,   158,   136,    48,   163,   170,    64,    78,    79,
      83,    84,   101,   111,   112,   113,   114,   120,   121,   123,
     133,   122,    27,    44,   163,   129,     3,    44,    45,    45,
      27,    45,   138,   104,    85,    36,    27,   163,   130,   149,
      47,   149,   163,    41,   117,     3,    41,    85,   153,   163,
      45,    41,   152,   122,   157,    98,    27,     3,    27,    27,
      85,    45,    48,    48,    26,   134,    41,   111,   115,    27,
     163,   163,   163,   104,   122,   139,   140,    98,   135,    48,
     138,    42,   163,   108,    45,    85,    99,    48,    85,   138,
     163,    48,    98,    26,    98,   136,    44,    85,   163,    99,
     163,    27,   122,    98,     3,   122,    27,   139,    27,    98,
     163,    48,   134,   149,    27,    98
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
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 110 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 136 "lex\\silang.yxx"
    { (yyval.expr)=makeConst((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].expr)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 139 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 144 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 149 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (2)].tp), (yyvsp[(2) - (2)].str)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 150 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (4)].tp), (yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 155 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 161 "lex\\silang.yxx"
    { (yyval.expr)=createEnum((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 166 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 170 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 171 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str),nullptr); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 179 "lex\\silang.yxx"
    { (yyval.expr)=makeClass((yyvsp[(1) - (3)].type),(yyvsp[(2) - (3)].str), nullptr, (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 181 "lex\\silang.yxx"
    { (yyval.expr)=makeClass((yyvsp[(1) - (5)].type),(yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].tp), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 182 "lex\\silang.yxx"
    { (yyval.expr)=annotationdClass((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 186 "lex\\silang.yxx"
    { (yyval.type)=0; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 187 "lex\\silang.yxx"
    { (yyval.type)=1; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 198 "lex\\silang.yxx"
    { (yyval.expr)=setProtected(); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 204 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(2, "Init", (yyvsp[(3) - (5)].expr), nullptr, (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 209 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(3, ":finalize", nullptr, nullptr, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 214 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 217 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 225 "lex\\silang.yxx"
    { (yyval.tp)=createInterface((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 235 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 240 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(0, (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].expr), (yyvsp[(6) - (6)].expr), nullptr); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 247 "lex\\silang.yxx"
    { (yyval.expr)=makeGet((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 251 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].tp), (yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 252 "lex\\silang.yxx"
    { (yyval.expr)=makeSet((yyvsp[(2) - (3)].str), nullptr, nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 263 "lex\\silang.yxx"
    { (yyval.tp)=getClassType((yyvsp[(1) - (1)].str)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 264 "lex\\silang.yxx"
    { (yyval.tp)=getType((yyvsp[(1) - (1)].type)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 265 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (3)].tp)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 266 "lex\\silang.yxx"
    { (yyval.tp)=makeArray((yyvsp[(1) - (4)].tp),(yyvsp[(3) - (4)].expr)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 267 "lex\\silang.yxx"
    { (yyval.tp)=getFuncType(); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 268 "lex\\silang.yxx"
    { (yyval.tp)=nullAble((yyvsp[(1) - (2)].tp)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 272 "lex\\silang.yxx"
    { (yyval.expr)=createDef((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 273 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 274 "lex\\silang.yxx"
    { (yyval.expr)=appendDef((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 278 "lex\\silang.yxx"
    { (yyval.expr)=makeSequence( (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 286 "lex\\silang.yxx"
    { (yyval.expr)=makeTuple((yyvsp[(4) - (5)].expr), (yyvsp[(2) - (5)].expr)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 290 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 291 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr), true); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 295 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 296 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 303 "lex\\silang.yxx"
    { (yyval.expr)=makeCall((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 307 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 309 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 322 "lex\\silang.yxx"
    { (yyval.expr)=createNew((yyvsp[(1) - (5)].tp), (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 326 "lex\\silang.yxx"
    { (yyval.expr)=makeDelete((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 334 "lex\\silang.yxx"
    { (yyval.expr)=addFunctionBlock((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 338 "lex\\silang.yxx"
    { (yyval.expr)=NULL; ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 344 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].str), nullptr, 1); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 349 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 351 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 361 "lex\\silang.yxx"
    { (yyval.expr)=createOperator((yyvsp[(2) - (7)].type), (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 365 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 366 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 371 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 376 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 381 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(6, "", (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 386 "lex\\silang.yxx"
    { (yyval.expr)=callReturn(); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 387 "lex\\silang.yxx"
    { (yyval.expr)=callReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 392 "lex\\silang.yxx"
    { (yyval.type)='+'; ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 393 "lex\\silang.yxx"
    { (yyval.type)='-'; ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 394 "lex\\silang.yxx"
    { (yyval.type)='*'; ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 395 "lex\\silang.yxx"
    { (yyval.type)='/'; ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 396 "lex\\silang.yxx"
    { (yyval.type)='&'; ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 397 "lex\\silang.yxx"
    { (yyval.type)='|'; ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 398 "lex\\silang.yxx"
    { (yyval.type)='!'; ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 399 "lex\\silang.yxx"
    { (yyval.type)='<'; ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 400 "lex\\silang.yxx"
    { (yyval.type)='>'; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 401 "lex\\silang.yxx"
    { (yyval.type)='%'; ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 402 "lex\\silang.yxx"
    { (yyval.type)='.'; ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 403 "lex\\silang.yxx"
    { (yyval.type)=LEFTMOVE; ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 404 "lex\\silang.yxx"
    { (yyval.type)=RIGHTMOVE; ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 405 "lex\\silang.yxx"
    { (yyval.type)=URIGHTMOVE; ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 406 "lex\\silang.yxx"
    { (yyval.type)=LEQ; ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 407 "lex\\silang.yxx"
    { (yyval.type)=REQ; ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 408 "lex\\silang.yxx"
    { (yyval.type)=RGO; ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 409 "lex\\silang.yxx"
    { (yyval.type)=EQ; ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 410 "lex\\silang.yxx"
    { (yyval.type)=AEQ; ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 411 "lex\\silang.yxx"
    { (yyval.type)=NOEQ; ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 412 "lex\\silang.yxx"
    { (yyval.type)=OR; ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 413 "lex\\silang.yxx"
    { (yyval.type)=AND; ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 417 "lex\\silang.yxx"
    { (yyval.type)='^'; ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 418 "lex\\silang.yxx"
    { (yyval.type)='~'; ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 431 "lex\\silang.yxx"
    { (yyval.expr)=makeIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 435 "lex\\silang.yxx"
    { (yyval.expr)=setElse((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 452 "lex\\silang.yxx"
    { (yyval.expr)=createSwitch((yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 457 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 461 "lex\\silang.yxx"
    { (yyval.expr)=createCase((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 462 "lex\\silang.yxx"
    { (yyval.expr)=createCase(nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 467 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 474 "lex\\silang.yxx"
    { (yyval.expr)=createTry( (yyvsp[(2) - (4)].expr), (yyvsp[(3) - (4)].expr), (yyvsp[(4) - (4)].expr) ); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 478 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 480 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 484 "lex\\silang.yxx"
    { (yyval.expr)=makeCatch((yyvsp[(3) - (6)].expr), (yyvsp[(4) - (6)].str), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 488 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 489 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),let((yyvsp[(3) - (3)].tp))); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 493 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 494 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 502 "lex\\silang.yxx"
    { (yyval.expr)=makeWhile((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 506 "lex\\silang.yxx"
    { (yyval.expr)=makeFor( (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].expr)); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 516 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 517 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 529 "lex\\silang.yxx"
    { (yyval.expr)=makeNull(); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 530 "lex\\silang.yxx"
    { (yyval.expr)=getVar((yyvsp[(1) - (1)].str)); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 531 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 532 "lex\\silang.yxx"
    { (yyval.expr)=binary((yyvsp[(2) - (3)].type), (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 533 "lex\\silang.yxx"
    { (yyval.expr)=unary((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 534 "lex\\silang.yxx"
    { (yyval.expr)=unaryAfter((yyvsp[(2) - (2)].type), (yyvsp[(1) - (2)].expr)); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 539 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 540 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr), false); ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 541 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF(makeIsNull((yyvsp[(1) - (3)].expr)), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 542 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 543 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 544 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 545 "lex\\silang.yxx"
    { (yyval.expr)=createNew((yyvsp[(1) - (4)].tp), NULL, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 549 "lex\\silang.yxx"
    { (yyval.expr)=binaryIs((yyvsp[(1) - (3)].expr), getType((yyvsp[(3) - (3)].type)));  ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 566 "lex\\silang.yxx"
    { (yyval.expr)=makeSplice((yyvsp[(1) - (6)].expr), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr)); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 574 "lex\\silang.yxx"
    { (yyval.expr)=makeIndex((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 583 "lex\\silang.yxx"
    { (yyval.expr)=makeBased((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 589 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 590 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 594 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 595 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (5)].expr), let((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].expr))); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2979 "intermediate/silang.tab.cpp"
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
#line 598 "lex\\silang.yxx"


