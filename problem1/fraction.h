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
    void abbreviation();
    bool toMixedNum(int, int, int);
    void print(int, int, int);
    double toDouble();
    //Fraction str2Fraction(string);
    void double2Fraction(double);
    int get_N() const;
    int get_D() const;
    int get_NU() const;
    void set_N(int N);
    void set_D(int D);
    void set_NU(int NU);
};

#endif
