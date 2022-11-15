#include "fraction.h"
#include <iostream>
#include <string>

using namespace std;

//Implement Member Functions
/*
Fraction Fraction::sum(Fraction b){
    //Fraction fraction;
    int N = get_N();
    int D = get_D();
    int NU = get_NU();

    cout << N << endl;
    cout << D << endl;
    cout << NU << endl;
}

Fraction Fraction::sum(double b){

}

Fraction Fraction::multiply(Fraction b){

}

Fraction Fraction::multiply(double b){

}
*/
void Fraction::printAbbre(){
    Fraction fraction;
    fraction.set_N(N);
    fraction.set_D(D);
    fraction.set_NU(NU);

    fraction.abbreviation();
    fraction.print();
}

void Fraction::abbreviation(){
    int gcd;

    if (D == 0){
        cout << "Incorrect Input!" << endl;
    }

    for (int i = 1; i <=  D; ++i) {
        if (NU % i == 0 && D % i ==0) {
            gcd = i;
        }
    }

    NU = NU/gcd;
    D = D/gcd;

    set_N(N);
    set_D(D);
    set_NU(NU);
}

bool Fraction::toMixedNum(){
    if (NU >= D){
        N += (NU/D);
        NU = (NU/D)*D;
        if (NU == 0){
            D = 0;
        }
        return true;
    }
    else {
        if (NU == 0){
            D = 0;
            return true;
        }
        else {
            return false;
        }
    }
}

void Fraction::print(){
    cout << N << " and " << NU << "/" << D << endl;
}

double Fraction::toDouble(){
    double value;

    if (this->N < 0){
        value = this->NU/this->D;
    }
    else {
        NU += N*D;
        value = (double)NU/(double)D;
    }

    abbreviation();
    toMixedNum();
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(7);
    cout << value << endl;

    return value;
}

Fraction Fraction::str2Fraction(string frac1){
    size_t pos = 0;
    string delimiter = "/";
    string token[3];

    while ((pos = frac1.find(delimiter)) != string::npos){
        for (int i = 0; i < 3; i++){
        token[i] = frac1.substr(0, pos);
        frac1.erase(0, pos + delimiter.length());
        }
    }

    int fst = stoi(token[0]);
    int snd = stoi(token[1]);
    int thr = stoi(token[2]);

    set_N(fst);
    set_NU(snd);
    set_D(thr);
}

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}

Fraction Fraction::double2Fraction(double frac2){
    Fraction fraction;
    double fractionPart = frac2 - (long)frac2;
    int N = frac2 - fractionPart;

    const long pVal = 1000000000;
 
    // Calculate GCD of integral
    // equivalent of fractional
    // part and precision value
    long long gcdVal = gcd((fractionPart * pVal), pVal);
 
    // Calculate num and deno
    long long NU = (fractionPart * pVal) / gcdVal;
    long long D = pVal / gcdVal;
    
    fraction.set_N(N);
    fraction.set_NU(NU);
    fraction.set_D(D);

    // Print the fraction
    fraction.print();

    return fraction;
}

int Fraction::get_N() const {
    return N;
}
void Fraction::set_N(int N){
    this->N = N;
}
int Fraction::get_D() const {
    return D;
}
void Fraction::set_D(int D){
    this->D = D;
}
int Fraction::get_NU() const {
    return NU;
}
void Fraction::set_NU(int NU){
    this->NU = NU;
}

Fraction::Fraction(){
    N = 0;
    NU = 0;
    D = 0;
}
Fraction::Fraction(double decimal){
    Fraction fraction;
    fraction = double2Fraction(decimal);
    this->N = fraction.N;
    this->NU = fraction.NU;
    this->D = fraction.D;
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(7);
}