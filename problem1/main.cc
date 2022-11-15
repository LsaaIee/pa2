#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;

int main(){
  string str;
  cin >> str;
  double decimal;
  cin >> decimal;
  Fraction fraction;
  
  
  fraction.str2Fraction(str);
  fraction.printAbbre();
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