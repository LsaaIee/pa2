#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <iostream>
using namespace std;

class Fraction{
  private: 
    int N;
    int D;
    int NU;

  public:
    Fraction sum(Fraction);
    Fraction sum(double);
    Fraction multiply(Fraction);
    Fraction multiply(double);
    void abbreviation();
    bool toMixedNum();
    void print();
    double toDouble();
    Fraction str2Fraction(string);
    Fraction double2Fraction(double);
    
    int get_N() const;
    int get_D() const;
    int get_NU() const;
    void set_N(int N);
    void set_D(int D);
    void set_NU(int NU);
    
    Fraction();
    Fraction(double);
};

/*
class frac2 : public Fraction {
  public: 
    frac2(){
      decimal = 0.0;
    }
    frac2 double2Fraction(double);
    frac2(double decimal) : decimal(decimal) {}
  
  private:
    double decimal = 0.0;
};
*/
#endif
