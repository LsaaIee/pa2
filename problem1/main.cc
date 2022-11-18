#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;

int main(){
  string str;
  double decimal;
  cin >> str;
  int len = str.length();
  for (int i = 0; i < len; i++){
    if (str[i] < 47 || str[i] > 57){
      cout << "Answer: Invalid input" << endl;
      return 0;
    }
  }
  cin >> decimal;
  if (decimal < 48 || decimal > 57){
    if (decimal == 46){
      cout << "Answer: Invalid input" << endl;
      return 0;
    }
  }
  Fraction fraction;
  
  fraction.str2Fraction(str);
  fraction.print();
  Fraction frac2(decimal);
  frac2.print();
  fraction.sum(fraction);
  fraction.sum(decimal);
  frac2.multiply(fraction);
  frac2.multiply(decimal);
  fraction.toDouble();
  frac2.toDouble();

  return 0;
}