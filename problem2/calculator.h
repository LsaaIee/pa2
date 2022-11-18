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
    float x;
    float y;
    float z;

  public:
    float add();
    float sub();
    float mul();
    float div();
    float mod();
    float exp();
    float addLetter();
    float subLetter();
    float mulLetter();
    float divLetter();
    float modLetter();
    float expLetter();
    float NCheck(float N);
    float MCheck(float M);

    void setValue(string oper);
    void toDouble(string oper);
};

#endif
