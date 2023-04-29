#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "../polynomial/polynomial.h"

using namespace std;
// Конструктор по умолчанию
Polynomial::Polynomial() {
    Monomial zeroMonomial;
    this->list.push_back(zeroMonomial);
}

// Конструктор копирования
Polynomial::Polynomial(Polynomial& _polynomial) {
    this->list = _polynomial.list;
}

// Конструктор из списка мономов
Polynomial::Polynomial(CList<Monomial> _list) {
    this->list = _list;
}

// Оператор присваивания
Polynomial& Polynomial::operator=(Polynomial& _polynomial) {
    this->list = _polynomial.list;
    return *this;
}

// Метод преобразования полинома в строку
std::string Polynomial::to_string() {
    std::stringstream ss;
    for (int i = 0; i < this->list.get_size(); i++) {
        ss << this->list[i].to_string();
        if (i < this->list.get_size() - 1) {
            ss << " + ";
        }
    }
    return ss.str();
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
double Polynomial::find_result(double _x, double _y, double _z) {
    double result = 0;
    for (int i = 0; i < this->list.get_size(); i++) {
        result += this->list[i].get_coeff() *
            pow(_x, this->list[i].get_degree(0)) *
            pow(_y, this->list[i].get_degree(1)) *
            pow(_z, this->list[i].get_degree(2));
    }
    return result;
}

// Метод для парсинга строки в полином
void Polynomial::parse(std::string _string) {
    std::stringstream ss(_string);
    std::string term;
    while (std::getline(ss, term, '+')) {
        Monomial monomial(term);
        this->list.push_back(monomial);
    }
}

// Оператор сложения полинома с мономом
Polynomial Polynomial::operator+(Monomial _monomial) {
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
Polynomial Polynomial::operator-(Monomial _monomial) {
    Polynomial result;
    result.list = this->list;
    bool found = false;
    for (int i = 0; i < result.list.size(); i++) {
        if (result.list[i].getVariableString() == _monomial.getVariableString()) {
            result.list[i] = result.list[i] - _monomial;
            found = true;
        }
    }
    if (!found) {
        _monomial.setCoefficient(-_monomial.getCoefficient());
        result.list.push_back(_monomial);
    }
    return result;
}

// Оператор сложения полиномов
Polynomial Polynomial::operator+(Polynomial _polynomial) {
    Polynomial result;
    result.list = this->list;
    for (int i = 0; i < _polynomial.list.size(); i++) {
        result = result + _polynomial.list[i];
    }
    return result;
}

// Оператор вычитания полиномов
Polynomial Polynomial::operator-(Polynomial _polynomial) {
    Polynomial result;
    result.list = this->list;
    for (int i = 0; i < _polynomial.list.size(); i++) {
        result = result - _polynomial.list[i];
    }
    return result;
}

// Оператор умножения полинома на моном
Polynomial Polynomial::operator*(Monomial _monomial) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] * _monomial;
        result = result + newMonomial;
    }
    return result;
}

// Оператор умножения полиномов
Polynomial Polynomial::operator*(Polynomial _polynomial) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        for (int j = 0; j < _polynomial.list.size(); j++) {
            Monomial newMonomial = this->list[i] * _polynomial.list[j];
            result = result + newMonomial;
        }
    }
    return result;
}

// Оператор деления полинома на моном
Polynomial Polynomial::operator/(Monomial _monomial) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] / _monomial;
        result = result + newMonomial;
    }
    return result;
}

// Оператор деления полинома на полином
Polynomial Polynomial::operator/(Polynomial _polynomial) {
    Polynomial quotient;
    Polynomial remainder = *this;
    while (remainder.list.size() > 0 &&
        remainder.list[0].getDegree('x') >= _polynomial.list[0].getDegree('x') &&
        remainder.list[0].getDegree('y') >= _polynomial.list[0].getDegree('y') &&
        remainder.list[0].getDegree('z') >= _polynomial.list[0].getDegree('z')) {
        Monomial divMonomial = remainder.list[0] / _polynomial.list[0];
        quotient = quotient + divMonomial;
        Polynomial tempPoly = _polynomial * divMonomial;
        remainder = remainder - tempPoly;
    }

return result;
}

// Оператор умножения полинома на число
Polynomial Polynomial::operator*(double _number) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        CMonomial newMonomial = this->list[i] * _number;
        result = result + newMonomial;
    }
    return result;
}

