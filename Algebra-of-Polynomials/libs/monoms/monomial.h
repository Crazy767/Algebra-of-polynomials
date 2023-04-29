#pragma once
#include <iostream>
#include <string>
#ifndef MONOMIAL_H
#define MONOMIAL_H

class Monomial {
private:
    float coefficient; 
    int degree[3];
public:
    Monomial();
    Monomial(float coeff, int* deg);
    Monomial(const Monomial& monomial);
    ~Monomial();
    bool operator==(Monomial& monomial);
    bool operator!=(Monomial& monomial);

    Monomial& operator=(const Monomial& monomial);
    Monomial operator+(Monomial& other);
    Monomial operator-(Monomial& other);
    Monomial operator*(Monomial& other);
    Monomial operator*(float scalar);
    Monomial operator/(Monomial& other);
    Monomial derivative(int variable);
    std::string to_string();
};
#endif

