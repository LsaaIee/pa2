#include <string>
using namespace std;
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
  //Write class definition here
  private: 
    float N;
    float M;
    string oper;

  public:
    float add();
    float sub();
    float mul();
    float div();
    float mod();
    float exp();
    
    void setValue(string oper);
    void print();
};

#endif
