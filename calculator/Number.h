//
// Created by Sophia on 30.05.2020.
//

#ifndef CALCULATOR_NUMBER_H
#define CALCULATOR_NUMBER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Number
{
public:
    Number();
    Number(string str);
    string exception = "";
    static const int BASE = 1000000000;
    vector<int> digits;
    bool IsNegative;
    void RemoveLeadingZeros();
    operator std::string() const;
    const Number operator +() const;
    const Number operator -() const;
    Number& operator +=(const Number& value);
    Number& operator -=(const Number& value);
    const Number operator++();
    void _shift_right();
    bool odd() const;
    bool even() const;
    const Number pow(Number n) const;
    Number& operator *=(const Number& value);
    Number& operator /=(const Number& value);
    const Number operator ++(int);
    const Number operator --();
    const Number operator --(int);
    void Do();
};
const Number operator *(const Number& left, const int& right);
const Number operator -(Number left, const Number& right);
const Number operator +(Number left, const Number& right);
const Number operator *(const Number& left, const Number& right);
const Number operator *(const Number& left, const int& right);

#endif //CALCULATOR_NUMBER_H
