#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
#include <algorithm>

using namespace std;

//Implement Member Functions
float Calculator::add(){
    float result = N + M;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::addLetter(){
    float result = x + x;
    cout << "Answer: " << result << endl;
    return result;
}

float Calculator::sub(){
    float result = N - M;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::subLetter(){
    float result = x - x;
    cout << "Answer: " << result << endl;
    return result;
}

float Calculator::mul(){
    float result = N * M;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::mulLetter(){
    float result = x * x;
    cout << "Answer: " << result << endl;
    return result;
}

float Calculator::div(){
    float result = N / M;
    if (M == 0){
        cout << "Answer: Operation disallowed" << endl;
        exit(1);
    }
    else {
        cout << "Answer: " << result << endl;
    }
    return result;
}
float Calculator::divLetter(){
    float result = 1;
    if (x == 0){
        cout << "Answer: Operation disallowed" << endl;
        exit(1);
    }
    else {
        cout << "Answer: " << result << endl;
    }
    return result;
}

float Calculator::mod(){
    int a = (int)N;
    int b = (int)M;
    int result = a%b;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::modLetter(){
    float result = 0;
    cout << "Answer: " << result << endl;
    return result;
}

float Calculator::exp(){
    float result = 1;
    while (M != 0){
        result *= N;
        --M;
    }
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::expLetter(){
    float result = 1;
    while (M != 0){
        result *= N;
        --M;
    }
    cout << "Answer: " << result << endl;
    return result;
}

float Calculator::NCheck(float N){
    if (N < 0 || N > 255){
        cout << "Invalid input!" << endl;
        exit(1);
    }
    return 0;
}
float Calculator::MCheck(float M){
    if (M < 0 || M > 255){
        cout << "Invalid input!" << endl;
        exit(1);
    }
    return 0;
}

void Calculator::setValue(string operation){
    string oper;
    string temp;
    int len = operation.length();
    char c[len];

    for (int i = 0; i < len; i++){
        c[i] = operation[i];
        if (!(c[i] >= 48 && c[i] <= 57) && c[i] != '+' && c[i] != '-' && c[i] != '*' && c[i] != '/' && c[i] != '%' && c[i] != '^' && c[i] != ' ' && c[i] != '=' && c[i] != 'x' && c[i] != 'y' && c[i] != 'z' && c[i] != '.'){
            cout << "Invalid input!" << endl;
            exit(1);
        }
    }

    temp = operation;
    int len2 = temp.length();
    for (int i = 0; i < len; i++){
        switch (temp[i]){
        case '+':
            temp.erase(0, i);
            break;
        case '-':
            temp.erase(0, i);
            break;
        case '*':
            temp.erase(0, i);
            break;
        case '/':
            temp.erase(0, i);
            break;
        case '%':
            temp.erase(0, i);
            break;
        case '^':
            temp.erase(0, i);
            break;
        case '=':
            temp.erase(0, i);
            break;
        case 'x':
            if (operation[0] == 'x' && operation[1] != ' '){
                cout << x << endl;
            }
            if (operation[0] == 'x' && operation[1] == ' '){
                if (operation[2] == '='){
                    temp.erase(0, 3);
                    N = stoi(temp);
                    x = N;
                }
            }
            break;
        case 'y':
            if (operation[0] == 'y' && operation[1] != ' '){
                cout << y << endl;
            }
            if (operation[0] == 'y' && operation[1] == ' '){
                if (operation[2] == '='){
                    temp.erase(0, 3);
                    N = stoi(temp);
                    y = N;
                }
            }
            break;
        case 'z':
            if (operation[0] == 'z' && operation[1] != ' '){
                cout << z << endl;
            }
            if (operation[0] == 'z' && operation[1] == ' '){
                if (operation[2] == '='){
                    temp.erase(0, 3);
                    N = stoi(temp);
                    z = N;
                }
            }
            break;
        }
    }
    
    if (!(operation[0] == 'x' || operation[0] == 'y' || operation[0] == 'z')){
        N = stoi(operation);
    }
    NCheck(N);
    len2 = temp.length();
    for (int j = len2; j < len; j++){
        switch (temp[0]){
        case '+':
            temp.erase(0, 2);
            if (c[j] >= 48 && c[j] <= 57){
                M = stoi(temp);
                MCheck(M);
                add();
            }
            else if (temp[0] == 'x') {
                addLetter();
            }
            break;
        case '-':
            temp.erase(0, 2);
            if (c[j] >= 48 && c[j] <= 57){
                M = stoi(temp);
                MCheck(M);
                sub();
            }
            else if (temp[0] == 'x') {
                subLetter();
            }
            break;
        case '*':
            temp.erase(0, 2);
            if (c[j] >= 48 && c[j] <= 57){
                M = stoi(temp);
                MCheck(M);
                mul();
            }
            else if (temp[0] == 'x') {
                mulLetter();
            }
            break;
        case '/':
            temp.erase(0, 2);
            if (c[j] >= 48 && c[j] <= 57){
                M = stoi(temp);
                MCheck(M);
                if (M == 0){
                    cout << "Answer: Operation disallowed" << endl;
                    exit(1);
                }
                div();
            }
            else if (temp[0] == 'x'){
                if (x == 0){
                    cout << "Answer: Operation disallowed" << endl;
                    exit(1);
                }
                else {
                    divLetter();
                }
            }
            break;
        case '%':
            temp.erase(0, 2);
            if (c[j] >= 48 && c[j] <= 57){
                M = stoi(temp);
                MCheck(M);
                mod();
            }
            else if (temp[0] == 'x') {
                modLetter();
            }
            break;
        case '^':
            temp.erase(0, 1);
            M = stoi(temp);
            MCheck(M);
            if (M > 10){
                exit(1);
            }
            exp();
            break;
        }
    }
}

void Calculator::toDouble(string operation){
    int len = operation.length();
    for (int i = 0; i < len; i++){
        if (operation[i] == '.'){
            cout.setf(ios::fixed, ios::floatfield);
            cout.precision(1);
        }
    }
}