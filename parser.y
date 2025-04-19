/* CMSC 430 Compiler Theory and Design
   Project 2 Skeleton

   Jonathan Apolaya 
   CMSC 430 
   Compiler Theory
   Descprition: added the grammer for arithmatic, left and right, level of precendence , removed EBNF and added recursion. added error handling to complete a parse with multiple errors. 

   Project 2 Parser */

%{

#include <string>
#include <cmath> 
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "values.h"
#include "listing.h"
#include "tokens.h"

int yylex();
void yyerror(const char* message);

%}

%define parse.error verbose

%token IDENTIFIER INT_LITERAL CHAR_LITERAL HEX_LITERAL REAL REAL_LITERAL

%token ADDOP MULOP ANDOP RELOP ARROW REMOP EXPOP NEGOP OROP NOTOP

%token LEFT RIGHT 

%token ELSIF ENDFOLD FOLD IF THEN ENDIF

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN





%%

function:	
	function_header optional_variable body ;

function_header:	
	FUNCTION IDENTIFIER parameters RETURNS type ';'  |
	FUNCTION IDENTIFIER error ';';

parameters:
	%empty |
	parameter_list ;

parameter_list:
	parameter |
	parameter_list ',' parameter |
	parameter_list error ;

parameter: 
	IDENTIFIER ':' type ;

type:
	INTEGER |
	CHARACTER |
	REAL;

	
optional_variable:
	optional_variable variable|
	optional_variable error |
	%empty ;
    
variable:	
	IDENTIFIER ':' type IS statement ';' |
	IDENTIFIER ':' LIST OF type IS list ';' ;


list:
	'(' expressions ')' ;

expressions:
	expressions ',' expression| 
	expression ;

body:
	BEGIN_ statements END ';' ;

statements:
	statements statement_ | %empty ;

statement_:
	statement ';' |
	error ';' ;
    
statement:
	expression |
	if_statement |
	fold_statement | 
	when_statement |
	switch_statement ;

switch_statement:
    SWITCH expression IS cases ENDSWITCH |      
    SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH ;  

when_statement:
	WHEN condition ',' expression ':' expression ;


fold_statement:
	FOLD direction operator operand ENDFOLD;

direction:
	LEFT | RIGHT ;

operator: 
	ADDOP | MULOP | RELOP;

operand: 
       list | IDENTIFIER;


if_statement:  
	IF condition THEN statements elsif_clauses optional_else ENDIF;

elsif_clauses:
	elsif_clauses elsif_clause |
	%empty ;

elsif_clause:
	ELSIF condition THEN statements ;

optional_else:
	ELSE statements |
	%empty;



cases:
	cases case |
	%empty ;
	
case:
	CASE INT_LITERAL ARROW statements ';' | 
	CASE error ARROW statements ';' | 
	CASE INT_LITERAL ARROW error ';' ;


condition:
	condition OROP logical_and |
	logical_and ;

logical_and:
	logical_and ANDOP logical_not |
	logical_not ;

logical_not:
	NOTOP logical_not |
	relation
relation:
	'(' condition ')' |
	expression RELOP expression ;

expression:
	expression operator term |
	term ;

term:
	term MULOP factor |
	term REMOP factor |
	factor ;

factor:       
	factor EXPOP primary |
	primary ;
      

primary:
	'(' expression ')' |
	NEGOP primary |
	INT_LITERAL |
	CHAR_LITERAL |
	REAL_LITERAL |
	HEX_LITERAL |
	IDENTIFIER '(' expression ')' |
	IDENTIFIER ;

%%

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

int main(int argc, char *argv[]) {
	firstLine();
	yyparse();
	lastLine();
	return 0;
} 
