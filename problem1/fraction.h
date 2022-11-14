#ifndef FRACTION_H
#define FRACTION_H
#include <string>
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

    void printAbbre();
};

class frac1: public Fraction{
  public:
    
}

#endif
