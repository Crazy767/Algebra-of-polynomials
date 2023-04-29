#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "../monoms/monomial.h"
#include "../clist/CList.h"



class Polynomial {
    CList<Monomial> list;
public:
    Polynomial() {}
    Polynomial( Polynomial& other);
    Polynomial(CList<Monomial> list);
    ~Polynomial() {}

    std::string to_string();

    bool operator==( Polynomial& other) ;
    bool operator!=( Polynomial& other) ;
    double find_result(double x, double y, double z) ;
    void parse(std::string str);

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

    Polynomial get_derivative() ;
};

#endif