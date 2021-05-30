#include <iostream>
#include "StrangeCalculator.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

/**
    Converts infix to prefix
    @param exp
    @return prefix
*/
string infix2prefix(const string exp){
    Stack stackPrefix;
    string prefix = "";
    for(int i = exp.length()-1; i>=0; i--){
        char ch = exp[i];

        if(isOperator((int)ch)){
            double top;
            stackPrefix.getTop(top);

            while(!stackPrefix.isEmpty() && (char)top != ')' && precedence((int) ch) < precedence(top)){
                stackPrefix.pop(top);
                prefix = (char)top + prefix;
                stackPrefix.getTop(top);
            }
            stackPrefix.push((int)ch);
        }

        else if(ch == ')'){
            stackPrefix.push((int)ch);
        }

        else if(ch == '('){
            double top;
            stackPrefix.getTop(top);
            while ((char)top != ')'){
                stackPrefix.pop(top);
                prefix = (char)top + prefix;
                stackPrefix.getTop(top);
            }
            stackPrefix.pop();
        }

        else{
            prefix = ch + prefix;
        }
    }

    while(!stackPrefix.isEmpty()){
        double top;
        stackPrefix.pop(top);
        prefix = (char)top + prefix;
    }

    return prefix;
}

/**
    Calculates the arithmetic operation given in prefix
    @param exp
    @return result
*/
double evaluatePrefix( const string exp ){
    Stack stackPrefix;
    double result = 0;
    for(int i = exp.length()-1; i >= 0; i--){
        char ch = exp[i];
        if(isOperator((int)ch)){
           double operand1;
           double operand2;
           stackPrefix.getTop(operand1);
           stackPrefix.pop();
           stackPrefix.getTop(operand2);
           stackPrefix.pop();

           if(ch == '+'){
            result = operand1 + operand2;
           }
           else if(ch == '-'){
            result = operand1 - operand2;
           }
           else if(ch == '*'){
            result = operand1 * operand2;
           }
           else{
            result = operand1 / operand2;
           }
           stackPrefix.push(result);
        }

        else{
            stackPrefix.push(ch - '0');
        }
    }

    stackPrefix.pop(result);
    return result;
}

/**
    Checks whether brackets in given string are balanced
    @param exp
    @return true if it is balanced
*/
bool isBalancedInfix(const string exp){
    Stack aStack;
    bool balancedSoFar = true;
    int i = 0;
    char ch;

    while ( balancedSoFar  and  i < exp.length() ){
       ch = exp[i];
       ++i;

       if ( ch == '(' )
          aStack.push( (double)'(' );
       else if ( ch == ')' )
          if ( !aStack.isEmpty() )
             aStack.pop();
          else
             balancedSoFar = false;

    }
    if ( balancedSoFar  and  aStack.isEmpty() )
       return true;
    else
       return false;

}

/**
    Takes input, removes the spaces of the input, then calculates the arithmetic operation
*/
void evaluateInputPrefixExpression(){
    string input;
    cout << "Please enter an input: ";
    getline(cin, input);

    string updatedInput = "";
    for(int i = 0; i < input.length(); i++){
        if(input[i] != ' '){
            updatedInput = updatedInput + input[i];
        }
    }

    if(!isBalancedInfix(updatedInput)){
        cout << "This infix is not balanced" << endl;
        return;
    }
    cout << "The result for given input is " << evaluatePrefix(infix2prefix(updatedInput)) << endl;
}

/**
    @param ch
    @return precedence value of given char
*/
int precedence(int ch){
    if((char)ch == '+' || (char)ch == '-')
        return 1;
    else
        return 2;
}

/**
    @param ch
    @return true if the given ch is operator
*/
bool isOperator(int ch){
    return ((char)ch == '+' || (char)ch == '-') || ((char)ch == '*' || (char)ch == '/');
}
