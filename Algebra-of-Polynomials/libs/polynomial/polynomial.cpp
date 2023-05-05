﻿#include "../polynomial/polynomial.h"

using namespace std;
// Конструктор по умолчанию
Polynomial::Polynomial() {
    Monomial zeroMonomial;
    this->list.push_back(zeroMonomial);
}

// Конструктор копирования
Polynomial::Polynomial(Polynomial& _polynomial) {
    this->list.copy(_polynomial.list);
}

// Конструктор из списка мономов
Polynomial::Polynomial(CList<Monomial>* _list) {
    this->list.copy(*_list);
}

// Оператор присваивания
Polynomial& Polynomial::operator=(Polynomial& _polynomial) {
    this->list = _polynomial.list;
    return *this;
}

// Метод преобразования полинома в строку
std::string Polynomial::toString() {
    std::string polynom_str;
    for (int i = 0; i < this->list.get_size(); i++) {
        std::string monom_str = Monomial(list[i]).toString();
        if (i < this->list.get_size() - 1) {
            polynom_str += monom_str + " + ";
        }
        else
            polynom_str += monom_str;
    }
    return polynom_str;
}

// Оператор сравнения на равенство
bool Polynomial::operator==(Polynomial& _polynomial) {
    return this->list == _polynomial.list;
}

// Оператор сравнения на неравенство
bool Polynomial::operator!=(Polynomial& _polynomial) {
    return !(*this == _polynomial);
}

// Метод для вычисления значения полинома в точке (x, y, z)
double Polynomial::findResult(double _x, double _y, double _z) {
    double result = 0;
    for (int i = 0; i < this->list.get_size(); i++) {
        result += this->list[i].getCoeff() *
            pow(_x, this->list[i].getDegree(0)) *
            pow(_y, this->list[i].getDegree(1)) *
            pow(_z, this->list[i].getDegree(2));
    }
    return result;
}

// Метод для парсинга строки в полином
void Polynomial::Parse(std::string _string) {
    std::stringstream ss(_string);
    std::string term;
    while (std::getline(ss, term, '+')) {
        Monomial monomial(term);
        this->list.push_back(monomial);
    }
}

// Оператор сложения полинома с мономом
Polynomial Polynomial::operator+(Monomial& _monomial) {
    Polynomial result;
    result.list = this->list;
    bool found = false;
    for (int i = 0; i < result.list.get_size(); i++) {
        if (result.list[i].getVariableString() == _monomial.getVariableString()) {
            result.list[i] = result.list[i] + _monomial;
            found = true;
        }
    }
    if (!found) {
        result.list.push_back(_monomial);
    }
    return result;
}

// Оператор вычитания монома из полинома
Polynomial Polynomial::operator-(Monomial& _monomial) {
    Polynomial result;
    result.list = this->list;
    bool found = false;
    for (int i = 0; i < result.list.get_size(); i++) {
        if (result.list[i].getVariableString() == _monomial.getVariableString()) {
            result.list[i] = result.list[i] - _monomial;
            found = true;
        }
    }
    if (!found) {
        _monomial.setCoeff(-_monomial.getCoeff());
        result.list.push_back(_monomial);
    }
    return result;
}

// Оператор сложения полиномов
Polynomial Polynomial::operator+(Polynomial& _polynomial) {
    Polynomial result;
    result.list = this->list;
    for (int i = 0; i < _polynomial.list.get_size(); i++) {
        result = result + _polynomial.list[i];
    }
    return result;
}

// Оператор вычитания полиномов
Polynomial Polynomial::operator-(Polynomial& _polynomial) {
    Polynomial result;
    result.list = this->list;
    for (int i = 0; i < _polynomial.list.get_size(); i++) {
        result = result - _polynomial.list[i];
    }
    return result;
}

// Оператор умножения полинома на моном
Polynomial Polynomial::operator*(Monomial& _monomial) {
    Polynomial result;
    for (int i = 0; i < this->list.get_size(); i++) {
        Monomial newMonomial = this->list[i] * _monomial;
        result = result + newMonomial;
    }
    return result;
}

// Оператор деления полинома на полином
Polynomial Polynomial::operator/(Polynomial& _polynomial) {
    Polynomial quotient;
    Polynomial remainder = *this;
    while (remainder.list.get_size() > 0 &&
        remainder.list[0].getDegree('x') >= _polynomial.list[0].getDegree('x') &&
        remainder.list[0].getDegree('y') >= _polynomial.list[0].getDegree('y') &&
        remainder.list[0].getDegree('z') >= _polynomial.list[0].getDegree('z')) {
        Monomial divMonomial = remainder.list[0] / _polynomial.list[0];
        quotient = quotient + divMonomial;
        Polynomial tempPoly = _polynomial * divMonomial;
        remainder = remainder - tempPoly;
    }

    return quotient;
}

// Оператор умножения полинома на число
Polynomial Polynomial::operator*(double _number) {
    Polynomial result;
    for (int i = 0; i < this->list.get_size(); i++) {
        Monomial newMonomial = this->list[i] * _number;
        result = result + newMonomial;
    }
    return result;
}

// Оператор деления полинома на моном
Polynomial Polynomial::operator/(Monomial& _monomial) {
    Polynomial result;
    for (int i = 0; i < this->list.get_size(); i++) {
        Monomial newMonomial = this->list[i] / _monomial;
        result = result + newMonomial;
    }
    return result;
}

// Оператор деления полинома на число
Polynomial Polynomial::operator/(double _number) {
    Polynomial result;
    for (int i = 0; i < this->list.get_size(); i++) {
        Monomial newMonomial = this->list[i] / _number;
        result = result + newMonomial;
    }
    return result;
}

Polynomial Polynomial::operator*(Polynomial& _polynomial) {
    Polynomial result;
    for (int i = 0; i < this->list.get_size(); i++) {
        for (int j = 0; j < _polynomial.list.get_size(); j++) {
            Monomial newMonomial = this->list[i] * _polynomial.list[j];
            result = result + newMonomial;
        }
    }
    return result;
}

// Оператор вывода полинома в поток
std::ostream& operator<<(std::ostream& os, Polynomial& polynomial) {
    os << polynomial.toString();
    return os;
}

// Оператор ввода полинома из потока
std::istream& operator>>(std::istream& is, Polynomial& polynomial) {
    std::string input;
    std::getline(is, input);
    polynomial.Parse(input);
    return is;
}