#pragma once
#include "base.h"
#ifndef MONOMIAL_H
#define MONOMIAL_H

class Monomial {
private:
    float coefficient;
    int x_deg;
    int y_deg;
    int z_deg;
public:
    Monomial();
    Monomial(std::string term);
    Monomial(float coefficient, int x_deg, int y_deg, int z_deg);
    Monomial(const Monomial& monomial);
    ~Monomial() {};
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
    int getXDeg() { return x_deg; }
    int getYDeg() { return y_deg; }
    int getZDeg() { return z_deg; }
    void parseTerm(std::string term);
};
#endif

