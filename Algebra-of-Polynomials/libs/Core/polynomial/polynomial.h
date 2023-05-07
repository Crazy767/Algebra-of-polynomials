#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Core/monomial/monomial.h"
#include "Core/clist/CList.h"

class Polynomial {
    CList<Monomial> list;
public:
    Polynomial();
    Polynomial(Polynomial& other);
    Polynomial(CList<Monomial>* list);
    ~Polynomial() {}

    std::string toString();

    bool operator==( Polynomial& other) ;
    bool operator!=( Polynomial& other) ;
    double findResult(double x, double y, double z) ;
    void Parse(std::string str);

    Polynomial operator+( Monomial& monomial) ;
    Polynomial operator-( Monomial& monomial) ;
    Polynomial operator*( Monomial& monomial) ;
    Polynomial operator/( Monomial& monomial) ;

    Polynomial& operator=(Polynomial& other);

    Polynomial operator+( Polynomial& other) ;
    Polynomial operator-( Polynomial& other) ;
    Polynomial operator*( Polynomial& other) ;
    Polynomial operator*(double coefficient) ;
    Polynomial operator/( Polynomial& other) ;
    Polynomial operator/(double _number);

    friend std::ostream& operator<<(std::ostream& os, Polynomial& _polynomial);
    friend std::istream& operator>>(std::istream& is, Polynomial& polynomial);

    //Polynomial getDerivative() ;
};

#endif