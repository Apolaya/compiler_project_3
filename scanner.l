/* CMSC 430 Compiler Theory and Design
   Jonathan Apolaya
   UMGC CITE
   Summer 2023 */
   
/* This file contains flex input file */



%{
#include <cstdio>
#include <string>

using namespace std;
#include "values.h"
#include "listing.h"
#include "tokens.h"


%}

%option noyywrap

ws		[ \t\r]+
comment		 ("//"|"--").*\n
line		[\n]
id		[A-Za-z]([_]{0,2}[A-Za-z0-9])*	

digit		[0-9]
dec		{digit}+
char		'([^\\]|\\[btnrf'\\])'
hex		"#"[0-9A-Fa-f]+
punc		[\(\),:;_]
real		[0-9]*\.[0-9]+([eE][+-]?[0-9]+)? 
%%


{ws}		{ ECHO; }
{comment}	{ ECHO; nextLine(); }
{line}		{ ECHO; nextLine(); }

"+" 		{ ECHO; yylval.oper = ADD; return(ADDOP); }
"-"		{ ECHO; yylval.oper = SUBTRACT; return(ADDOP); }
"/"		{ ECHO; yylval.oper = DIVIDE ; return (ADDOP);}
"*"		{ ECHO; yylval.oper = MULTIPLY ; return(MULOP); }
"&"		{ ECHO; yylval.oper = AND ; return(ANDOP); }
"^"		{ ECHO; yylval.oper = EXPONENT ; return (EXPOP);}
"~"		{ ECHO; yylval.oper = NEGATE ; return (NEGOP);}
"%"		{ ECHO; yylval.oper = REMAINDER ; return (REMOP);}


"=>"		{ ECHO; return(ARROW); }

"<"     	{ ECHO; yylval.oper = LESS ; return(RELOP); }
">"     	{ ECHO; yylval.oper = GREATER ;return(RELOP); }
"="     	{ ECHO; yylval.oper = EQUAL ;return(RELOP); }
"<>"    	{ ECHO; yylval.oper = NOTEQUAL ;return(RELOP); }
">="    	{ ECHO; yylval.oper = GREATEREQUAL ; return(RELOP); }
"<="    	{ ECHO; yylval.oper = LESSEQUAL ; return(RELOP); }

"|"		{ ECHO; yylval.oper = OR ;return(OROP);  }
"!"		{ ECHO; yylval.oper = NOT ; return(NOTOP); }

begin		{ ECHO; return(BEGIN_); }
case		{ ECHO; return(CASE); }
character	{ ECHO; return(CHARACTER); }
end		{ ECHO; return(END); }
endif		{ ECHO; return(ENDIF);}
endswitch	{ ECHO; return(ENDSWITCH); }
function	{ ECHO; return(FUNCTION); }
integer		{ ECHO; return(INTEGER); }
is		{ ECHO; return(IS); }
list		{ ECHO; return(LIST); }
of		{ ECHO; return(OF); }
others		{ ECHO; return(OTHERS); }
returns		{ ECHO; return(RETURNS); }
switch		{ ECHO; return(SWITCH); }
when		{ ECHO; return(WHEN); }
else		{ ECHO; return(ELSE); }
elsif		{ ECHO; return(ELSIF); }
endfold		{ ECHO; return(ENDFOLD); }
fold		{ ECHO; return(FOLD); }
if		{ ECHO; return(IF); }
left		{ ECHO; return(LEFT); }
real 		{ ECHO; return(REAL); }

right		{ ECHO; return(RIGHT); }
then		{ ECHO; return(THEN); }


{real}  { ECHO; yylval.value = atof(yytext); return (REAL_LITERAL); }
{id}		{ ECHO; yylval.iden = (CharPtr)malloc(yyleng + 1); 			strcpy(yylval.iden, yytext); return(IDENTIFIER);}

{dec}		{ ECHO; yylval.value = atoi(yytext); return(INT_LITERAL); }
{char}		{ ECHO; yylval.value = yytext[1]; return(CHAR_LITERAL); }

{hex}		{ ECHO; return(HEX_LITERAL);}
{punc}		{ ECHO; return(yytext[0]); }
.		{ ECHO; appendError(LEXICAL, yytext); }
%%

