#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <iomanip>

using namespace std;

//Implement Member Functions
float calculator::add(){
    result = N + M;
    print();
    return result;
}
float calculator::addLetter(float local1, float local2){
    result = 0;
    result = local1 + local2;
    print();
    return result;
}

float calculator::sub(){
    result = N - M;
    print();
    return result;
}
float calculator::subLetter(float local1, float local2){
    result = 0;
    result = local1 - local2;
    print();
    return result;
}

float calculator::mul(){
    result = N * M;
    print();
    return result;
}
float calculator::mulLetter(float local1, float local2){
    result = 0;
    result = local1 * local2;
    print();
    return result;
}

float calculator::div(){
    result = N / M;
    if (M == 0){
        cout << "Answer: Operation disallowed" << endl;
        exit(1);
    }
    else {
        print();
    }
    return result;
}
float calculator::divLetter(float local1, float local2){
    result = 1;
    if (x == 0){
        cout << "Answer: Operation disallowed" << endl;
        exit(1);
    }
    else {
        result = local1 / local2;
        print();
    }
    return result;
}

float calculator::mod(){
    int a = (int)N;
    int b = (int)M;
    result = a%b;
    print();
    return result;
}
float calculator::modLetter(float local1, float local2){
    result = 0;
    int a = (int)local1;
    int b = (int)local2;
    result = a % b;
    print();
    return result;
}

float calculator::exp(){
    result = pow(N, M);
    print();
    return result;
}
float calculator::expLetter(float local1, float local2){
    result = pow(local1, local2);
    print();
    return result;
}

void calculator::numCheck(float N){
    if (N < 0 || N > 255){
        cout << "Answer: Invalid input" << endl;
        exit(1);
    }
}

