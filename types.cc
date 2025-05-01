
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
	if ((left == INT_TYPE && right == REAL_TYPE) ||
	    (left == REAL_TYPE && right == INT_TYPE) ||
	    (left == REAL_TYPE && right == REAL_TYPE))
		return REAL_TYPE;

	appendError(GENERAL_SEMANTIC, "Incompatible types for arithmetic operation");
	return MISMATCH;
}


Types checkRelational(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;

	//integer comparison
	if (left == INT_TYPE && right == INT_TYPE)
		return INT_TYPE;

	// Allow compare of characters
	if (left == CHAR_TYPE && right == CHAR_TYPE)
		return INT_TYPE;

	// Do not allow char to int oor real to char 
	if ((left == CHAR_TYPE || right == CHAR_TYPE)) {
		appendError(GENERAL_SEMANTIC, "Character Comparison With Non-Character");
		return MISMATCH;
	}

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

//step 6 checking subscript 
Types checkSubscript(Types indexType) {
    if (indexType != INT_TYPE && indexType != MISMATCH) {
        appendError(GENERAL_SEMANTIC, "List Subscript Must Be Integer");
        return MISMATCH;
    }
    return indexType;
}

//step 5 variable check
Types checkListDeclaration(Types declaredElementType, Types actualElementType) {
    if (declaredElementType == MISMATCH || actualElementType == MISMATCH)
        return MISMATCH;
    if (declaredElementType != actualElementType) {
        appendError(GENERAL_SEMANTIC, "List Type Does Not Match Element Types");
        return MISMATCH;
    }
    return declaredElementType;
}

Types checkList(vector<Types>& elements) {
	if (elements.empty())
		return MISMATCH;

	Types first = elements[0];
	for (size_t i = 1; i < elements.size(); ++i) {
		if (elements[i] == MISMATCH)
			return MISMATCH;
		if (elements[i] != first) {
			appendError(GENERAL_SEMANTIC, "List Elements Have Mismatched Types");
			return MISMATCH;
		}
	}
	return first;
}

Types find(Symbols<Types>& table, CharPtr identifier, string tableName) {
    Types type;
    if (!table.find(identifier, type)) {
        appendError(GENERAL_SEMANTIC, tableName + " " + identifier);
        return MISMATCH;
    }
    return type;
}
