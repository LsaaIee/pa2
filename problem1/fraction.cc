#include "fraction.h"
#include <iostream>
#include <string>

using namespace std;

//Implement Member Functions
/*void Fraction::sum(Fraction b){

}

void Fraction::sum(double b){

}

void Fraction::multiply(Fraction b){

}

void Fraction::multiply(double b){

}
*/
void Fraction::abbreviation(int N, int NU, int D){
    int gcd;
    Fraction fraction;

    if (D == 0){
        cout << "Incorrect Input!" << endl;
    }

    if (D > NU) {   
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

    fraction.print(N, NU, D);
}
/*
bool Fraction::toMixedNum(int N, int NU, int D){
    
}
*/
void Fraction::print(int N, int NU, int D){
    cout << N << " and " << D << "/" << NU << endl;
}
/*
double Fraction::toDouble(){

}

Fraction::str2Fraction(string frac1){
    size_t pos = 0;
    string delimiter = "/";
    string token[3];

    while ((pos = frac1.find(delimiter)) != string::npos){
        for (int i = 0; i < 3; i++){
        token[i] = frac1.substr(0, pos);
        frac1.erase(0, pos + delimiter.length());
        }
    }
    int N = stoi(token[0]);
    int NU = stoi(token[1]);
    int D = stoi(token[2]);
}
*/

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

double Fraction::double2Fraction(double frac2){
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
 
    // Print the fraction
    //cout << (N * D) + NU << "/" << D << endl;

    fraction.print(N, D, NU);
    return true;
}