// Оператор деления полинома на моном
Polynomial Polynomial::operator/(CMonomial _monomial) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] / _monomial;
        result = result + newMonomial;
    }
    return result;
}

// Оператор деления полинома на число
Polynomial Polynomial::operator/(double _number) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] / _number;
        result = result + newMonomial;
    }
    return result;
}

// Оператор взятия производной по переменной
Polynomial Polynomial::operator/(char _variable) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] / _variable;
        if (newMonomial.getCoefficient() != 0) {
            result = result + newMonomial;
        }
    }
    return result;
}

// Оператор взятия интеграла по переменной
Polynomial Polynomial::operator*(char _variable) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] * _variable;
        result = result + newMonomial;
    }
    return result;
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& os, Polynomial& _polynomial) {
    os << _polynomial.toString();
    return os;
} Polynomial Polynomial::operator*(Polynomial _polynomial) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        for (int j = 0; j < _polynomial.list.size(); j++) {
            Monomial newMonomial = this->list[i] * _polynomial.list[j];
            result = result + newMonomial;
        }
    }
    return result;
}

// Оператор умножения полинома на число
Polynomial Polynomial::operator*(double _number) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] * _number;
        result = result + newMonomial;
    }
    return result;
}

// Оператор деления полинома на число
Polynomial Polynomial::operator/(double _number) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] / _number;
        result = result + newMonomial;
    }
    return result;
}

// Оператор возведения полинома в степень
Polynomial Polynomial::operator^(int _power) {
    if (_power == 0) {
        Monomial zeroMonomial;
        Polynomial result;
        result.list.push_back(zeroMonomial);
        return result;
    }
    else if (_power == 1) {
        return *this;
    }
    else {
        Polynomial result = *this;
        for (int i = 1; i < _power; i++) {
            result = result * (*this);
        }
        return result;
    }
}

// Оператор инкремента
Polynomial& Polynomial::operator++() {
    Monomial oneMonomial;
    oneMonomial.setCoefficient(1);
    *this = *this + oneMonomial;
    return *this;
}

// Оператор декремента
Polynomial& Polynomial::operator--() {
    Monomial oneMonomial;
    oneMonomial.setCoefficient(-1);
    *this = *this + oneMonomial;
    return *this;
}

// Оператор сложения с присваиванием
Polynomial& Polynomial::operator+=(Polynomial& _polynomial) {
    *this = *this + _polynomial;
    return *this;
}

// Оператор вычитания с присваиванием
Polynomial& Polynomial::operator-=(Polynomial& _polynomial) {
    *this = *this - _polynomial;
    return *this;
}

// Оператор умножения с присваиванием
Polynomial& Polynomial::operator*=(Polynomial& _polynomial) {
    *this = *this * _polynomial;
    return *this;
}

// Оператор умножения на число с присваиванием
Polynomial& Polynomial::operator*=(double _number) {
    *this = *this * _number;
    return *this;
}

// Оператор деления на число с присваиванием
Polynomial& Polynomial::operator/=(double _number) {
    *this = *this / _number;
    return *this;
}
// Оператор умножения полиномов
Polynomial Polynomial::operator*(Polynomial _polynomial) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        for (int j = 0; j < _polynomial.list.size(); j++) {
            Monomial newMonomial = this->list[i] * _polynomial.list[j];
            result = result + newMonomial;
        }
    }
    return result;
}

// Оператор деления полинома на моном
Polynomial Polynomial::operator/(CMonomial _monomial) {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i] / _monomial;
        result = result + newMonomial;
    }
    return result;
}

// Оператор деления полинома на полином
Polynomial Polynomial::operator/(Polynomial _polynomial) {
    Polynomial result;
    Polynomial remainder = *this;
    while (remainder.list.size() > 0 && remainder.list[0].getDegree() >= _polynomial.list[0].getDegree()) {
        Monomial divisor = remainder.list[0] / _polynomial.list[0];
        Polynomial term;
        term.list.push_back(divisor);
        result = result + term;
        remainder = remainder - (_polynomial * term);
    }
    return result;
}

// Оператор взятия производной
Polynomial Polynomial::operator-() {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = -this->list[i];
        result.list.push_back(newMonomial);
    }
    return result;
}

// Оператор взятия интеграла
Polynomial Polynomial::operator+() {
    Polynomial result;
    for (int i = 0; i < this->list.size(); i++) {
        Monomial newMonomial = this->list[i].integrate();
        result.list.push_back(newMonomial);
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