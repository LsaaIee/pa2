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
    float add(float, float);
    float sub(float, float);
    float mul(float, float);
    float div(float, float);
    float mod(float, float);
    float exp(float, float);

    float get_N() const;
    float get_M() const;
    string get_oper() const;
    void set_N(float N);
    void set_M(float M);
    void set_oper(string oper);

    void slicer(string);

    Calculator();
};

#endif
