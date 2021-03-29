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
    EOL = 272,                     /* EOL  */
    FEOF = 273,                    /* FEOF  */
    FUNC = 274,                    /* FUNC  */
    DOTS = 275,                    /* DOTS  */
    TYPE = 276,                    /* TYPE  */
    RGO = 277,                     /* RGO  */
    WHEN_NULL = 278,               /* WHEN_NULL  */
    ITYPE = 279,                   /* ITYPE  */
    L_IDENTIFIER = 280,            /* L_IDENTIFIER  */
    U_IDENTIFIER = 281,            /* U_IDENTIFIER  */
    INTEGER = 282,                 /* INTEGER  */
    FLOAT_TOKEN = 283,             /* FLOAT_TOKEN  */
    INT64_TOKEN = 284,             /* INT64_TOKEN  */
    FLOAT64 = 285,                 /* FLOAT64  */
    BOOLEAN_TOKEN = 286,           /* BOOLEAN_TOKEN  */
    STRING_LITERAL = 287,          /* STRING_LITERAL  */
    CALL = 288,                    /* CALL  */
    IF = 289,                      /* IF  */
    ELSE = 290,                    /* ELSE  */
    WHILE = 291,                   /* WHILE  */
    FOR = 292,                     /* FOR  */
    RETURN = 293,                  /* RETURN  */
    CLASS = 294,                   /* CLASS  */
    INTERF = 295,                  /* INTERF  */
    PROTECTED = 296,               /* PROTECTED  */
    PACKAGE = 297,                 /* PACKAGE  */
    IMPORT = 298,                  /* IMPORT  */
    NULLPTR = 299,                 /* NULLPTR  */
    STATIC = 300,                  /* STATIC  */
    CONST_TOKEN = 301,             /* CONST_TOKEN  */
    ENUM = 302,                    /* ENUM  */
    SWITCH = 303,                  /* SWITCH  */
    CASE = 304,                    /* CASE  */
    DEFAULT = 305,                 /* DEFAULT  */
    SINGLETON = 306,               /* SINGLETON  */
    TRY_TOKEN = 307,               /* TRY_TOKEN  */
    CATCH = 308,                   /* CATCH  */
    FINALLY = 309,                 /* FINALLY  */
    GET_TOKEN = 310,               /* GET_TOKEN  */
    SET_TOKEN = 311,               /* SET_TOKEN  */
    OPERATOR = 312,                /* OPERATOR  */
    NEW_TOKEN = 313,               /* NEW_TOKEN  */
    DELETE_TOKEN = 314,            /* DELETE_TOKEN  */
    INIT_TOKEN = 315,              /* INIT_TOKEN  */
    FINALIZE_TOKEN = 316,          /* FINALIZE_TOKEN  */
    GO_TOKEN = 317,                /* GO_TOKEN  */
    BBRACKETS = 318,               /* BBRACKETS  */
    CONCEPT = 319,                 /* CONCEPT  */
    PK = 320,                      /* PK  */
    AS = 321,                      /* AS  */
    VOID_TOKEN = 322               /* VOID_TOKEN  */
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

#line 138 "intermediate/silang.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERMEDIATE_SILANG_TAB_HPP_INCLUDED  */
