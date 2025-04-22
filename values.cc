// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the evaluation functions

#include <string>
#include <cmath>

using namespace std;

#include "values.h"
#include "listing.h"

double evaluateArithmetic(double left, Operators operator_, double right) {
    switch (operator_) {
        case ADD: return left + right;
        case SUBTRACT: return left - right;
        case MULTIPLY: return left * right;
        case DIVIDE: return right != 0 ? left / right : NAN;
        case REMAINDER: return fmod(left, right);
        case EXPONENT: return pow(left, right);
        default:
            appendError(SEMANTIC, "Unsupported arithmetic operator.");
            return NAN;
    }
}
double evaluateRelational(double left, Operators operator_, double right) {
    switch (operator_) {
        case LESS: return left < right;
        case GREATER: return left > right;
        case EQUAL: return left == right;
        case NOTEQUAL: return left != right;
        case LESSEQUAL: return left <= right;
        case GREATEREQUAL: return left >= right;
        default:
            appendError(SEMANTIC, "Unsupported relational operator.");
            return false;
    }
}
double evaluateNegation(double value){
    return -value;
}
double evaluateFold(int dir, Operators op, const vector<double>& vals) {
    if (vals.empty()) {
        appendError(GENERAL_SEMANTIC, "Fold on empty list");
        return 0.0;
    }
    if (dir == 0) {                // 0 means “LEFT”
        double acc = vals[0];
        for (size_t i = 1; i < vals.size(); ++i)
            acc = evaluateArithmetic(acc, op, vals[i]);
        return acc;
    }
    else {                         
        double acc = vals.back();
        for (size_t i = vals.size() - 1; i-- > 0; )
            acc = evaluateArithmetic(vals[i], op, acc);
        return acc;
    }
}
