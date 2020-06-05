
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
     FLOAT_TOKEN = 285,
     INT64_TOKEN = 286,
     FLOAT64 = 287,
     BOOLEAN_TOKEN = 288,
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
     CONST_TOKEN = 302,
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
     BBRACKETS = 319,
     CONCEPT = 320,
     PK = 321,
     AS = 322,
     VOID_TOKEN = 323
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "lex\\silang.yxx"

	AstType		*tp;
	AstNode		*expr;
	char*		str;
	int			type;



/* Line 1676 of yacc.c  */
#line 129 "intermediate/silang.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


