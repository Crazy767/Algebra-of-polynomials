#include "monomial.h"
#include <iostream>
#include <sstream>

Monomial::Monomial() {
    coefficient = 0.0;
    degree[0] = degree[1] = degree[2] = 0;
}

Monomial::Monomial(std::string term)
{
    parseTerm(term);
}

Monomial::Monomial(float _coefficient, int* _degree) {
    coefficient = _coefficient;
    degree[0] = _degree[0];
    degree[1] = _degree[1];
    degree[2] = _degree[2];
}

Monomial::Monomial(const Monomial& monomial) {
    coefficient = monomial.coefficient;
    degree[0] = monomial.degree[0];
    degree[1] = monomial.degree[1];
    degree[2] = monomial.degree[2];
}

Monomial::~Monomial() {}

std::string Monomial::toString() {
    std::stringstream ss;
    if (coefficient != 1.0) {
        ss << coefficient;
    }
    if (degree[0] != 0) {
        ss << "x^" << degree[0];
    }
    if (degree[1] != 0) {
        ss << "y^" << degree[1];
    }
    if (degree[2] != 0) {
        ss << "z^" << degree[2];
    }
    auto s = ss.str();
    return ss.str();
}

std::string Monomial::getVariableString() {
    std::string result;
    if (degree[0] > 0) result += "x^" + std::to_string(degree[0]);
    if (degree[1] > 0) result += "y^" + std::to_string(degree[1]);
    if (degree[2] > 0) result += "z^" + std::to_string(degree[2]);
    return result;
}

bool Monomial::operator==(Monomial& monomial) {
    return (coefficient == monomial.coefficient) && (degree[0] == monomial.degree[0]) &&
        (degree[1] == monomial.degree[1]) && (degree[2] == monomial.degree[2]);
}

bool Monomial::operator!=(Monomial& monomial) {
    return !(*this == monomial);
}

Monomial& Monomial::operator=(Monomial& monomial) {
    coefficient = monomial.coefficient;
    degree[0] = monomial.degree[0];
    degree[1] = monomial.degree[1];
    degree[2] = monomial.degree[2];
    return *this;
}

Monomial Monomial::operator+(Monomial& monomial) {
    if ((degree[0] != monomial.degree[0]) || (degree[1] != monomial.degree[1]) ||
        (degree[2] != monomial.degree[2])) {
        std::cerr << "Error: Cannot add monomials with different degrees." << std::endl;
        return *this;
    }
    return Monomial(coefficient + monomial.coefficient, degree);
}

Monomial Monomial::operator-(Monomial& monomial) {
    if ((degree[0] != monomial.degree[0]) || (degree[1] != monomial.degree[1]) ||
        (degree[2] != monomial.degree[2])) {
        std::cerr << "Error: Cannot subtract monomials with different degrees." << std::endl;
        return *this;
    }
    return Monomial(coefficient - monomial.coefficient, degree);
}

Monomial Monomial::operator*(Monomial& monomial) {
    return Monomial(coefficient * monomial.coefficient,
        new int[3] {degree[0] + monomial.degree[0], degree[1] + monomial.degree[1], degree[2] + monomial.degree[2]});
}

Monomial Monomial::operator*(float scalar) {
    return Monomial(coefficient * scalar, degree);
}


Monomial Monomial::operator/(Monomial& monomial) {
    return Monomial(coefficient / monomial.coefficient,
        new int[3] {degree[0] - monomial.degree[0], degree[1] - monomial.degree[1], degree[2] - monomial.degree[2]});
}

Monomial Monomial::operator/(float scalar)
{
    return Monomial(coefficient / scalar, degree);
}

Monomial Monomial::derivative(int variable) {
    if (variable < 0 || variable > 2) {
        std::cerr << "Error: Invalid variable index." << std::endl;
        return Monomial();
    }

    if (degree[variable] == 0) {
        return Monomial();
    }

    return Monomial(coefficient * degree[variable],
        new int[3] {degree[0] - (variable == 0 ? 1 : 0), degree[1] - (variable == 1 ? 1 : 0), degree[2] - (variable == 2 ? 1 : 0)});
}

void Monomial::parseTerm(std::string term)
{
    std::stringstream ss(term);

    ss >> coefficient;

    std::string str_degree;
    std::getline(ss, str_degree);

    // Разделение строки степеней на компоненты
    std::stringstream ss_degree(str_degree);
    std::string degree_component;
    int i = 0;
    while (std::getline(ss_degree, degree_component, ',')) {
        degree[i++] = std::stoi(degree_component);
    }
}