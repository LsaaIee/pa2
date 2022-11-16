#include <string>
using namespace std;
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
  //Write class definition here
  public:
    Calculator add();
    Calculator sub();
    Calculator mul();
    Calculator div();
    Calculator mod();
    Calculator exp();
    void print();
    Calculator();
  
  private:
    double N;
    double M;
    double result;
};

#endif
