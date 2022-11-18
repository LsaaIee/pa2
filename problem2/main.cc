#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

int main(){
  //write your code here
  Calculator calculator;
  string operation;

  cout << "Enter your equation to calculate: ";
  getline(cin, operation);
  calculator.setValue(operation);
  //calculator.print();
  return 0;
}
