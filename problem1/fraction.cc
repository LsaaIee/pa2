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
void Fraction::abbreviation(){
    int gcd;
    //Fraction fraction;

    int N = get_N();
    int D = get_D();
    int NU = get_NU();

    if (D == 0){
        cout << "Incorrect Input!" << endl;
    }
    else if (D > NU) {   
        int temp = D;
        D = NU;
        NU = temp;
    }
        
    for (int i = 1; i <=  D; ++i) {
        if (NU % i == 0 && D % i ==0) {
        gcd = i;
        }
    }

    NU = NU/gcd;
    D = D/gcd;

    cout << N << " and " << D << "/" << NU << endl;
    //fraction.print();
}
/*
bool Fraction::toMixedNum(int N, int NU, int D){
    
}

void Fraction::print(){
    int N = get_N();
    int D = get_D();
    int NU = get_NU();

    cout << N << " and " << D << "/" << NU << endl;
}
*/
double Fraction::toDouble(){
    double value; 
    double NU = get_NU();
    double D = get_D();
    double N = get_N();
    
    if (N < 0){
        value = NU/D;
    }
    else {
        NU += N*D;
        value = NU/D;
    }
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
    Fraction::set_N(fst);
    Fraction::set_NU(snd);
    Fraction::set_D(thr);

    //return Fraction::str2Fraction(frac1);
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
    //Fraction fraction;
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
 
    // Print the fraction
    //cout << (N * D) + NU << "/" << D << endl;
    cout << N << " and " << NU << "/" << D << endl;

    //return Fraction::double2Fraction(frac2);
    //fraction.print();
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