void calculator::setValue(string operation) {
    this->operation = operation;
    float local1 = 0;
    float local2 = 0;
    string temp;
    len = operation.length();
    string c;
    c = operation;
    for (int i = 0; i < len; i++){
        if (!(c[i] >= 48 && c[i] <= 57) && c[i] != '+' && c[i] != '-' && c[i] != '*' && c[i] != '/' && c[i] != '%' && c[i] != '^' && c[i] != ' ' && c[i] != '=' && c[i] != 'x' && c[i] != 'y' && c[i] != 'z' && c[i] != '.'){
            cout << "Answer: Invalid input" << endl;
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
                    forX = stof(temp);
                    x = forX;
                }
                else {
                    local1 = x;
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
                    forY = stof(temp);
                    y = forY;
                }
                else {
                    local1 = y;
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
                    forZ = stof(temp);
                    z = forZ;
                }
                else {
                    local1 = z;
                }
            }
            break;
        }
    }
    
    if (!(operation[0] == 'x' || operation[0] == 'y' || operation[0] == 'z')){
        N = stof(operation);
    }
    numCheck(N);

    len2 = temp.length();
    for (int j = len2; j < len; j++){
        switch (temp[0]){
        case '+':
            temp.erase(0, 2);
            if (operation[0] == 'x' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << forX + M << endl;
                break;
            }
            else if (operation[0] == 'y' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << forY + M << endl;
                break;
            }
            else if (operation[0] == 'z' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << forZ + M << endl;
                break;
            }
            
            if (temp[0] >= 48 && temp[0] <= 57){
                M = stof(temp);
                numCheck(M);
                add();
            }
            else {
                if (temp[0] == 'x'){
                    local2 = x;
                }
                else if (temp[0] == 'y'){
                    local2 = y;
                }
                else if (temp[0] == 'z'){
                    local2 = z;
                }
                addLetter(local1, local2);
            }
            break;
        case '-':
            temp.erase(0, 2);
            if (operation[0] == 'x' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << forX - M << endl;
                break;
            }
            else if (operation[0] == 'y' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << forY - M << endl;
                break;
            }
            else if (operation[0] == 'z' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                //numCheck(M);
                cout << "Answer: " << forZ - M << endl;
                break;
            }
            
            if (temp[0] >= 48 && temp[0] <= 57) {
                M = stof(temp);
                numCheck(M);
                sub();
            }
            else {
                if (temp[0] == 'x'){
                    local2 = x;
                }
                else if (temp[0] == 'y'){
                    local2 = y;
                }
                else if (temp[0] == 'z'){
                    local2 = z;
                }
                subLetter(local1, local2);
            }
            break;
        case '*':
            temp.erase(0, 2);
            if (operation[0] == 'x' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << forX * M << endl;
                break;
            }
            else if (operation[0] == 'y' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << forY * M << endl;
                break;
            }
            else if (operation[0] == 'z' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << forZ * M << endl;
                break;
            }

            if (temp[0] >= 48 && temp[0] <= 57){
                M = stof(temp);
                numCheck(M);
                mul();
            }
            else {
                if (temp[0] == 'x'){
                    local2 = x;
                }
                else if (temp[0] == 'y'){
                    local2 = y;
                }
                else if (temp[0] == 'z'){
                    local2 = z;
                }
                mulLetter(local1, local2);
            }
            break;
        case '/':
            temp.erase(0, 2);
            if (operation[0] == 'x' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                if (M == 0){
                    cout << "Answer: Invalid input" << endl;
                    exit(1);
                }
                else {
                    cout << "Answer: " << forX / M << endl;
                }
                break;
            }
            else if (operation[0] == 'y' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                if (M == 0){
                    cout << "Answer: Invalid input" << endl;
                    exit(1);
                }
                else {
                    cout << "Answer: " << forY / M << endl;
                }
                
                break;
            }
            else if (operation[0] == 'z' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                if (M == 0){
                    cout << "Answer: Invalid input" << endl;
                    exit(1);
                }
                else {
                    cout << "Answer: " << forZ / M << endl;
                }
                break;
            }

            if (temp[0] >= 48 && temp[0] <= 57){
                M = stof(temp);
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
                        local2 = x;
                    }
                    else if (temp[0] == 'y'){
                        local2 = y;
                    }
                    else if (temp[0] == 'z'){
                        local2 = z;
                    }
                    divLetter(local1, local2);
                }
            }
            break;
        case '%':
            temp.erase(0, 2);
            if (operation[0] == 'x' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << int(forX) % int(M) << endl;
                break;
            }
            else if (operation[0] == 'y' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << int(forY) % int(M) << endl;
                break;
            }
            else if (operation[0] == 'z' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << int(forZ) % int(M) << endl;
                break;
            }

            if (temp[0] >= 48 && temp[0] <= 57){
                M = stof(temp);
                numCheck(M);
                mod();
            }
            else {
                if (temp[0] == 'x'){
                    local2 = x;
                }
                else if (temp[0] == 'y'){
                    local2 = y;
                }
                else if (temp[0] == 'z'){
                    local2 = z;
                }
                modLetter(local1, local2);
            }
            break;
        case '^':
            temp.erase(0, 2);
            if (operation[0] == 'x' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << pow(forX, M) << endl;
                break;
            }
            else if (operation[0] == 'y' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << pow(forY, M) << endl;
                break;
            }
            else if (operation[0] == 'z' && (temp[0] >= 48 && temp[0] <= 57)){
                M = stof(temp);
                numCheck(M);
                cout << "Answer: " << pow(forZ, M) << endl;
                break;
            }

            if (temp[0] >= 48 && temp[0] <= 57){
                M = stof(temp);
                numCheck(M);
                exp();
            }
            else {
                if (temp[0] == 'x'){
                    local2 = x;
                }
                else if (temp[0] == 'y'){
                    local2 = y;
                }
                else if (temp[0] == 'z'){
                    local2 = z;
                }
                expLetter(local1, local2);
            }
            break;
        }
    }
}

void calculator::print() {
    cout << "Answer: " << result << endl;  
}
