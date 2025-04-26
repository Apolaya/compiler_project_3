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
Symbols<Types> lists;


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
%type <value> expression term factor primary relation condition logical_and logical_not
%type <value> direction
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

%type <list> vector
%type <list> list expressions
%type <list> operand

%right EXPOP 
%left ADDOP
%left MULOP REMOP

%left OROP
%left ANDOP 
%right NOTOP


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
	IDENTIFIER ':' type {
		if (paramValues)
			scalars.insert($1, paramValues[paramIndex++]);
		else {
			appendError(GENERAL_SEMANTIC, "Missing parameter value for function.");
			scalars.insert($1, 0);
		}
	};

type:
	INTEGER |
	CHARACTER |
	REAL;

	
optional_variable:
	optional_variable variable|
	optional_variable error |
	%empty ;
    
variable:
   IDENTIFIER ':' type IS statement ';'
			{
			checkAssignment($3,$5, "Variable Initialization");
			scalars.insert($1, $5);
			} |
   IDENTIFIER ':' LIST OF type IS list ';'
			{
			lists.insert($1, $7);
			} ;

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
	statements statement_ { $$ = $2 ;} |
	statement_ { $$ = $1;} |
	%empty ;

statement_:
	statement ';' |
	error ';'  {$$ = 0;} ;
    
statement:
	expression |
	if_statement |
	fold_statement | 
	when_statement {$$ = chekcWhen($4,$6);} |
	switch_statement {$$ = checkSwitch($2, $4, $7);} ;

switch_statement:
    SWITCH expression IS cases ENDSWITCH |      
    SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH {$$ = !isnan($4) ? $4 : $7;} ;  

when_statement:
	WHEN condition ',' expression ':' expression {$$ = $2 ? $4 : $6;} ;


fold_statement:
    FOLD direction operator operand ENDFOLD
    {
        int dir = (int) (yyvsp[-3].value);
        /* $3.oper is your Operators enum, $4.list is the vector<double>* */
        (yyval.value) = evaluateFold(dir, (yyvsp[-2].oper), * (yyvsp[-1].list));
    };

direction:
	LEFT { $$ = 0.0; } |
	RIGHT { $$ = 1.0; }  ;

operator: 
	ADDOP | MULOP | RELOP;

operand:
    list {
        $$ = $1;
    } | 
    IDENTIFIER {
        vector<double>* lst;
        if (!lists.find($1, lst)) {
            appendError(UNDECLARED_IDENTIFIER, $1);
            $$ = new vector<double>();
        } else {
            $$ = lst;
        }
    } ;

if_statement:
	IF condition THEN statements elsif_clauses optional_else ENDIF
	{
		if ($2) $$ = $4;
		else if (!isnan($5)) $$ = $5;
		else $$ = $6;
	};

elsif_clauses:
	elsif_clauses elsif_clause { $$ = !isnan($1) ? $1 : $2; } |
	%empty { $$ = NAN; };

elsif_clause:
	ELSIF condition THEN statements { $$ = $2 ? $4 : NAN; };

optional_else:
	ELSE statements { $$ = $2; } |
	%empty { $$ = NAN; };


cases:
	cases case { 
			$$ = !isnan($1) ? $1 : $2 ;
			$$ = checkCases($1,$2) ;
			} |
	%empty {$$ = NAN;} ;
	
case:
	CASE INT_LITERAL ARROW statements {
						$$ = $<value>-2 == $2 ? $4 : NAN; 
						$$ = $4 ;
						} |
	CASE error ARROW statements ';' | 
	CASE INT_LITERAL ARROW error ';' ;


condition:
	condition ANDOP relation {$$ = $1 && $2;} |
	condition OROP logical_and {$$ = $1 && $3;} |
	logical_and ;

logical_and:
	logical_and ANDOP logical_not {$$ = $1 && $3; }|
	logical_not ;

logical_not:
	NOTOP logical_not {$$ = !$2; } |
	relation

relation:
	'(' condition ')' {$$ = $2;}|
	expression RELOP expression {$$ = evaluateRelational($1, $2, $3);};

expression:
	expression ADDOP term   {
				$$ = checkArtithmetic($1, $3) ;
				$$ = evaluateArithmetic($1, $2, $3); 
				}
	| term;

term:
	term MULOP factor	{
				$$ = checkArithmetic($1, $3);
				$$ = evaluateArithmetic($1, $2, $3);
				} 
	| term REMOP factor	{	
				$$ = evaluateArithmetic($1, REMAINDER, $3); 
				}
	| factor;

factor:
    primary |
    primary EXPOP factor { $$ = evaluateArithmetic($1, EXPONENT, $3); } ;

primary:
    NEGOP primary           { $$ = evaluateNegation($2); }
  | '(' expression ')'      { $$ = $2; }
  | INT_LITERAL             { $$ = $1; }
  | CHAR_LITERAL            { $$ = $1; }
  | REAL_LITERAL            { $$ = $1; }
  | HEX_LITERAL             { $$ = $1; }
  | IDENTIFIER '(' expression ')' { $$ = extract_element($1, $3); }
  | IDENTIFIER {
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

	if (argc > 1) {
		paramValues = new double[argc - 1];
		for (int i = 1; i < argc; i++)
			paramValues[i - 1] = atof(argv[i]);
		paramIndex = 0; // ✅ set after values are loaded
	} else {
		paramValues = nullptr;
		paramIndex = 0;  // still set for consistency
	}

	yyparse();

	if (getTotalErrors() == 0)
		printf("Result = %.2f\n", result);

	lastLine();
	delete[] paramValues;
	return 0;
}
