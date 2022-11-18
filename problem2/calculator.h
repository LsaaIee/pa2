#include <string>
using namespace std;
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
  //Write class definition here
  private: 
    float N;
    float M;
    string operation;
    float x;
    float y;
    float z;
    float forX;
    float forY;
    float forZ;
    int len;
    float result;

  public:
    float add();
    float sub();
    float mul();
    float div();
    float mod();
    float exp();
    float addLetter(float, float);
    float subLetter(float, float);
    float mulLetter(float, float);
    float divLetter(float, float);
    float modLetter(float, float);
    float expLetter(float, float);
    float numCheck(float N);

    void setValue(string oper);
    void print();
};

#endif
