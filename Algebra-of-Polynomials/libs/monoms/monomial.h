#pragma once
#include <iostream>
#ifndef MONOMIAL_H
#define MONOMIAL_H

class Monomial {
private:
    float coefficient; 
    int degree; 
public:
    Monomial();
    Monomial(float coeff, int deg);
    Monomial operator+(Monomial other);
    Monomial operator-(Monomial other);
    Monomial operator*(Monomial other);
    Monomial operator*(float scalar);
    Monomial operator/(Monomial other);
    Monomial operator-();
    Monomial derivative();
    void assign(float coeff, int deg);
    void print();
};
#endif

