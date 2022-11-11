#ifndef FRACTION_H
#define FRACTION_H

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
    void abbreviation(int, int, int);
    bool toMixedNum(int, int, int);
    void print(int, int, int);
    double toDouble();
    Fraction str2Fraction(string);
    double double2Fraction(double);
};

#endif
