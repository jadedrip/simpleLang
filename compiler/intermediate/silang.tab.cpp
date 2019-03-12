
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
     GO_TOKEN = 318
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
#line 194 "intermediate/silang.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 206 "intermediate/silang.tab.cpp"

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
#define YYLAST   2093

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  250
/* YYNRULES -- Number of states.  */
#define YYNSTATES  442

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,    88,    24,     2,
      27,    28,    22,    20,    86,    21,     4,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    43,
      11,     3,    12,    87,    89,     2,     2,     2,     2,     2,
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
      77,    78,    79,    80,    81,    82,    83,    84,    85
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
     397,   398,   401,   403,   405,   407,   411,   418,   422,   425,
     427,   430,   432,   434,   436,   438,   440,   442,   444,   446,
     448,   450,   452,   454,   456,   458,   460,   462,   464,   466,
     468,   470,   472,   474,   476,   482,   486,   488,   490,   492,
     494,   496,   502,   504,   507,   512,   516,   518,   522,   527,
     528,   530,   533,   540,   542,   546,   547,   550,   556,   566,
     567,   569,   573,   577,   581,   583,   585,   587,   589,   591,
     593,   595,   597,   601,   604,   607,   609,   611,   613,   615,
     618,   621,   625,   631,   635,   639,   644,   648,   652,   656,
     660,   664,   668,   672,   676,   680,   684,   688,   692,   696,
     700,   704,   708,   712,   716,   720,   724,   728,   730,   733,
     735,   737,   739,   741,   743,   750,   755,   758,   764,   770,
     774
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      91,     0,    -1,    93,    94,   100,    -1,    49,    -1,    92,
       4,    49,    -1,    65,    92,    -1,    -1,    -1,    95,    -1,
      94,    95,    -1,    66,    97,    -1,    66,    27,    98,    28,
      -1,    49,    -1,    96,     4,    49,    -1,    96,     4,    22,
      -1,    96,     4,    50,    -1,    96,     4,    49,    -1,    97,
      -1,    98,    97,    -1,    41,    42,    -1,    41,   100,    42,
      -1,   101,    -1,   100,   101,    -1,   130,    -1,   113,    -1,
     122,    -1,   133,    -1,   135,    -1,   170,    -1,   171,    -1,
     150,    -1,   168,    -1,   167,    -1,   155,    -1,   140,    -1,
     102,    -1,   107,    -1,   158,    -1,   162,    -1,   139,    -1,
     144,    -1,   138,    -1,    69,    49,     3,   171,    -1,    49,
       3,   171,    -1,   171,    -1,   104,    86,   171,    -1,   128,
      49,    -1,   128,    49,     3,   171,    -1,   105,    -1,   106,
      86,   105,    -1,    70,    50,    41,   108,    42,    -1,   109,
      -1,   108,    86,   109,    -1,    50,     3,   171,    -1,    50,
      -1,    -1,    46,   128,    -1,    -1,    11,   112,    12,    -1,
      50,    -1,   112,    86,    50,    -1,   114,    50,   111,   110,
     121,    -1,   178,   113,    -1,    62,    -1,    74,    -1,   130,
      -1,   126,    -1,   127,    -1,   116,    -1,   119,    -1,   102,
      -1,   140,    -1,    64,    46,    -1,   144,    -1,    83,    27,
     143,    28,   117,    -1,    -1,    41,    42,    -1,    41,   118,
      42,    -1,    83,    27,   136,    28,    -1,   100,    -1,    84,
     141,    -1,   115,    -1,   120,   115,    -1,    41,   120,    42,
      -1,    -1,    63,    49,    41,   124,    42,    -1,   130,    -1,
     125,    -1,   123,    -1,   124,   123,    -1,    36,    49,    27,
     143,    28,   145,    -1,    78,    49,    99,    -1,    79,    49,
      27,   128,    49,    28,    99,    -1,    79,    49,    99,    -1,
      50,    -1,    50,    11,   129,    12,    -1,    48,    -1,   128,
      44,    45,    -1,   128,    44,   171,    45,    -1,    36,    -1,
     128,    87,    -1,   128,    -1,   129,    86,   128,    -1,   105,
      -1,   130,    86,    49,    -1,   130,    86,    49,     3,   171,
      -1,   128,    49,     5,   171,    -1,   128,    27,   134,    28,
       5,   171,    -1,    44,   104,    45,    -1,    27,   171,    86,
     104,    28,    -1,   134,     5,   171,    -1,    49,    86,    49,
      -1,   134,    86,    49,    -1,    49,    27,   136,    28,    -1,
      -1,   137,    -1,   136,    86,   137,    -1,   171,    -1,   103,
      -1,   128,    49,    27,   136,    28,    -1,    82,   171,    -1,
     125,   141,    -1,    -1,    99,    -1,   128,    37,    49,    -1,
      -1,   106,    -1,   106,    86,   142,    -1,   142,    -1,    80,
     153,    27,   143,    28,   145,   141,    -1,    -1,    46,   147,
      -1,   105,    -1,   128,    -1,   146,    -1,   147,    86,   146,
      -1,    36,    27,   143,    28,   145,    99,    -1,    85,   145,
      99,    -1,    85,   171,    -1,    61,    -1,    61,   104,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    30,    -1,    11,    -1,    12,    -1,    88,    -1,
       4,    -1,    19,    -1,    18,    -1,    17,    -1,    14,    -1,
      13,    -1,    39,    -1,     8,    -1,     7,    -1,    26,    -1,
      29,    -1,   151,    -1,   152,    -1,    57,    27,   156,    28,
     157,    -1,   154,    58,   157,    -1,   154,    -1,   171,    -1,
     172,    -1,   101,    -1,    99,    -1,    71,   171,    41,   159,
      42,    -1,   160,    -1,   159,   160,    -1,    72,   161,    46,
     100,    -1,    73,    46,   100,    -1,   171,    -1,   161,    86,
     171,    -1,    75,    99,   163,   166,    -1,    -1,   164,    -1,
     163,   164,    -1,    76,    27,   165,    49,    28,    99,    -1,
     128,    -1,   165,    86,   128,    -1,    -1,    77,    99,    -1,
      59,    27,   171,    28,   157,    -1,    60,    27,   169,    43,
     171,    43,   171,    28,   157,    -1,    -1,   105,    -1,    49,
       3,   171,    -1,    49,     3,    99,    -1,    49,     5,   171,
      -1,   174,    -1,   131,    -1,   148,    -1,   135,    -1,   132,
      -1,   149,    -1,    67,    -1,    49,    -1,    27,   171,    28,
      -1,   152,   171,    -1,   171,   152,    -1,   170,    -1,   175,
      -1,   176,    -1,   177,    -1,   171,    32,    -1,   171,    31,
      -1,   171,    40,   171,    -1,   171,    87,   171,    46,   171,
      -1,    50,     4,    49,    -1,    50,     4,    50,    -1,   128,
      27,   136,    28,    -1,   171,    20,   171,    -1,   171,    21,
     171,    -1,   171,    22,   171,    -1,   171,    23,   171,    -1,
     171,    24,   171,    -1,   171,    25,   171,    -1,   171,    11,
     171,    -1,   171,    12,   171,    -1,   171,    88,   171,    -1,
     171,     4,   171,    -1,   171,    19,   171,    -1,   171,    18,
     171,    -1,   171,    17,   171,    -1,   171,    14,   171,    -1,
     171,    13,   171,    -1,   171,    39,   171,    -1,   171,    10,
     171,    -1,   171,     5,   171,    -1,   171,     8,   171,    -1,
     171,     7,   171,    -1,   171,     6,    48,    -1,    15,    -1,
     173,    15,    -1,    51,    -1,    52,    -1,    53,    -1,    54,
      -1,   173,    -1,   171,    44,   171,    46,   171,    45,    -1,
     171,    44,   171,    45,    -1,   171,    99,    -1,    89,    50,
      27,   171,    28,    -1,    89,    50,    27,   179,    28,    -1,
      49,     3,   171,    -1,   179,    86,    49,     3,   171,    -1
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
     399,   400,   404,   405,   409,   410,   414,   419,   421,   426,
     427,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     454,   455,   459,   460,   468,   472,   473,   477,   478,   482,
     483,   487,   493,   494,   498,   499,   503,   504,   511,   515,
     516,   517,   521,   525,   526,   530,   531,   539,   542,   546,
     548,   553,   554,   555,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   607,   611,   612,   616,
     617,   618,   619,   620,   629,   637,   646,   652,   653,   657,
     658
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
  "DELETE_TOKEN", "INIT_TOKEN", "FINALIZE_TOKEN", "GO_TOKEN", "','", "'?'",
  "'%'", "'@'", "$accept", "package", "package_name", "package_name_line",
  "import", "import_line", "import_name_pre", "import_name",
  "import_names", "block", "lines", "line", "const", "equal", "exprs",
  "typeLet", "typeLets", "enum", "enum_list", "enum_assignment",
  "cls_inherit", "cls_template_list", "types", "cls", "cls_type",
  "cls_line", "cls_construct", "construct_block_or_none",
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
     313,   314,   315,   316,   317,   318,    44,    63,    37,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    92,    92,    93,    93,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   103,   104,   104,   105,   105,   106,   106,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   117,   117,   117,   118,   118,
     119,   120,   120,   121,   121,   122,   123,   123,   124,   124,
     125,   126,   127,   127,   128,   128,   128,   128,   128,   128,
     128,   129,   129,   130,   130,   130,   130,   130,   131,   132,
     133,   134,   134,   135,   136,   136,   136,   137,   137,   138,
     139,   140,   141,   141,   142,   143,   143,   143,   143,   144,
     145,   145,   146,   146,   147,   147,   148,   149,   149,   150,
     150,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     152,   152,   153,   153,   154,   155,   155,   156,   156,   157,
     157,   158,   159,   159,   160,   160,   161,   161,   162,   163,
     163,   163,   164,   165,   165,   166,   166,   167,   168,   169,
     169,   170,   170,   170,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   172,   173,   173,   174,
     174,   174,   174,   174,   175,   176,   177,   178,   178,   179,
     179
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
       0,     2,     1,     1,     1,     3,     6,     3,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     1,     1,     1,     1,
       1,     5,     1,     2,     4,     3,     1,     3,     4,     0,
       1,     2,     6,     1,     3,     0,     2,     5,     9,     0,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     1,     1,     1,     1,     2,
       2,     3,     5,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     6,     4,     2,     5,     5,     3,
       5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     7,     3,     5,     1,     0,     0,     8,
       0,     0,    12,     0,    10,   237,   160,     0,   161,    99,
       0,    96,   201,    94,   239,   240,   241,   242,     0,     0,
       0,   139,    63,     0,   200,     0,     0,     0,    64,     0,
       0,     0,   130,     0,     9,     2,    21,    35,   103,    36,
      24,     0,    25,   122,     0,    23,   195,   198,    26,     0,
      27,    41,    39,    34,    40,   196,   199,    30,     0,   166,
      33,    37,    38,    32,    31,    28,    29,   243,   194,   206,
     207,   208,     0,     4,    17,     0,     0,    99,   201,     0,
     197,   205,     0,   125,     0,     0,    44,     0,     0,   114,
       0,     0,     0,     0,     0,   189,   140,     0,     0,     0,
       0,     0,   179,   151,   159,   158,   148,   149,   156,   155,
     154,   153,   152,   141,   142,   143,   144,   145,   146,   147,
     157,   150,   162,   163,     0,   120,     0,     0,   138,     0,
      22,    57,   123,   121,   114,     0,    46,   100,     0,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,   209,     0,     0,     0,     0,     0,   246,   204,
     238,    62,    11,    18,    14,    16,    15,   114,   202,     0,
      99,    94,    48,   126,     0,   128,     0,   125,   108,     0,
     192,   191,   193,   201,   118,     0,   115,   117,   111,   213,
     214,   101,     0,     0,   167,   168,     0,   190,     0,     0,
       0,     0,     0,     0,    19,     0,     0,   185,   180,   125,
     132,   133,   134,   131,   137,     0,     0,    55,   201,     0,
       0,    97,     0,     0,     0,   114,   104,   110,   112,   170,
     169,   165,   225,   233,   235,   234,   232,   222,   223,   230,
     229,   228,   227,   226,   216,   217,   218,   219,   220,   221,
     231,   211,     0,     0,   224,     0,     0,     0,    46,   130,
       0,    45,     0,   113,     0,    95,     0,     0,     0,     0,
       0,    99,    88,     0,    87,     0,    86,    42,    54,     0,
      51,     0,     0,     0,   172,    20,     0,     0,   181,   178,
       0,     0,   201,     0,     0,    59,     0,     0,    84,     0,
     215,    98,    47,   106,     0,     0,   245,     0,     0,   109,
      49,   127,   124,     0,   130,    43,   116,   102,   164,   236,
     187,     0,    85,    89,     0,    46,     0,    50,     0,     0,
     176,     0,   171,   173,   183,     0,   186,   130,   135,     0,
     247,   248,     0,    58,     0,    56,     0,    61,     0,   119,
     105,     0,   212,   136,    90,     0,     0,    53,    52,     0,
       0,   175,     0,     0,   122,   191,     0,    60,     0,     0,
       0,     0,   122,    70,    81,    68,    69,     0,    66,    67,
      65,    71,    73,   107,   244,     0,   174,   177,     0,   184,
     129,     0,    72,     0,     0,   125,    80,    83,    82,     0,
     182,   250,    91,     0,    93,     0,   188,     0,    75,     0,
       0,    74,     0,    76,     0,    79,     0,    92,   114,    77,
       0,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     3,     8,     9,    13,    14,    85,   178,
     225,    46,    47,   204,    95,    48,   193,    49,   299,   300,
     318,   237,   316,    50,    51,   394,   395,   431,   436,   396,
     397,   367,    52,   292,   293,    53,   398,   399,    89,   212,
      55,    56,    57,    58,    59,    90,   240,   206,    61,    62,
      63,   143,   195,   196,    64,   137,   232,   233,    65,    66,
      67,   132,    68,   134,    69,    70,   213,   251,    71,   303,
     304,   349,    72,   227,   228,   355,   309,    73,    74,   219,
      91,    76,   215,    77,    78,    79,    80,    81,    82,   314
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -362
static const yytype_int16 yypact[] =
{
     -40,   -19,    43,    20,  -362,   125,  -362,   110,  1589,  -362,
     101,   106,  -362,   198,  -362,  -362,  -362,  1881,  -362,   164,
    1881,  -362,     9,    31,  -362,  -362,  -362,  -362,   176,   178,
     187,  1881,  -362,   186,  -362,   188,   169,  1881,  -362,   195,
    1422,  1881,   444,   189,  -362,  1789,  -362,  -362,  -362,  -362,
    -362,   190,  -362,   195,     2,   152,  -362,  -362,  -362,    13,
    1334,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  1881,   183,
    -362,  -362,  -362,  -362,  -362,  1384,  1246,   244,  -362,  -362,
    -362,  -362,   136,  -362,  -362,    -9,    -2,   238,   130,   103,
    -362,  -362,    52,   197,   239,    70,  1246,   575,  1881,  1911,
     218,   104,   197,  1881,  1881,   197,   191,   229,   271,   234,
    1296,  1639,   211,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,   264,  1246,   197,   195,  1246,   267,
    -362,   285,  -362,  -362,  1941,  1839,   131,  -362,   250,  1881,
     257,  1246,  1689,  1881,  1881,  1881,  1881,  1881,  1881,  1881,
    1881,  1881,  1881,  1881,  1881,  1881,  1881,  1881,  1881,  1881,
    1881,  -362,  -362,  1881,  1881,  1881,  1881,  1881,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   304,  -362,  1911,  -362,  1881,
    -362,   299,  -362,   226,    83,  -362,   286,   197,  -362,  1881,
    -362,  1246,  1246,   203,  -362,    21,  -362,  1246,  -362,  -362,
    -362,     1,     4,   289,   852,  -362,   890,  -362,    73,   270,
     212,  1881,   265,  1478,  -362,  1739,   294,   124,  -362,   197,
    -362,    73,  -362,   236,  -362,  1971,   273,   288,    12,    22,
      26,  -362,   940,  1881,  1881,  1911,   330,  1246,  -362,  -362,
    -362,  -362,  1246,  1246,   155,   155,  1456,   232,   232,   232,
     232,   651,   651,   651,  2005,  2005,   534,   534,   261,   261,
    1246,  1246,   754,   985,  1246,    27,   197,   290,   332,   291,
     308,  1246,   575,  -362,  1911,  -362,   197,  1689,   292,  1689,
    1881,   296,  -362,   184,  -362,    74,   152,  1246,   338,   -18,
    -362,  1881,   300,    69,  -362,  -362,   197,   195,  -362,  -362,
     319,   197,   204,  1030,    30,  -362,    14,   197,   311,   348,
    -362,  -362,  1246,  1246,    33,  1881,  -362,  1881,  1881,  -362,
    -362,  -362,  -362,   195,   291,  1246,  -362,     1,  -362,  -362,
    -362,  1071,  -362,  -362,   305,    29,  1881,  -362,   265,   102,
    1246,  1789,  -362,  -362,     1,    38,  -362,   291,  -362,   575,
    -362,  -362,   307,  -362,   309,     1,   469,  -362,  1881,  -362,
    1246,  1116,  1246,  -362,  -362,  1881,   274,  1246,  -362,  1789,
    1881,  1789,   329,   197,   195,  1158,   358,  -362,   316,   315,
     317,   340,   195,  -362,  -362,  -362,  -362,   247,  -362,  -362,
     152,  -362,  -362,  1246,  -362,  1208,  1789,  1246,   195,     1,
    -362,  1881,  -362,   195,   170,   197,  -362,  -362,  -362,  1689,
    -362,  1246,  -362,   197,  -362,   337,  -362,    77,   327,   341,
    1539,  -362,   195,  -362,   343,  1789,   335,  -362,  1911,  -362,
      39,  -362
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -362,  -362,  -362,  -362,  -362,   373,  -362,    17,  -362,   132,
       0,   -43,  -345,  -362,   -26,   -83,  -362,  -362,  -362,    34,
    -362,  -362,  -362,   301,  -362,   -10,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,    95,  -362,  -187,  -362,  -362,    -8,  -362,
    -214,  -362,  -362,  -362,  -140,    -7,   -96,   109,  -362,  -362,
    -235,  -361,   118,  -188,  -174,  -252,    84,  -362,  -362,  -362,
    -362,  -362,   447,  -362,  -362,  -362,  -362,  -276,  -362,  -362,
      93,  -362,  -362,  -362,   173,  -362,  -362,  -362,  -362,  -362,
      -1,   287,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -250
static const yytype_int16 yytable[] =
{
      54,    60,   140,   205,   239,   106,   296,    75,    45,   280,
     192,   338,    97,   340,    98,   282,   285,    98,   149,   182,
     184,   393,   217,   410,   347,     1,   363,   333,    84,   144,
       4,   416,   243,   294,   244,   101,    99,    54,    60,    99,
      12,   310,   102,     6,    75,   145,   145,   185,   186,   283,
     319,   146,   393,   230,   320,   329,   153,   154,   361,   155,
     156,   369,   157,   158,   159,   160,   161,   441,   348,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    16,   296,
     188,    18,   374,   171,   172,   194,     7,   382,   147,   147,
     286,   173,   174,   111,   211,   100,   175,   218,   100,   150,
     364,   344,   183,    54,    60,   384,   294,   284,   150,   250,
      75,   352,   284,   199,   192,   198,   362,   145,   145,   284,
     277,   145,   278,   345,   383,   284,   429,   145,   231,    10,
     187,   401,   278,    97,   243,    98,   244,    11,   189,   176,
     177,   301,   302,   426,    54,    60,   192,   145,   379,   324,
      83,    75,   400,   209,   210,    12,   199,    99,   245,    12,
     147,   147,   401,   275,   147,   157,   158,   159,   160,   161,
     147,   112,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    16,   140,   400,    18,   142,   171,   172,   380,   194,
     147,    93,   402,   330,   173,   174,   111,   423,    32,   175,
     226,   307,    86,   103,   239,   104,   282,   359,    98,    98,
      38,   111,   295,    94,   105,    54,    60,    54,    60,   109,
     291,   194,    75,   402,    75,    43,   342,   425,   230,   200,
      99,    99,    21,   190,   191,   107,   111,   108,   148,   139,
     141,   152,   176,   177,   250,    21,   250,   191,   291,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    16,   180,
      21,    18,   191,   171,   172,    93,   197,   208,   194,   234,
     220,   173,   174,   111,   221,   222,   175,   199,   337,    54,
      60,    54,    60,   291,   249,   295,    75,   226,    75,   417,
      18,   229,   171,   172,   235,    21,   236,   191,   354,   246,
     173,   174,   111,   231,    92,   175,   248,    96,   -13,   365,
     102,   388,   276,   290,   279,   298,    35,   287,    96,   176,
     177,   306,   311,   315,   110,   389,   390,    40,   135,   138,
     391,   392,   192,   325,   317,   243,   334,   136,   140,   332,
     339,   346,   440,    54,    60,    94,   351,   357,   176,   177,
      75,   381,   366,   368,   376,   151,   386,   408,   295,   387,
     100,   411,   412,   140,   413,   428,   414,   415,   430,   432,
     438,    54,    60,    54,    60,   409,   250,   439,    75,   406,
      75,    44,   378,   181,   201,   202,   207,   418,   343,   295,
     214,   216,   140,   336,   331,   358,   353,     0,    54,    60,
     308,     0,     0,     0,     0,    75,     0,   194,     0,     0,
       0,    54,    60,     0,   200,   427,     0,     0,    75,   249,
       0,   249,    54,    60,     0,     0,     0,    54,    60,    75,
     435,   207,   242,     0,    75,     0,   247,     0,     0,   356,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,     0,    15,
     270,   271,   272,   273,   274,   373,     0,     0,     0,     0,
      16,    17,     0,    18,   207,     0,    96,     0,     0,     0,
      87,     0,     0,     0,     0,     0,   281,   133,    20,     0,
     136,   200,    21,    88,    23,    24,    25,    26,    27,     0,
       0,     0,     0,     0,     0,   291,     0,     0,   297,     0,
       0,    34,     0,     0,     0,     0,   142,    21,     0,   191,
       0,     0,   313,   179,   142,     0,     0,     0,     0,    42,
     322,   323,   207,   388,     0,     0,     0,     0,    35,   179,
     420,     0,     0,   179,     0,   422,   424,   389,   390,    40,
       0,   249,   391,   392,     0,     0,     0,   179,   169,   170,
      16,     0,     0,    18,   437,   171,   172,     0,     0,   335,
       0,   207,     0,   173,   174,   111,     0,   341,   175,     0,
       0,     0,   179,     0,     0,   179,     0,     0,   350,     0,
      15,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,    16,    17,     0,    18,     0,     0,     0,     0,     0,
       0,    87,   370,     0,   371,   372,   111,     0,     0,    20,
       0,   176,   177,    21,    88,    23,    24,    25,    26,    27,
       0,     0,     0,   377,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,   385,     0,   179,   179,
       0,     0,     0,     0,   179,   403,     0,     0,     0,     0,
      42,   179,   405,   179,     0,     0,     0,   407,     0,     0,
       0,   165,   166,   167,   168,   169,   170,    16,     0,     0,
      18,     0,   171,   172,     0,     0,     0,     0,     0,   179,
     173,   174,   111,     0,   179,   175,     0,     0,   421,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,     0,     0,     0,   207,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   177,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     179,   155,   156,     0,   157,   158,   159,   160,   161,   179,
     179,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      16,     0,   179,    18,     0,   171,   172,     0,   179,     0,
       0,     0,     0,   173,   174,   111,     0,   179,   175,   326,
     327,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,   179,   179,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,   179,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   177,     0,     0,     0,     0,     0,     0,     0,
     179,     0,   179,     0,   179,     0,   153,   154,   288,   155,
     156,     0,   157,   158,   159,   160,   161,     0,   179,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    16,     0,
       0,    18,     0,   171,   172,     0,     0,     0,     0,     0,
       0,   173,   174,   111,   153,   154,   175,   155,   156,     0,
     157,   158,   159,   160,   161,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    16,     0,   289,    18,
       0,   171,   172,     0,     0,     0,     0,     0,     0,   173,
     174,   111,     0,     0,   175,     0,     0,     0,     0,   176,
     177,     0,     0,     0,   153,   154,     0,   155,   156,     0,
     157,   158,   159,   160,   161,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    16,     0,     0,    18,
       0,   171,   172,     0,     0,     0,     0,   176,   177,   173,
     174,   111,     0,     0,   175,   321,     0,     0,     0,   153,
     154,     0,   155,   156,     0,   157,   158,   159,   160,   161,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    16,     0,     0,    18,     0,   171,   172,     0,     0,
       0,     0,     0,     0,   173,   174,   111,   176,   177,   175,
       0,   328,     0,     0,   153,   154,     0,   155,   156,     0,
     157,   158,   159,   160,   161,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    16,     0,   360,    18,
       0,   171,   172,     0,     0,     0,     0,     0,     0,   173,
     174,   111,   176,   177,   175,   153,   154,     0,   155,   156,
       0,   157,   158,   159,   160,   161,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    16,     0,     0,
      18,     0,   171,   172,     0,     0,     0,     0,     0,     0,
     173,   174,   111,     0,   375,   175,     0,   176,   177,     0,
     153,   154,     0,   155,   156,     0,   157,   158,   159,   160,
     161,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    16,     0,     0,    18,     0,   171,   172,     0,
       0,     0,     0,     0,     0,   173,   174,   111,   176,   177,
     175,   404,   153,   154,     0,   155,   156,     0,   157,   158,
     159,   160,   161,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    16,     0,     0,    18,     0,   171,
     172,     0,     0,     0,     0,     0,     0,   173,   174,   111,
       0,     0,   175,   176,   177,     0,     0,     0,     0,     0,
       0,     0,   153,   154,     0,   155,   156,     0,   157,   158,
     159,   160,   161,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    16,     0,   419,    18,     0,   171,
     172,     0,     0,     0,  -249,   176,   177,   173,   174,   111,
     153,   154,   175,   155,   156,     0,   157,   158,   159,   160,
     161,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    16,     0,     0,    18,     0,   171,   172,     0,
       0,     0,     0,     0,     0,   173,   174,   111,     0,     0,
     175,     0,     0,     0,     0,   176,   177,     0,     0,     0,
     153,   154,     0,   155,   156,     0,   157,   158,   159,   160,
     161,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    16,     0,     0,    18,     0,   171,   172,     0,
       0,     0,     0,   176,   177,   173,   174,   223,  -197,  -197,
     175,  -197,  -197,     0,  -197,  -197,  -197,  -197,  -197,     0,
       0,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
       0,     0,     0,     0,     0,  -197,  -197,     0,     0,     0,
       0,     0,     0,  -197,  -197,  -197,     0,     0,     0,     0,
       0,     0,     0,   176,   177,     0,     0,     0,  -205,  -205,
       0,  -205,  -205,     0,  -205,  -205,  -205,  -205,  -205,     0,
       0,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
       0,     0,     0,     0,     0,  -205,  -205,     0,     0,     0,
       0,  -197,  -197,  -205,  -205,  -205,   113,     0,     0,   114,
     115,     0,     0,   116,   117,   118,   119,     0,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    16,     0,
       0,    18,   129,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,     0,     0,   158,   159,   160,
     161,  -205,  -205,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    16,     0,     0,    18,     0,   171,   172,     0,
       0,     0,     0,    15,     0,   173,   174,   111,     0,     0,
     175,     0,     0,     0,    16,    17,     0,    18,     0,     0,
     131,     0,     0,     0,    19,     0,     0,     0,     0,     0,
     224,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,     0,     0,    28,     0,    29,    30,    31,
      32,    33,     0,   176,   177,    34,     0,    35,    36,    37,
     301,   302,    38,    39,    15,     0,     0,     0,    40,     0,
      41,     0,     0,    42,     0,    16,    17,    43,    18,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,   433,     0,    20,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,     0,     0,    28,     0,    29,    30,
      31,    32,    33,     0,    15,     0,    34,     0,    35,    36,
      37,     0,     0,    38,    39,    16,    17,     0,    18,    40,
       0,    41,   434,     0,    42,    19,     0,     0,    43,     0,
       0,     0,     0,    20,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,     0,     0,    28,     0,    29,    30,
      31,    32,    33,     0,    15,     7,    34,     0,    35,    36,
      37,     0,     0,    38,    39,    16,    17,     0,    18,    40,
       0,    41,     0,     0,    42,    19,     0,     0,    43,     0,
       0,   224,     0,    20,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,     0,     0,    28,     0,    29,    30,
      31,    32,    33,     0,    15,     0,    34,     0,    35,    36,
      37,     0,     0,    38,    39,    16,    17,     0,    18,    40,
       0,    41,     0,     0,    42,    19,     0,     0,    43,     0,
     111,     0,     0,    20,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,     0,     0,    28,     0,    29,    30,
      31,    32,    33,     0,    15,     0,    34,     0,    35,    36,
      37,     0,     0,    38,    39,    16,    17,     0,    18,    40,
       0,    41,     0,     0,    42,    19,     0,     0,    43,     0,
       0,   305,     0,    20,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,     0,     0,    28,     0,    29,    30,
      31,    32,    33,     0,    15,     0,    34,     0,    35,    36,
      37,     0,     0,    38,    39,    16,    17,     0,    18,    40,
       0,    41,     0,     0,    42,    19,     0,     0,    43,     0,
       0,     0,     0,    20,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,     0,     0,    28,     0,    29,    30,
      31,    32,    33,     0,    15,     0,    34,     0,    35,    36,
      37,     0,     0,    38,    39,    16,    17,     0,    18,    40,
       0,    41,     0,     0,    42,    87,     0,     0,    43,     0,
       0,     0,     0,    20,   241,     0,     0,    21,    88,    23,
      24,    25,    26,    27,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    16,    17,     0,
      18,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     0,     0,    42,    20,    15,     0,     0,    21,
      88,    23,    24,    25,    26,    27,     0,    16,    17,     0,
      18,     0,     0,     0,     0,     0,     0,    87,    34,     0,
       0,     0,     0,     0,     0,    20,    15,     0,     0,    21,
     203,    23,    24,    25,    26,    27,    42,    16,    17,     0,
      18,     0,     0,     0,     0,     0,     0,    87,    34,     0,
       0,     0,     0,     0,     0,    20,    15,     0,     0,    21,
     238,    23,    24,    25,    26,    27,    42,    16,    17,     0,
      18,     0,     0,     0,     0,     0,     0,    87,    34,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,    21,
     312,    23,    24,    25,    26,    27,    42,   167,   168,   169,
     170,    16,     0,     0,    18,     0,   171,   172,    34,     0,
       0,     0,     0,     0,   173,   174,   111,     0,     0,   175,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,   177
};

static const yytype_int16 yycheck[] =
{
       8,     8,    45,    99,   144,    31,   220,     8,     8,   197,
      93,   287,     3,   289,     5,     3,    12,     5,     5,    28,
      22,   366,   105,   384,    42,    65,    12,   279,    11,    27,
      49,   392,     3,   220,     5,     4,    27,    45,    45,    27,
      49,   229,    11,     0,    45,    44,    44,    49,    50,    28,
      28,    49,   397,   136,    28,    28,     4,     5,    28,     7,
       8,    28,    10,    11,    12,    13,    14,    28,    86,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   293,
      28,    29,   334,    31,    32,    93,    66,    49,    87,    87,
      86,    39,    40,    41,   102,    86,    44,   105,    86,    86,
      86,    27,    85,   111,   111,   357,   293,    86,    86,   152,
     111,    42,    86,    86,   197,    45,    86,    44,    44,    86,
      37,    44,    49,    49,    86,    86,    49,    44,   136,     4,
      27,   366,    49,     3,     3,     5,     5,    27,    86,    87,
      88,    72,    73,   419,   152,   152,   229,    44,    46,   245,
      49,   152,   366,    49,    50,    49,    86,    27,    27,    49,
      87,    87,   397,   189,    87,    10,    11,    12,    13,    14,
      87,    39,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   225,   397,    29,    53,    31,    32,    86,   197,
      87,    27,   366,   276,    39,    40,    41,    27,    62,    44,
      76,    77,     4,    27,   344,    27,     3,     3,     5,     5,
      74,    41,   220,    49,    27,   223,   223,   225,   225,    50,
      36,   229,   223,   397,   225,    89,    42,   415,   311,    97,
      27,    27,    48,    36,    50,    49,    41,    49,    86,    50,
      50,    58,    87,    88,   287,    48,   289,    50,    36,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    15,
      48,    29,    50,    31,    32,    27,    27,    49,   276,   137,
      41,    39,    40,    41,     3,    41,    44,    86,   286,   287,
     287,   289,   289,    36,   152,   293,   287,    76,   289,    42,
      29,    27,    31,    32,    27,    48,    11,    50,   306,    49,
      39,    40,    41,   311,    17,    44,    49,    20,     4,   317,
      11,    64,    86,    43,    28,    50,    69,    28,    31,    87,
      88,    27,    86,    50,    37,    78,    79,    80,    41,    42,
      83,    84,   415,     3,    46,     3,    28,    46,   381,    49,
      48,     3,   438,   351,   351,    49,    46,    28,    87,    88,
     351,   351,    41,     5,    49,    68,    49,    28,   366,    50,
      86,     3,    46,   406,    49,    28,    49,    27,    41,    28,
      27,   379,   379,   381,   381,   383,   419,    42,   379,   379,
     381,     8,   348,    82,    97,    98,    99,   397,   293,   397,
     103,   104,   435,   284,   276,   311,   303,    -1,   406,   406,
     227,    -1,    -1,    -1,    -1,   406,    -1,   415,    -1,    -1,
      -1,   419,   419,    -1,   282,   423,    -1,    -1,   419,   287,
      -1,   289,   430,   430,    -1,    -1,    -1,   435,   435,   430,
     430,   144,   145,    -1,   435,    -1,   149,    -1,    -1,   307,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    15,
     173,   174,   175,   176,   177,   333,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,   187,    -1,   189,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,   199,    40,    44,    -1,
      46,   359,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,   221,    -1,
      -1,    67,    -1,    -1,    -1,    -1,   384,    48,    -1,    50,
      -1,    -1,   235,    76,   392,    -1,    -1,    -1,    -1,    85,
     243,   244,   245,    64,    -1,    -1,    -1,    -1,    69,    92,
     408,    -1,    -1,    96,    -1,   413,   414,    78,    79,    80,
      -1,   419,    83,    84,    -1,    -1,    -1,   110,    24,    25,
      26,    -1,    -1,    29,   432,    31,    32,    -1,    -1,   282,
      -1,   284,    -1,    39,    40,    41,    -1,   290,    44,    -1,
      -1,    -1,   135,    -1,    -1,   138,    -1,    -1,   301,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,   325,    -1,   327,   328,    41,    -1,    -1,    44,
      -1,    87,    88,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,   359,    -1,   201,   202,
      -1,    -1,    -1,    -1,   207,   368,    -1,    -1,    -1,    -1,
      85,   214,   375,   216,    -1,    -1,    -1,   380,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,   242,
      39,    40,    41,    -1,   247,    44,    -1,    -1,   411,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,    -1,    -1,    -1,   438,    -1,    -1,   281,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    -1,    -1,    -1,   297,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
     313,     7,     8,    -1,    10,    11,    12,    13,    14,   322,
     323,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,   335,    29,    -1,    31,    32,    -1,   341,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,   350,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,   371,   372,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     403,    -1,   405,    -1,   407,    -1,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    -1,   421,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,     4,     5,    44,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,     4,     5,    -1,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    87,    88,    39,
      40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,    -1,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    87,    88,    44,
      -1,    46,    -1,    -1,     4,     5,    -1,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    87,    88,    44,     4,     5,    -1,     7,     8,
      -1,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    -1,    43,    44,    -1,    87,    88,    -1,
       4,     5,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    87,    88,
      44,    45,     4,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    44,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    86,    87,    88,    39,    40,    41,
       4,     5,    44,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
       4,     5,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    87,    88,    39,    40,    41,     4,     5,
      44,     7,     8,    -1,    10,    11,    12,    13,    14,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,     4,     5,
      -1,     7,     8,    -1,    10,    11,    12,    13,    14,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    87,    88,    39,    40,    41,     4,    -1,    -1,     7,
       8,    -1,    -1,    11,    12,    13,    14,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    87,    88,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    15,    -1,    39,    40,    41,    -1,    -1,
      44,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,
      88,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    -1,    87,    88,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    15,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    85,    -1,    26,    27,    89,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    15,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    74,    75,    26,    27,    -1,    29,    80,
      -1,    82,    83,    -1,    85,    36,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    15,    66,    67,    -1,    69,    70,
      71,    -1,    -1,    74,    75,    26,    27,    -1,    29,    80,
      -1,    82,    -1,    -1,    85,    36,    -1,    -1,    89,    -1,
      -1,    42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    15,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    74,    75,    26,    27,    -1,    29,    80,
      -1,    82,    -1,    -1,    85,    36,    -1,    -1,    89,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    15,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    74,    75,    26,    27,    -1,    29,    80,
      -1,    82,    -1,    -1,    85,    36,    -1,    -1,    89,    -1,
      -1,    42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    15,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    74,    75,    26,    27,    -1,    29,    80,
      -1,    82,    -1,    -1,    85,    36,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    63,    -1,    15,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    74,    75,    26,    27,    -1,    29,    80,
      -1,    82,    -1,    -1,    85,    36,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    26,    27,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    44,    15,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    26,    27,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    15,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    85,    26,    27,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    15,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    85,    26,    27,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    85,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    31,    32,    67,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    91,    93,    49,    92,     0,    66,    94,    95,
       4,    27,    49,    96,    97,    15,    26,    27,    29,    36,
      44,    48,    49,    50,    51,    52,    53,    54,    57,    59,
      60,    61,    62,    63,    67,    69,    70,    71,    74,    75,
      80,    82,    85,    89,    95,   100,   101,   102,   105,   107,
     113,   114,   122,   125,   128,   130,   131,   132,   133,   134,
     135,   138,   139,   140,   144,   148,   149,   150,   152,   154,
     155,   158,   162,   167,   168,   170,   171,   173,   174,   175,
     176,   177,   178,    49,    97,    98,     4,    36,    49,   128,
     135,   170,   171,    27,    49,   104,   171,     3,     5,    27,
      86,     4,    11,    27,    27,    27,   104,    49,    49,    50,
     171,    41,    99,     4,     7,     8,    11,    12,    13,    14,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    30,
      39,    88,   151,   152,   153,   171,    46,   145,   171,    50,
     101,    50,    99,   141,    27,    44,    49,    87,    86,     5,
      86,   171,    58,     4,     5,     7,     8,    10,    11,    12,
      13,    14,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    31,    32,    39,    40,    44,    87,    88,    99,   152,
      15,   113,    28,    97,    22,    49,    50,    27,    28,    86,
      36,    50,   105,   106,   128,   142,   143,    27,    45,    86,
      99,   171,   171,    49,   103,   136,   137,   171,    49,    49,
      50,   128,   129,   156,   171,   172,   171,   105,   128,   169,
      41,     3,    41,    41,    42,   100,    76,   163,   164,    27,
     105,   128,   146,   147,    99,    27,    11,   111,    49,   134,
     136,    45,   171,     3,     5,    27,    49,   171,    49,    99,
     101,   157,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   104,    86,    37,    49,    28,
     143,   171,     3,    28,    86,    12,    86,    28,     6,    28,
      43,    36,   123,   124,   125,   128,   130,   171,    50,   108,
     109,    72,    73,   159,   160,    42,    27,    77,   164,   166,
     143,    86,    49,   171,   179,    50,   112,    46,   110,    28,
      28,    45,   171,   171,   136,     3,    45,    46,    46,    28,
     105,   142,    49,   145,    28,   171,   137,   128,   157,    48,
     157,   171,    42,   123,    27,    49,     3,    42,    86,   161,
     171,    46,    42,   160,   128,   165,    99,    28,   146,     3,
      28,    28,    86,    12,    86,   128,    41,   121,     5,    28,
     171,   171,   171,    99,   145,    43,    49,   171,   109,    46,
      86,   100,    49,    86,   145,   171,    49,    50,    64,    78,
      79,    83,    84,   102,   115,   116,   119,   120,   126,   127,
     130,   140,   144,   171,    45,   171,   100,   171,    28,   128,
     141,     3,    46,    49,    49,    27,   141,    42,   115,    28,
      99,   171,    99,    27,    99,   143,   157,   128,    28,    49,
      41,   117,    28,    42,    83,   100,   118,    99,    27,    42,
     136,    28
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
#line 399 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 400 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 405 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 410 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 415 "lex\\silang.yxx"
    { (yyval.expr)=createFunction(6, "", (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 420 "lex\\silang.yxx"
    { (yyval.expr)=createGo(createFunction(6, "", nullptr, (yyvsp[(2) - (3)].expr), (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 421 "lex\\silang.yxx"
    { (yyval.expr)=createGo((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 426 "lex\\silang.yxx"
    { (yyval.expr)=callReturn(); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 427 "lex\\silang.yxx"
    { (yyval.expr)=callReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 432 "lex\\silang.yxx"
    { (yyval.type)='+'; ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 433 "lex\\silang.yxx"
    { (yyval.type)='-'; ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 434 "lex\\silang.yxx"
    { (yyval.type)='*'; ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 435 "lex\\silang.yxx"
    { (yyval.type)='/'; ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 436 "lex\\silang.yxx"
    { (yyval.type)='&'; ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 437 "lex\\silang.yxx"
    { (yyval.type)='|'; ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 438 "lex\\silang.yxx"
    { (yyval.type)='!'; ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 439 "lex\\silang.yxx"
    { (yyval.type)='<'; ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 440 "lex\\silang.yxx"
    { (yyval.type)='>'; ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 441 "lex\\silang.yxx"
    { (yyval.type)='%'; ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 442 "lex\\silang.yxx"
    { (yyval.type)='.'; ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 443 "lex\\silang.yxx"
    { (yyval.type)=LEFTMOVE; ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 444 "lex\\silang.yxx"
    { (yyval.type)=RIGHTMOVE; ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 445 "lex\\silang.yxx"
    { (yyval.type)=URIGHTMOVE; ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 446 "lex\\silang.yxx"
    { (yyval.type)=LEQ; ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 447 "lex\\silang.yxx"
    { (yyval.type)=REQ; ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 448 "lex\\silang.yxx"
    { (yyval.type)=RGO; ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 449 "lex\\silang.yxx"
    { (yyval.type)=OR; ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 450 "lex\\silang.yxx"
    { (yyval.type)=AND; ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 454 "lex\\silang.yxx"
    { (yyval.type)='^'; ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 455 "lex\\silang.yxx"
    { (yyval.type)='~'; ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 468 "lex\\silang.yxx"
    { (yyval.expr)=makeIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 472 "lex\\silang.yxx"
    { (yyval.expr)=setElse((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 489 "lex\\silang.yxx"
    { (yyval.expr)=createSwitch((yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 494 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 498 "lex\\silang.yxx"
    { (yyval.expr)=createCase((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 499 "lex\\silang.yxx"
    { (yyval.expr)=createCase(nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 504 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 511 "lex\\silang.yxx"
    { (yyval.expr)=createTry( (yyvsp[(2) - (4)].expr), (yyvsp[(3) - (4)].expr), (yyvsp[(4) - (4)].expr) ); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 515 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 517 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 521 "lex\\silang.yxx"
    { (yyval.expr)=makeCatch((yyvsp[(3) - (6)].expr), (yyvsp[(4) - (6)].str), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 525 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 526 "lex\\silang.yxx"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),let((yyvsp[(3) - (3)].tp))); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 530 "lex\\silang.yxx"
    { (yyval.expr)=nullptr; ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 531 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 539 "lex\\silang.yxx"
    { (yyval.expr)=makeWhile((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 543 "lex\\silang.yxx"
    { (yyval.expr)=makeFor( (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].expr)); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 553 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 554 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), createFunction(6, "", nullptr, nullptr, (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 555 "lex\\silang.yxx"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 568 "lex\\silang.yxx"
    { (yyval.expr)=makeNull(); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 569 "lex\\silang.yxx"
    { (yyval.expr)=getVar((yyvsp[(1) - (1)].str)); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 570 "lex\\silang.yxx"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 571 "lex\\silang.yxx"
    { (yyval.expr)=unary((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 572 "lex\\silang.yxx"
    { (yyval.expr)=unaryAfter((yyvsp[(2) - (2)].type), (yyvsp[(1) - (2)].expr)); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 577 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 578 "lex\\silang.yxx"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr), false); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 579 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF(makeIsNull((yyvsp[(1) - (3)].expr)), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 580 "lex\\silang.yxx"
    { (yyval.expr)=makeIIF((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 581 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 582 "lex\\silang.yxx"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 583 "lex\\silang.yxx"
    { (yyval.expr)=createNew((yyvsp[(1) - (4)].tp), NULL, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 584 "lex\\silang.yxx"
    { (yyval.expr)=binary('+', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 585 "lex\\silang.yxx"
    { (yyval.expr)=binary('-', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 586 "lex\\silang.yxx"
    { (yyval.expr)=binary('*', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 587 "lex\\silang.yxx"
    { (yyval.expr)=binary('/', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 588 "lex\\silang.yxx"
    { (yyval.expr)=binary('&', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 589 "lex\\silang.yxx"
    { (yyval.expr)=binary('|', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 590 "lex\\silang.yxx"
    { (yyval.expr)=binary('<', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 591 "lex\\silang.yxx"
    { (yyval.expr)=binary('>', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 592 "lex\\silang.yxx"
    { (yyval.expr)=binary('%', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 593 "lex\\silang.yxx"
    { (yyval.expr)=binary('.', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 594 "lex\\silang.yxx"
    { (yyval.expr)=binary(LEFTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 595 "lex\\silang.yxx"
    { (yyval.expr)=binary(RIGHTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 596 "lex\\silang.yxx"
    { (yyval.expr)=binary(URIGHTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 597 "lex\\silang.yxx"
    { (yyval.expr)=binary(LEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 598 "lex\\silang.yxx"
    { (yyval.expr)=binary(REQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 599 "lex\\silang.yxx"
    { (yyval.expr)=binary(RGO, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 600 "lex\\silang.yxx"
    { (yyval.expr)=binary(EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 601 "lex\\silang.yxx"
    { (yyval.expr)=binary(AEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 602 "lex\\silang.yxx"
    { (yyval.expr)=binary(OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 603 "lex\\silang.yxx"
    { (yyval.expr)=binary(AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 607 "lex\\silang.yxx"
    { (yyval.expr)=binaryIs((yyvsp[(1) - (3)].expr), getType((yyvsp[(3) - (3)].type)));  ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 612 "lex\\silang.yxx"
    {(yyval.expr)=stringCat((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr));;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 620 "lex\\silang.yxx"
    { (yyval.expr)=(yyval.expr); ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 629 "lex\\silang.yxx"
    { (yyval.expr)=makeSplice((yyvsp[(1) - (6)].expr), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr)); ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 637 "lex\\silang.yxx"
    { (yyval.expr)=makeIndex((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 646 "lex\\silang.yxx"
    { (yyval.expr)=makeBased((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 652 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 653 "lex\\silang.yxx"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 657 "lex\\silang.yxx"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 658 "lex\\silang.yxx"
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
#line 661 "lex\\silang.yxx"


