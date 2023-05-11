#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Core/monomial/monomial.h"
#include "Core/clist/CList.h"

class Polynomial {
    CList<Monomial> list;
public:
    Polynomial();
    Polynomial(const Polynomial& other);
    Polynomial(CList<Monomial>& list);
    ~Polynomial() {}

    std::string toString();

    bool operator==(const Polynomial& other) const;
    bool operator!=(const Polynomial& other) const;
    bool operator>(const Polynomial& other) const;
    bool operator<(const Polynomial& other) const;
    double findResult(int x, int y, int z) ;
    void Parse(std::string str);

    Polynomial operator+( Monomial& monomial) ;
    Polynomial operator-( Monomial& monomial) ;
    Polynomial operator*( Monomial& monomial) ;
    Polynomial operator/( Monomial& monomial) ;

    Polynomial& operator=(const Polynomial& other);

    Polynomial operator+( Polynomial& other) ;
    Polynomial operator-( Polynomial& other) ;
    Polynomial operator*( Polynomial& other) ;
    Polynomial operator*(double coefficient) ;
    Polynomial operator/( Polynomial& other) ;
    Polynomial operator/(double _number);

    friend std::ostream& operator<<(std::ostream& os, Polynomial& _polynomial);
    friend std::istream& operator>>(std::istream& is, Polynomial& polynomial);
};

#endif