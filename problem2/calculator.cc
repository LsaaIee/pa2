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
    float result = 0;
    if (y == 0 && z == 0){
        result = forX + forX;
    }
    else if (x == 0 && z == 0){
        result = forY + forY;
    }
    else if (x == 0 && y == 0){
        result = forZ + forZ;
    }
    cout << "Answer: " << result << endl;
    return result;
}

float Calculator::sub(){
    float result = N - M;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::subLetter(){
    float result = 0;
    if (y == 0 && z == 0){
        result = x - x;
    }
    else if (x == 0 && z == 0){
        result = y - y;
    }
    else if (x == 0 && y == 0){
        result = z - z;
    }
    cout << "Answer: " << result << endl;
    return result;
}

float Calculator::mul(){
    float result = N * M;
    cout << "Answer: " << result << endl;
    return result;
}
float Calculator::mulLetter(){
    float result = 0;
    if (y == 0 && z == 0){
        result = x * x;
    }
    else if (x == 0 && z == 0){
        result = y * y;
    }
    else if (x == 0 && y == 0){
        result = z * z;
    }
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
    while (x != 0){
        result *= x;
        --x;
    }
    cout << "Answer: " << result << endl;
    return result;
}

float Calculator::numCheck(float N){
    if (N < 0 || N > 255){
        cout << "Invalid input!" << endl;
        exit(1);
    }
    return false;
}

void Calculator::setValue(string operation){
    string oper;
    string temp;
    int len = operation.length();
    string c;
    c = operation;
    for (int i = 0; i < len; i++){
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
                    forX = stoi(temp);
                    x = forX;
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
                    forY = stoi(temp);
                    y = forY;
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
                    forZ = stoi(temp);
                    z = forZ;
                }
            }
            break;
        }
    }
    
    if (!(operation[0] == 'x' || operation[0] == 'y' || operation[0] == 'z')){
        N = stoi(operation);
    }
    numCheck(N);

    len2 = temp.length();
    for (int j = len2; j < len; j++){
        switch (temp[0]){
        case '+':
            temp.erase(0, 2);
            if (temp[0] >= 48 && temp[0] <= 57){
                M = stoi(temp);
                numCheck(M);
                add();
            }
            else {
                if (temp[0] == 'x'){
                    y = 0;
                    z = 0;
                    addLetter();
                }
                else if (temp[0] == 'y'){
                    x = 0;
                    z = 0;
                    addLetter();
                }
                else if (temp[0] == 'z'){
                    x = 0;
                    y = 0;
                    addLetter();
                }
            }
            break;
        case '-':
            temp.erase(0, 2);
            if (temp[0] >= 48 && temp[0] <= 57){
                M = stoi(temp);
                numCheck(M);
                sub();
            }
            else {
                if (temp[0] == 'x'){
                    y = 0;
                    z = 0;
                    subLetter();
                }
                else if (temp[0] == 'y'){
                    x = 0;
                    z = 0;
                    subLetter();
                }
                else if (temp[0] == 'z'){
                    x = 0;
                    y = 0;
                    subLetter();
                }
            }
            break;
        case '*':
            temp.erase(0, 2);
            if (temp[0] >= 48 && temp[0] <= 57){
                M = stoi(temp);
                numCheck(M);
                mul();
            }
            else {
                if (temp[0] == 'x'){
                    y = 0;
                    z = 0;
                    mulLetter();
                }
                else if (temp[0] == 'y'){
                    x = 0;
                    z = 0;
                    mulLetter();
                }
                else if (temp[0] == 'z'){
                    x = 0;
                    y = 0;
                    mulLetter();
                }
            }
            break;
        case '/':
            temp.erase(0, 2);
            if (temp[0] >= 48 && temp[0] <= 57){
                M = stoi(temp);
                numCheck(M);
                if (M == 0){
                    cout << "Answer: Operation disallowed" << endl;
                    exit(1);
                }
                div();
            }
            else {
                if (x == 0 || y == 0 || z == 0){
                    cout << "Answer: Operation disallowed" << endl;
                    exit(1);
                }
                else {
                    if (temp[0] == 'x'){
                        y = 0;
                        z = 0;
                        divLetter();
                    }
                    else if (temp[0] == 'y'){
                        x = 0;
                        z = 0;
                        divLetter();
                    }
                    else if (temp[0] == 'z'){
                        x = 0;
                        y = 0;
                        divLetter();
                    }
                }
            }
            break;
        case '%':
            temp.erase(0, 2);
            if (temp[0] >= 48 && temp[0] <= 57){
                M = stoi(temp);
                numCheck(M);
                mod();
            }
            else {
                if (temp[0] == 'x'){
                    y = 0;
                    z = 0;
                    modLetter();
                }
                else if (temp[0] == 'y'){
                    x = 0;
                    z = 0;
                    modLetter();
                }
                else if (temp[0] == 'z'){
                    x = 0;
                    y = 0;
                    modLetter();
                }
            }
            break;
        case '^':
            temp.erase(0, 2);
            if (temp[0] >= 48 && temp[0] <= 57){
                M = stoi(temp);
                numCheck(M);
                exp();
            }
            else {
                if (temp[0] == 'x'){
                    y = 0;
                    z = 0;
                    expLetter();
                }
                else if (temp[0] == 'y'){
                    x = 0;
                    z = 0;
                    expLetter();
                }
                else if (temp[0] == 'z'){
                    x = 0;
                    y = 0;
                    expLetter();
                }
            }
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