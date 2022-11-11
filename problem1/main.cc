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
  
  //fraction.str2Fraction(frac1);
  size_t pos = 0;
  string delimiter = "/";
  string token[3];

  while ((pos = frac1.find(delimiter)) != string::npos){
      for (int i = 0; i < 3; i++){
        token[i] = frac1.substr(0, pos);
        frac1.erase(0, pos + delimiter.length());
      }
  }

  int N = stoi(token[0]);
  int NU = stoi(token[1]);
  int D = stoi(token[2]);
  

  fraction.abbreviation(N, NU, D);
  fraction.double2Fraction(frac2);
  //fraction.toMixedNum(frac2);

  return 0;
}