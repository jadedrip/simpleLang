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

#ifndef YY_YY_INTERMEDIATE_SILANG_TAB_HPP_INCLUDED
# define YY_YY_INTERMEDIATE_SILANG_TAB_HPP_INCLUDED
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
     FLOAT_TOKEN = 284,
     INT64_TOKEN = 285,
     FLOAT64 = 286,
     BOOLEAN_TOKEN = 287,
     CALL = 288,
     IF = 289,
     ELSE = 290,
     WHILE = 291,
     FOR = 292,
     RETURN = 293,
     CLASS = 294,
     INTERF = 295,
     PROTECTED = 296,
     PACKAGE = 297,
     IMPORT = 298,
     NULLPTR = 299,
     STATIC = 300,
     CONST_TOKEN = 301,
     ENUM = 302,
     SWITCH = 303,
     CASE = 304,
     DEFAULT = 305,
     SINGLETON = 306,
     TRY_TOKEN = 307,
     CATCH = 308,
     FINALLY = 309,
     GET_TOKEN = 310,
     SET_TOKEN = 311,
     OPERATOR = 312,
     NEW_TOKEN = 313,
     DELETE_TOKEN = 314,
     INIT_TOKEN = 315,
     FINALIZE_TOKEN = 316,
     GO_TOKEN = 317,
     BBRACKETS = 318,
     CONCEPT = 319,
     PK = 320,
     AS = 321,
     VOID_TOKEN = 322
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 13 "lex\\silang.yxx"

	AstType		*tp;
	AstNode		*expr;
	char*		str;
	int			type;


/* Line 2058 of yacc.c  */
#line 132 "intermediate/silang.tab.hpp"
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

#endif /* !YY_YY_INTERMEDIATE_SILANG_TAB_HPP_INCLUDED  */
