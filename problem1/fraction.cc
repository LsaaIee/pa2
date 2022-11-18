#include "fraction.h"
#include <iostream>
#include <string>

using namespace std;

//Implement Member Functions

Fraction Fraction::sum(Fraction b){
    Fraction obj;
    obj.set_N(N);
    obj.set_NU(NU);
    obj.set_D(D);

    obj.N += N;
    obj.NU += NU;

    if (obj.NU >= obj.D){
        if (obj.NU%obj.D == 0){
            obj.N += obj.NU/obj.D;
            obj.NU = 0;
            obj.D = 0;
        }
        else if (obj.NU%obj.D != 0){
            obj.N += obj.NU/obj.D;
            obj.NU -= obj.D;
        }
    }
    obj.abbreviation();
    obj.print();

    return obj;
}

Fraction Fraction::sum(double b){
    Fraction fraction(b);
    if (fraction.NU == 0 && fraction.D == 0){
        fraction.NU = fraction.N;
        fraction.N = 0;
        fraction.D = 1;
    }
    if (this->NU == 0 && this->D == 0){
        this->NU = this->N;
        this->N = 0;
        this->D = 1;
    }
    
    fraction.N += this->N;
    fraction.NU *= this->D;
    fraction.NU += fraction.D*this->NU;
    fraction.D *= this->D;

    if (fraction.NU >= fraction.D){
        if (fraction.NU%fraction.D == 0){
            fraction.N += fraction.NU/fraction.D;
            fraction.NU = 0;
            fraction.D = 0;
        }
        else if (fraction.NU%fraction.D != 0){
            fraction.N += fraction.NU/fraction.D;
            fraction.NU -= fraction.D;
        }
    }
    fraction.abbreviation();
    fraction.toMixedNum();
    fraction.print();
}

Fraction Fraction::multiply(Fraction b){
    Fraction fraction;
    fraction = b;
    if (fraction.NU == 0 && fraction.D == 0){
        fraction.NU = fraction.N;
        fraction.N = 0;
        fraction.D = 1;
    }
    if (this->NU == 0 && this->D == 0){
        this->NU = this->N;
        this->N = 0;
        this->D = 1;
    }
    
    this->NU += this->N*this->D;
    fraction.NU += fraction.N*fraction.D;
    fraction.N = 0;
    this->N = 0;

    fraction.D *= this->D;
    fraction.NU *= this->NU;

    fraction.abbreviation();
    fraction.toMixedNum();
    fraction.print();
}

Fraction Fraction::multiply(double b){
    Fraction fraction(b);
    if (fraction.NU == 0 && fraction.D == 0){
        fraction.NU = fraction.N;
        fraction.N = 0;
        fraction.D = 1;
    }
    if (this->NU == 0 && this->D == 0){
        this->NU = this->N;
        this->N = 0;
        this->D = 1;
    }

    this->NU += this->N*this->D;
    fraction.NU += fraction.N*fraction.D;
    fraction.N = 0;
    this->N = 0;

    fraction.D *= this->D;
    fraction.NU *= this->NU;

    fraction.abbreviation();
    fraction.toMixedNum();
    fraction.print();
}

void Fraction::abbreviation(){
    int gcd;

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
        NU = NU%D;
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

    if (N < 0){
        value = NU/D;
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
    int token[3];
    int i = 0;
    
    while ((pos = frac1.find('/')) != string::npos){
        /*for (int i = 0; i < 3; i++){
            if (i == 2){
                //token[i] = frac1;
                token[i] = stof(frac1);
            }
            else {
                //token[i] = frac1.substr(0, pos);
                
            }
        }*/
        token[i] = stof(frac1);
        frac1.erase(0, pos + delimiter.length());
        i++;
    }
    token[i] = stof(frac1);
    /*
    int fst = stof(token[0]);
    int snd = stof(token[1]);
    int thr = stof(token[2]);
*/
    int fst = (token[0]);
    int snd = (token[1]);
    int thr = (token[2]);

    if (thr == 0){
        cout << "Answer: Invalid input" << endl;
        exit(1);
    }
    else {
        set_N(fst);
        set_NU(snd);
        set_D(thr);
    }
    abbreviation();
    toMixedNum();
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
    if (frac2 < 48 || frac2 > 57){
        if (frac2 == 46){
            cout << "Answer: Invalid input" << endl;
            exit(1);
        }
    }
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

    if (fraction.NU == 0){
        fraction.D = 0;
    }

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