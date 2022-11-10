#ifndef FRACTION_H
#define FRACTION_H

class Fraction{
  private: 
    int N;
    int D;
    int NU;

  public:
    Fraction sum(Fraction b);
    Fraction sum(double b);
    Fraction multiply(Fraction b);
    Fraction multiply(double b);
    void abbreviation();
    bool toMixedNum();
    void print();
    double toDouble();
    Fraction str2Fraction(string str);
    Fraction double2Fraction(double val);
};

made a change

#endif
