
// CMSC 430 Compiler Theory and Design
// Project 4 Skeleton
// UMGC CITE
// Summer 2023

// This file contains type definitions and the function
// prototypes for the type checking functions

#ifndef types_h
#define types_h
#include <string>
#include "symbols.h"

typedef char* CharPtr;


enum Types {MISMATCH, INT_TYPE, CHAR_TYPE, REAL_TYPE, NONE};

void checkAssignment(Types lValue, Types rValue, string message);
Types checkWhen(Types true_, Types false_);
Types checkSwitch(Types case_, Types when, Types other);
Types checkCases(Types left, Types right);
Types checkArithmetic(Types left, Types right);
Types checkRelational(Types left , Types right);
Types checkLogical(Types left, Types right);
Types checkNot(Types operand);
Types checkExponentiation(Types base, Types exponent);
Types checkFold(Types elementType);
Types checkList(vector<Types>& elements) ;
Types checkSubscript(Types indexType);
Types checkListDeclaration(Types declaredElementType, Types actualElementType);
Types checkNegation(Types operand);
Types find(Symbols<Types>& table, CharPtr identifier , string tableName);
Types checkRemainder(Types left, Types right);
Types checkIfStatement(Types thenType, Types elsifType, Types elseType);
#endif 
