#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
#include <algorithm>

using namespace std;

//Implement Member Functions
float Calculator::add(){
    int result = N + M;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::sub(){
    int result = N - M;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::mul(){
    int result = N * M;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::div(){
    int result = N / M;
    if (M == 0){
        cout << "Answer: Operation disallowed" << endl;
        exit(1);
    }
    else {
        cout << "Answer: " << result << endl;
    }
    return result;
}
/*
float Calculator::mod(){
    cout << "Answer: " << N%M << endl;
    return N % M;
}
*/
float Calculator::exp(){
    int result = N*(N*M);
    cout << "Answer: " << result << endl;
    return result;
}

void Calculator::setValue(string operation){
    string oper;
    string temp;
    //operation.erase(remove(operation.begin(), operation.end(), ' '), operation.end());
    int len = operation.length();
    char c[len];

    for (int i = 0; i < len; i++){
        c[i] = operation[i];
        if (!(c[i] >= 48 && c[i] <= 57) && c[i] != '+' && c[i] != '-' && c[i] != '*' && c[i] != '/' && c[i] != '%' && c[i] != '^' && c[i] != ' '){
            cout << "Invalid input!" << endl;
            exit(1);
        }
    }
    temp = operation;
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
        }
    }
    int len2 = temp.length();
    N = stoi(operation);
    operation.erase(0, len2);
    for (int j = len2; j < len; j++){
        switch (temp[0]){
        case '+':
            oper = '+';
            temp.erase(0, 1);
            M = stoi(temp);
            add();
            break;
        case '-':
            oper = '-';
            temp.erase(0, 1);
            M = stoi(temp);
            sub();
            break;
        case '*':
            oper = '*';
            temp.erase(0, 1);
            M = stoi(temp);
            mul();
            break;
        case '/':
            oper = '/';
            temp.erase(0, 1);
            M = stoi(temp);
            div();
            break;
        case '%':
            oper = '%';
            temp.erase(0, 1);
            M = stoi(temp);
            //mod();
            break;
        case '^':
            oper = '^';
            temp.erase(0, 1);
            M = stoi(temp);
            exp();
            break;
        case 'q':
            exit(1);
        }
    }
}
void Calculator::print(){
    cout << N << oper << M << endl;
}
