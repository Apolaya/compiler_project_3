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
#include "types.h"


int yylex();
void yyerror(const char* message);
double extract_element(CharPtr list_name, double subscript);

Symbols<double> scalars;
Symbols<vector<double>*> lists;
//projec4 symbol types 
Types find(Symbols<Types>& table, CharPtr identifier, string tableName);


Symbols<Types> symbols;
Symbols<Types> listTypes;


double result;

double* paramValues;
int paramIndex = -1; 



%}

%define parse.error verbose

%union {
	CharPtr iden;
	Operators oper;
	double value;
	vector<double>* list;
	vector<Types>* typeList;
	int dir;
	//project4
	Types type;
}

%token ELSIF ENDFOLD FOLD IF THEN ENDIF
%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN

%token <iden> IDENTIFIER

%token <oper>  ADDOP MULOP ANDOP RELOP ARROW REMOP EXPOP NEGOP OROP NOTOP
%type <oper> operator

//union changed from value ->type projec4
%token <type> INT_LITERAL CHAR_LITERAL HEX_LITERAL REAL REAL_LITERAL LEFT RIGHT
%type <type> expression term factor primary relation condition logical_and logical_not
%type <type> case cases
%type <type> if_statement elsif_clauses elsif_clause optional_else
%type <type> switch_statement when_statement
%type <type> fold_statement
%type <type> statement
%type <type> statement_
%type <type> statements
%type <type> body
%type <type> variable optional_variable
%type <type> type
%type <type> parameter parameter_list parameters
%type <type> function_header
%type <type> function
%type <type> expressions
%type <typeList> expressions_raw
%type <type> list
%type <type> operand



%type <list> vector

%type <value> direction

%right EXPOP 
%left ADDOP
%left MULOP REMOP

%left OROP
%left ANDOP 
%right NOTOP


%%

function:
    function_header optional_variable body { result = 0; };

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
	IDENTIFIER ':' type {
		if (paramValues)
			scalars.insert($1, paramValues[paramIndex++]);
		else {
			appendError(GENERAL_SEMANTIC, "Missing parameter value for function.");
			scalars.insert($1, 0);
		}
	};

type:
	INTEGER {$$ = INT_TYPE;}|
	CHARACTER {$$ = CHAR_TYPE;}|
	REAL {$$ = REAL_TYPE;};

	
optional_variable:
	optional_variable variable|
	optional_variable error |
	%empty ;
    
variable:
   IDENTIFIER ':' type IS statement ';'
			{
			checkAssignment($3,$5, "Variable Initialization");
			symbols.insert($1,$3);
			} |
   IDENTIFIER ':' LIST OF type IS list ';'
			{
			Types finalType = checkListDeclaration($5, $7);
			listTypes.insert($1, finalType);
			} ;

list:
	'(' expressions ')'  {$$ = $2;};

vector:
       '(' ')' { $$ = new vector<double>(); };

expressions:
	expressions_raw { $$ = checkList(*$1); delete $1; };

expressions_raw:
	expressions_raw ',' expression {
		$1->push_back($3);
		$$ = $1;
	} |
	expression {
		$$ = new vector<Types>();
		$$->push_back($1);
	};

body:
	BEGIN_ statements END ';' {$$  = $2;} ;

statements:
	statements statement_ { $$ = $2 ;} |
	statement_ { $$ = $1;} |
	%empty {$$ = NONE;} ;

statement_:
	statement ';' |
	error ';'  {$$ = MISMATCH;} ;
    
statement:
	expression |
	if_statement |
	fold_statement | 
	when_statement  |
	switch_statement  ;

switch_statement:
    SWITCH expression IS cases ENDSWITCH {$$ = checkSwitch($2,$4,NONE);} |      
    SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH {
								$$ = checkSwitch($2, $4, $7);
								$$ = !isnan($4) ? $4 : $7;
								} ;  

when_statement:
	WHEN condition ',' expression ':' expression {
							$$ = checkWhen($4,$6);
							$$ = $2 ? $4 : $6;
							} ;



fold_statement:
    FOLD direction operator operand ENDFOLD
    {
        $$ = checkFold($4);
    };

direction:
	LEFT { $$ = 0.0; } |
	RIGHT { $$ = 1.0; }  ;

operator: 
	ADDOP | MULOP | RELOP;


operand:
    IDENTIFIER {
        $$ = find(listTypes, $1, "List");  // Return the type (INT_TYPE, CHAR_TYPE, etc)
    } |
    list {
        $$ = $1;  // list rule already returns type via expressions → checkList
    };

if_statement:
    IF condition THEN statements elsif_clauses optional_else ENDIF
    {
        $$ = checkIfStatement($4,$5,$6);
    };

elsif_clauses:
	elsif_clauses elsif_clause { $$ = $1 != NONE ? $1 : $2; } |
	%empty { $$ = NONE; };

elsif_clause:
	ELSIF condition THEN statements { $$ = $2 != NONE ? $4 : NONE; };

optional_else:
	ELSE statements { $$ = $2; } |
	%empty { $$ = NONE; };


cases:
	cases case { 
			$$ = checkCases($1,$2) ;
			} |
	%empty {$$ = NONE;} ;
	
case:
	CASE INT_LITERAL ARROW statements {
						$$ = $4 ;
						} |
	CASE error ARROW statements ';' | 
	CASE INT_LITERAL ARROW error ';' ;


condition:
	condition ANDOP relation {$$ = checkLogical($1, $3);} |
	condition OROP logical_and {$$ = checkLogical($1, $3); }|
	logical_and ;

logical_and:
	logical_and ANDOP logical_not {$$ = checkLogical($1,$3);}|
	logical_not ;

logical_not:
	NOTOP logical_not {$$ = checkNot($2);} |
	relation

relation:
	'(' condition ')' {$$ = $2;}|
	expression RELOP expression {$$ = checkRelational($1, $3);};

expression:
	expression ADDOP term   {
				$$ = checkArithmetic($1, $3 ) ;
				}
	| term;

term:
	term MULOP factor	{
				$$ = checkArithmetic($1, $3);
				} 
	| term REMOP factor	{	
				$$ = checkRemainder($1,$3);
				}
	| factor;

factor:
    primary |
    primary EXPOP factor { $$ = checkExponentiation($1, $3) ;} ;

primary:
    NEGOP primary           { $$ = checkNegation($2); }
  | '(' expression ')'      { $$ = $2; }
  | INT_LITERAL             { $$ = INT_TYPE; }
  | CHAR_LITERAL            { $$ = CHAR_TYPE; }
  | REAL_LITERAL            { $$ = REAL_TYPE; }
  | HEX_LITERAL             { $$ = INT_TYPE; }
  | IDENTIFIER '(' expression ')' {
      checkSubscript($3);
      $$ = find(listTypes, $1, "List");
  }
  | IDENTIFIER {
		$$ = find(symbols, $1, "Scalar");
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
	return NONE;
}
int main(int argc, char *argv[]) {
	firstLine();

	if (argc > 1) {
		paramValues = new double[argc - 1];
		for (int i = 1; i < argc; i++)
			paramValues[i - 1] = atof(argv[i]);
		paramIndex = 0; 
	} else {
		paramValues = nullptr;
		paramIndex = 0;  
	}

	yyparse();

	if (getTotalErrors() == 0)
		printf("Result = %.2f\n", result);

	lastLine();
	delete[] paramValues;
	return 0;
}
