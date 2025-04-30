/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    ELSIF = 258,                   /* ELSIF  */
    ENDFOLD = 259,                 /* ENDFOLD  */
    FOLD = 260,                    /* FOLD  */
    IF = 261,                      /* IF  */
    THEN = 262,                    /* THEN  */
    ENDIF = 263,                   /* ENDIF  */
    BEGIN_ = 264,                  /* BEGIN_  */
    CASE = 265,                    /* CASE  */
    CHARACTER = 266,               /* CHARACTER  */
    ELSE = 267,                    /* ELSE  */
    END = 268,                     /* END  */
    ENDSWITCH = 269,               /* ENDSWITCH  */
    FUNCTION = 270,                /* FUNCTION  */
    INTEGER = 271,                 /* INTEGER  */
    IS = 272,                      /* IS  */
    LIST = 273,                    /* LIST  */
    OF = 274,                      /* OF  */
    OTHERS = 275,                  /* OTHERS  */
    RETURNS = 276,                 /* RETURNS  */
    SWITCH = 277,                  /* SWITCH  */
    WHEN = 278,                    /* WHEN  */
    IDENTIFIER = 279,              /* IDENTIFIER  */
    ADDOP = 280,                   /* ADDOP  */
    MULOP = 281,                   /* MULOP  */
    ANDOP = 282,                   /* ANDOP  */
    RELOP = 283,                   /* RELOP  */
    ARROW = 284,                   /* ARROW  */
    REMOP = 285,                   /* REMOP  */
    EXPOP = 286,                   /* EXPOP  */
    NEGOP = 287,                   /* NEGOP  */
    OROP = 288,                    /* OROP  */
    NOTOP = 289,                   /* NOTOP  */
    INT_LITERAL = 290,             /* INT_LITERAL  */
    CHAR_LITERAL = 291,            /* CHAR_LITERAL  */
    HEX_LITERAL = 292,             /* HEX_LITERAL  */
    REAL = 293,                    /* REAL  */
    REAL_LITERAL = 294,            /* REAL_LITERAL  */
    LEFT = 295,                    /* LEFT  */
    RIGHT = 296                    /* RIGHT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "parser.y"

	CharPtr iden;
	Operators oper;
	double value;
	vector<double>* list;
	vector<Types>* typeList;
	int dir;
	//project4
	Types type;

#line 116 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
