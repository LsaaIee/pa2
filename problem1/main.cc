#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;

int main(){
  string str;
  getline(cin, str);
  double decimal;
  cin >> decimal;
  Fraction fraction;
  
  
  fraction.str2Fraction(str);
  fraction.printAbbre();
  //fraction.double2Fraction(decimal);
  Fraction frac2(decimal);
  fraction.toDouble();
  frac2.toDouble();

  return 0;
}