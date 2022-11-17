#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

int main(){
  //write your code here
  Calculator calculator;

  string operation;
  /*아래에 있는 코드를 아예 함수에 넣어서 구현하는 것도 좋을듯..?*/
  while (1){
    cout << "Enter your equation to calculate: ";
    getline(cin, operation);
    calculator.slicer(operation);

    switch (oper)
    {
      case '+':
        calculator.add();
        break;
      
      case '-':
        calculator.sub();
        break;

      case '*':
        calculator.mul();
        break;

      case '/':
        calculator.div();
        break;
      
      case '%':
        calculator.mod();
        break;
      
      case '^':
        calculator.exp();
        break;
      
      case '-':
        calculator.sub();
        break;
    }    
  }
  */
  return 0;
}
