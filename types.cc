
// CMSC 430 Compiler Theory and Design
// Project 4 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the type checking functions

#include <string>
#include <vector>

using namespace std;

#include "types.h"
#include "listing.h"

void checkAssignment(Types lValue, Types rValue, string message) {
	if (lValue != MISMATCH && rValue != MISMATCH && lValue != rValue)
		appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
}

Types checkWhen(Types true_, Types false_) {
	if (true_ == MISMATCH || false_ == MISMATCH)
		return MISMATCH;
	if (true_ != false_)
		appendError(GENERAL_SEMANTIC, "When Types Mismatch ");
	return true_;
}

Types checkSwitch(Types case_, Types when, Types other) {
	if (case_ != INT_TYPE)
		appendError(GENERAL_SEMANTIC, "Switch Expression Not Integer");
	return checkCases(when, other);
}

Types checkCases(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == NONE || left == right)
		return right;
	appendError(GENERAL_SEMANTIC, "Case Types Mismatch");
	return MISMATCH;
}

Types checkArithmetic(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == INT_TYPE && right == INT_TYPE)
		return INT_TYPE;
	appendError(GENERAL_SEMANTIC, "Integer Type Required");
	return MISMATCH;
}
// Checks types for relational operators (<, >, ==, etc.)
Types checkRelational(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == INT_TYPE && right == INT_TYPE)
		return INT_TYPE;  // relational returns integer (true/false as 1/0)
	appendError(GENERAL_SEMANTIC, "Relational Operator Requires Integer Operands");
	return MISMATCH;
}

// Checks types for logical AND, OR operations
Types checkLogical(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == INT_TYPE && right == INT_TYPE)
		return INT_TYPE;  // logical ops return integers 1 or 0
	appendError(GENERAL_SEMANTIC, "Logical Operator Requires Integer Operands");
	return MISMATCH;
}

// Checks type for logical NOT operation
Types checkNot(Types operand) {
	if (operand == MISMATCH)
		return MISMATCH;
	if (operand == INT_TYPE)
		return INT_TYPE;
	appendError(GENERAL_SEMANTIC, "Logical NOT Requires Integer Operand");
	return MISMATCH;
}

// Checks types for exponentiation ^
Types checkExponentiation(Types base, Types exponent) {
	if (base == MISMATCH || exponent == MISMATCH)
		return MISMATCH;
	if (base == INT_TYPE && exponent == INT_TYPE)
		return INT_TYPE;
	appendError(GENERAL_SEMANTIC, "Exponentiation Requires Integer Operands");
	return MISMATCH;
}

// Optional: if you want specific checking inside FOLD statements
Types checkFold(Types elementType) {
	if (elementType == MISMATCH)
		return MISMATCH;
	if (elementType == INT_TYPE)
		return INT_TYPE;
	appendError(GENERAL_SEMANTIC, "Fold Requires List of Integers");
	return MISMATCH;
}

