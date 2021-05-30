#include <iostream>
#include "StrangeCalculator.h"
using namespace std;

int main(){
cout << "prefix of: 5+6 is: " << infix2prefix("5+6") << endl;
cout << "prefix of: 5+6*7 is: " << infix2prefix("5+6*7") << endl;
cout << "prefix of: 5+6*(7/2) is: " << infix2prefix("5+6*(7/2)") << endl;
cout << "prefix of: (5+6)*(7/2) is: " << infix2prefix("(5+6)*(7/2)") << endl;
cout << "prefix of: (5+6)*(7/2)-5+7*(8*2) is: " << infix2prefix("(5+6)*(7/2)-5+7*(8*2)") << endl;
cout<< "Checkpoint 1" << endl;
cout << "result of: 5+6 is: " << evaluatePrefix( infix2prefix("5+6")) << endl;
cout << "result of: 5+6*7 is: " << evaluatePrefix( infix2prefix("5+6*7")) << endl;
cout << "result of: 5+6*(7/2) is: " << evaluatePrefix(infix2prefix("5+6*(7/2)")) << endl;
cout << "result of: (5+6)*(7/2) is: " << evaluatePrefix( infix2prefix("(5+6)*(7/2)")) << endl;
cout << "result of: (5+6)*(7/2)-5+7*(8*2) is: " << evaluatePrefix(infix2prefix("(5+6)*(7/2)-5+7*(8*2)")) << endl;
cout << "Checkpoint 2" << endl;
cout << isBalancedInfix( "((5+7" ) << endl;
cout << isBalancedInfix( "((5+7)))" ) << endl;
cout << isBalancedInfix( "(5+4" ) << endl;
cout << isBalancedInfix( "(5+4)*3-4*(9+8))" ) << endl;
cout << isBalancedInfix( "(5+4)*3-(4*(9+8))" ) << endl;

evaluateInputPrefixExpression();
return 0;
}
