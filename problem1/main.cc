#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;

int main(){
  string frac1;
  double frac2;
  Fraction fraction;

  getline(cin, frac1);
  cin >> frac2;
  
  fraction.str2Fraction(frac1);
  fraction.abbreviation();
  fraction.double2Fraction(frac2);
  fraction.toDouble();

  return 0;
}