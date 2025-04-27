// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the functions that produces the 
// compilation listing
// 
//
// jonathan apolaya
// CMSC 430 
// provides the logic for the functions saving error messaging 
// and displaying the proper message for that line
// will keep track of each type of error as well 
// WARNING:  compiler gives warning unused variable. 

#include <cstdio>
#include <string>

#include <vector> 
#include "listing.h"

using namespace std;


static int lineNumber;
static string error = "";
static int totalErrors = 0;
//keep track of each type of error individually 
static int syntaxErrors = 0 ;
static int sematicErrors = 0 ;
static int lexerErrors = 0 ;
static int globalIndex = 0 ;
std::vector<std::string> errorMessages;

static void displayErrors();

int getTotalErrors() {
    return totalErrors;
}

void firstLine()
{
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}

void nextLine()
{
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}

int lastLine()
{
	//here
	printf("\r");
	printf("\n");
	displayErrors();
	if (totalErrors > 0){
		printf("\n");
		printf("Lexical Errors: %d\n", lexerErrors);    // Changed from totalErrors
		printf("Syntax Errors: %d\n", syntaxErrors);    // Now shows actual count
		printf("Semantic Errors: %d\n", sematicErrors); // Now shows actual count
	}
	else {
		printf("Compiled Successfully\n");
	}
	printf("     \n");
		return totalErrors;	
	//here
}
    
void appendError(ErrorCategories errorCategory, string message)

{
	string messages[] = { 
        "Lexical Error, Invalid Character ", 
        "Syntax Error, ",  // Added syntax error message
        "Semantic Error, ", 
        "Semantic Error, Duplicate ",
        "Semantic Error, Undeclared " 
    };

    switch (errorCategory){
        case LEXICAL: 
            lexerErrors++;
            break;
        case SYNTAX:  
            syntaxErrors++; 
            break;
	case SEMANTIC:
	    sematicErrors++;
        case GENERAL_SEMANTIC: 
        case DUPLICATE_IDENTIFIER:
        case UNDECLARED_IDENTIFIER:
            sematicErrors++;
            break;
    }

    error = messages[errorCategory] + message;
    errorMessages.push_back(error);
    totalErrors++;	
	//here end 
}

void displayErrors()
{
	int size = errorMessages.size();
	//if (error != "")
	//	printf("%s\n", error.c_str());
	//error = "";

	//mine
	if (globalIndex != size){

		for (;globalIndex < size ; globalIndex++){
			printf("%s\n", errorMessages[globalIndex].c_str());
		}

	}
}

