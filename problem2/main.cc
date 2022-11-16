#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

int main(){
  //write your code here
  Calculator calculator;
  string num1;
  string oper;
  string num2;
  cout << "Enter your equation to calculate: ";
  cin >> num1;
  cin >> oper;
  cin >> num2;

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
  return 0;
}
