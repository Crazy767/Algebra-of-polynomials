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
    Monomial(std::string term);
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
    Monomial operator/(float scalar);
    Monomial derivative(int variable);
    std::string toString();
    std::string getVariableString();

    float getCoeff() { return coefficient; }
    void setCoeff(float c) { coefficient = c; }
    int getDegree(int index) { return degree[index]; }

    void parseTerm(std::string term);
};
#endif

