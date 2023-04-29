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

    Monomial& operator=(Monomial& monomial);
    Monomial operator+(Monomial& other);
    Monomial operator-(Monomial& other);
    Monomial operator*(Monomial& other);
    Monomial operator*(float scalar);
    Monomial operator/(Monomial& other);
    Monomial derivative(int variable);
    std::string to_string();

    float get_coeff() { return coefficient; }
    int get_degree(int index) { return degree[index]; }
};
#endif

