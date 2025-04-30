// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains type definitions and the function
// definitions for the evaluation functions

#ifndef VALUES_H
#define VALUES_H

typedef char* CharPtr;


enum Operators {ADD, MULTIPLY, LESS, AND, SUBTRACT, DIVIDE, EXPONENT, NEGATE, REMAINDER, GREATER , EQUAL, NOTEQUAL, GREATEREQUAL, LESSEQUAL, OR, NOT };
double evaluateArithmetic(double left, Operators operator_, double right);
double evaluateRelational(double left, Operators operator_, double right);
double evaluateNegation(double value);
//double evaluateFold(int dir, Operators op, const vector<double>& vals);

#endif

