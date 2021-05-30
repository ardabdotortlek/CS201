#pragma once
#include <iostream>
#include "Stack.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

string infix2prefix(const string exp);
double evaluatePrefix(const string exp);
bool isBalancedInfix(const string exp);
void evaluateInputPrefixExpression();
int precedence(int ch);
bool isOperator(int ch);
