/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INTERMEDIATE_SILANG_TAB_HPP_INCLUDED
# define YY_YY_INTERMEDIATE_SILANG_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AEQ = 258,                     /* AEQ  */
    ISOPT = 259,                   /* ISOPT  */
    OR = 260,                      /* OR  */
    AND = 261,                     /* AND  */
    EQ = 262,                      /* EQ  */
    NOEQ = 263,                    /* NOEQ  */
    LEQ = 264,                     /* LEQ  */
    REQ = 265,                     /* REQ  */
    LEFTMOVE = 266,                /* LEFTMOVE  */
    RIGHTMOVE = 267,               /* RIGHTMOVE  */
    URIGHTMOVE = 268,              /* URIGHTMOVE  */
    ARRAY = 269,                   /* ARRAY  */
    INC = 270,                     /* INC  */
    DEC = 271,                     /* DEC  */
    BINARY = 272,                  /* BINARY  */
    EOL = 273,                     /* EOL  */
    FEOF = 274,                    /* FEOF  */
    FUNC = 275,                    /* FUNC  */
    DOTS = 276,                    /* DOTS  */
    TYPE = 277,                    /* TYPE  */
    RGO = 278,                     /* RGO  */
    WHEN_NULL = 279,               /* WHEN_NULL  */
    ITYPE = 280,                   /* ITYPE  */
    L_IDENTIFIER = 281,            /* L_IDENTIFIER  */
    U_IDENTIFIER = 282,            /* U_IDENTIFIER  */
    INTEGER = 283,                 /* INTEGER  */
    FLOAT_TOKEN = 284,             /* FLOAT_TOKEN  */
    INT64_TOKEN = 285,             /* INT64_TOKEN  */
    FLOAT64 = 286,                 /* FLOAT64  */
    BOOLEAN_TOKEN = 287,           /* BOOLEAN_TOKEN  */
    STRING_LITERAL = 288,          /* STRING_LITERAL  */
    CALL = 289,                    /* CALL  */
    IF = 290,                      /* IF  */
    ELSE = 291,                    /* ELSE  */
    WHILE = 292,                   /* WHILE  */
    FOR = 293,                     /* FOR  */
    RETURN = 294,                  /* RETURN  */
    CLASS = 295,                   /* CLASS  */
    INTERF = 296,                  /* INTERF  */
    PROTECTED = 297,               /* PROTECTED  */
    PACKAGE = 298,                 /* PACKAGE  */
    IMPORT = 299,                  /* IMPORT  */
    NULLPTR = 300,                 /* NULLPTR  */
    STATIC = 301,                  /* STATIC  */
    CONST_TOKEN = 302,             /* CONST_TOKEN  */
    ENUM = 303,                    /* ENUM  */
    SWITCH = 304,                  /* SWITCH  */
    CASE = 305,                    /* CASE  */
    DEFAULT = 306,                 /* DEFAULT  */
    SINGLETON = 307,               /* SINGLETON  */
    TRY_TOKEN = 308,               /* TRY_TOKEN  */
    CATCH = 309,                   /* CATCH  */
    FINALLY = 310,                 /* FINALLY  */
    GET_TOKEN = 311,               /* GET_TOKEN  */
    SET_TOKEN = 312,               /* SET_TOKEN  */
    OPERATOR = 313,                /* OPERATOR  */
    NEW_TOKEN = 314,               /* NEW_TOKEN  */
    DELETE_TOKEN = 315,            /* DELETE_TOKEN  */
    INIT_TOKEN = 316,              /* INIT_TOKEN  */
    FINALIZE_TOKEN = 317,          /* FINALIZE_TOKEN  */
    GO_TOKEN = 318,                /* GO_TOKEN  */
    BBRACKETS = 319,               /* BBRACKETS  */
    CONCEPT = 320,                 /* CONCEPT  */
    PK = 321,                      /* PK  */
    AS = 322,                      /* AS  */
    VOID_TOKEN = 323               /* VOID_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "lex\\silang.yxx"

	AstType		*tp;
	AstNode		*expr;
	char*		str;
	int			type;

#line 139 "intermediate/silang.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERMEDIATE_SILANG_TAB_HPP_INCLUDED  */
