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
#include "symbols.h"


int yylex();
void yyerror(const char* message);
double extract_element(CharPtr list_name, double subscript);

Symbols<double> scalars;
Symbols<vector<double>*> lists;
double result;


%}

%define parse.error verbose

%union {
	CharPtr iden;
	Operators oper;
	double value;
	vector<double>* list;
}

%token <iden> IDENTIFIER

%token <value> INT_LITERAL CHAR_LITERAL HEX_LITERAL REAL REAL_LITERAL

%token <oper>  ADDOP MULOP ANDOP RELOP ARROW REMOP EXPOP NEGOP OROP NOTOP


%token LEFT RIGHT 

%token ELSIF ENDFOLD FOLD IF THEN ENDIF

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN


%type <value> expression term factor primary relation condition logical_and logical_not
%type <oper> operator

%type <list> vector
%type <list> list expressions

%type <value> direction

%type <value> operand

%type <value> case cases
%type <value> if_statement elsif_clauses elsif_clause optional_else
%type <value> switch_statement when_statement
%type <value> fold_statement

%type <value> statement
%type <value> statement_
%type <value> statements
%type <value> body

%type <value> variable optional_variable

%type <value> type
%type <value> parameter parameter_list parameters
%type <value> function_header
%type <value> function



%%

function:	
	function_header optional_variable body  {result = $3;} ;

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
	IDENTIFIER ':' type IS expression ';' {
		scalars.insert($1, $5);
	} |
	IDENTIFIER ':' LIST OF type IS list ';' {
		lists.insert($1, $7);
	};


list:
	'(' expressions ')'  {$$ = $2;};

vector:
       '(' ')' { $$ = new vector<double>(); };

expressions:
	expressions ',' expression { 
		$1->push_back($3); 
		$$ = $1; 
	    } |
	    expression { 
		$$ = new vector<double>(); 
		$$->push_back($1); 
	    };
body:
	BEGIN_ statements END ';' {$$  = $2;} ;

statements:
	statements statement_ | %empty ;

statement_:
	statement ';' |
	error ';'  {$$ = 0;} ;
    
statement:
	expression |
	if_statement |
	fold_statement | 
	when_statement |
	switch_statement ;

switch_statement:
    SWITCH expression IS cases ENDSWITCH |      
    SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH {$$ = !isnan($4) ? $4 : $7;} ;  

when_statement:
	WHEN condition ',' expression ':' expression {$$ = $2 ? $4 : $6;} ;


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
	cases case {$$ = !isnan($1) ? $1 : $2;} |
	%empty {$$ = NAN;} ;
	
case:
	CASE INT_LITERAL ARROW statements {$$ = $<value>-2 == $2 ? $4 : NAN; } |
	CASE error ARROW statements ';' | 
	CASE INT_LITERAL ARROW error ';' ;


condition:
	condition ANDOP relation {$$ = $1 && $2;} |
	condition OROP logical_and |
	logical_and ;

logical_and:
	logical_and ANDOP logical_not |
	logical_not ;

logical_not:
	NOTOP logical_not |
	relation

relation:
	'(' condition ')' {$$ = $2;}|
	expression RELOP expression {$$ = evaluateRelational($1, $2, $3);};

expression:
	expression operator term {$$ = evaluateArithmetic($1, $2, $3);} |
	term ; 

term:
	term MULOP factor {$$ = evaluateArithmetic($1, $2, $3 );}|
	term REMOP factor {$$ = evaluateArithmetic($1, $2, $3 );}|
	factor ; 

factor:       
	factor EXPOP primary {$$ = evaluateArithmetic($1, $2,$3 ); } |
	primary ;
      

primary:
    '(' expression ')' { $$ = $2; } |
    NEGOP primary       { $$ = -$2; } |
    INT_LITERAL         { $$ = $1; } |
    CHAR_LITERAL        { $$ = $1; } |
    REAL_LITERAL        { $$ = $1; } |
    HEX_LITERAL         { $$ = $1; } |
    IDENTIFIER '(' expression ')' { $$ = extract_element($1, $3); } |
    IDENTIFIER {
        if (!scalars.find($1, $$))
            appendError(UNDECLARED_IDENTIFIER, $1);
    };

%%

void yyerror(const char* msg) {
	appendError(SYNTAX, msg);
}

double extract_element(CharPtr list_name, double subscript) {
	vector<double>* list; 
	if (lists.find(list_name, list))
		return (*list)[subscript];
	appendError(UNDECLARED_IDENTIFIER, list_name);
	return NAN;
}


int main(int argc, char *argv[]) {
	firstLine();
	yyparse();
	lastLine();
	return 0;
} 
