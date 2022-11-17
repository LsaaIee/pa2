#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>

using namespace std;

//Implement Member Functions
/*
float Calculator::add(){
    return a + b;
}
float Calculator::sub(){
    return a - b;
}
float Calculator::mul(){
    return a * b;
}
float Calculator::div(){
    if (b == 0){
        cout << "Invalid input!" << endl;
        return INFINITY;
    }
    else {
        return a / b;
    }
}

float Calculator::mod(){
    cout << a%b << endl;
    return a % b;
}

float Calculator::exp(){
    for (int i = 0; i <= b; i++){
        a = a*b;
    }
    return a;
}
*/
float Calculator::get_N() const {
    return N;
}
float Calculator::get_M() const {
    return M;
}
string Calculator::get_oper() const {
    return oper;
}
void Calculator::set_N(float N){
    this->N = N;
}
void Calculator::set_M(float M){
    this->M = M;
}
void Calculator::set_oper(string oper){
    this->oper = oper;
}

void Calculator::slicer(string operation){
    int num1;
    string oper;
    int num2;
    int len = operation.length();
    char c[len];
    
    for (int i = 0; i < len; i++){
        c[i] = operation[i];
        if (!(c[i] >= 48 && c[i] <= 57) && c[i] != '+' && c[i] != '-' && c[i] != '*' && c[i] != '/' && c[i] != '%' && c[i] != '^' && c[i] != ' '){
            cout << "Invalid input!" << endl;
            exit(1);
        }
        else {
            num1 = stoi(operation);
        }
        switch (c[i]){
        case '+':
            oper = '+';
            num2 = stoi(operation);
            break;
        case '-':
            oper = '-';
            num2 = stoi(operation);
            break;
        case '*':
            oper = '*';
            num2 = stoi(operation);
            break;
        case '/':
            oper = '/';
            num2 = stoi(operation);
            break;
        case '%':
            oper = '%';
            num2 = stoi(operation);
            break;
        case '^':
            oper = '^';
            num2 = stoi(operation);
            break;
        }
    }
}

//letter error 처리. stoi하면 첫번째 숫자 나오고 중간 operator 찾고 저장하고 나서 그 다음거를 substr로 뽑아오고. 그걸 stoi하면 2번쨰 숫자 나옴.

Calculator::Calculator(){
    M = 0.0;
    N = 0.0;
    oper = "";
}