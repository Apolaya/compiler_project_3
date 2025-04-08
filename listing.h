// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the function prototypes for the functions that produce
// the compilation listing
//
// jonathan apolaya 
// CMSC 430
//
//
#include <iostream>
enum ErrorCategories {LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER,
	UNDECLARED_IDENTIFIER};


void firstLine();
void nextLine();
int lastLine();
//change the String to std :: ??
void appendError(ErrorCategories errorCategory, std::string message);

