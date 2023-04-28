#include <iostream>
#include <sstream>
#include <vector>
#include "lib_polynomial.h"

using namespace std;

Polynomial::Polynomial() {
    m_coeffs = std::vector<std::vector<std::vector<double>>>(3,
        std::vector<std::vector<double>>(3, std::vector<double>(3, 0)));
}

Polynomial::Polynomial(std::vector<std::vector<std::vector<double>>> coeffs) {
    m_coeffs = coeffs;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    std::vector<std::vector<std::vector<double>>> newCoeffs(3,
        std::vector<std::vector<double>>(3, std::vector<double>(3)));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                newCoeffs[i][j][k] = m_coeffs[i][j][k] + other.m_coeffs[i][j][k];
            }
        }
    }
    return Polynomial(newCoeffs);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    std::vector<std::vector<std::vector<double>>> newCoeffs(3,
        std::vector<std::vector<double>>(3, std::vector<double>(3)));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                newCoeffs[i][j][k] = m_coeffs[i][j][k] - other.m_coeffs[i][j][k];
            }
        }
    }
    return Polynomial(newCoeffs);
}

Polynomial Polynomial::operator*(double scalar) const {
    std::vector<std::vector<std::vector<double>>> newCoeffs(3,
        std::vector<std::vector<double>>(3, std::vector<double>(3)));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                newCoeffs[i][j][k] = m_coeffs[i][j][k] * scalar;
            }
        }
    }
    return Polynomial(newCoeffs);
}

std::string Polynomial::toString() const {
    std::ostringstream oss;
    bool isFirstTerm = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                double coeff = m_coeffs[i][j][k];
                if (coeff == 0) {
                    continue;
                }
                if (!isFirstTerm) {
                    if (coeff > 0) {
                        oss << " + ";
                    }
                    else {
                        oss << " ";
                    }
                    if (coeff != 1 && coeff != -1) {
                        oss << coeff;
                    }
                    if (i > 0) {
                        oss << "x^" << i;
                    }
                    if (j > 0) {
                        oss << "y^" << j;
                    }
                    if (k > 0) {
                        oss << "z^" << k;

                    }
                }
                else {
                    if (coeff == -1) {
                        oss << "-";
                    }
                    if (coeff != 1 && coeff != -1) {
                        oss << coeff;
                    }
                    if (i > 0) {
                        oss << "x^" << i;
                    }
                    if (j > 0) {
                        oss << "y^" << j;
                    }
                    if (k > 0) {
                        oss << "z^" << k;
                    }
                    isFirstTerm = false;
                }
            }
        }
    }
    if (isFirstTerm) {
        oss << "0";
    }
    return oss.str();
}

double Polynomial::operator()(double x, double y, double z) const {
    double result = 0.0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result += m_coeffs[i][j][k] * pow(x, i) * pow(y, j) * pow(z, k);
            }
        }
    }
    return result;
}
int main() {

    std::vector<std::vector<std::vector<double>>> coeffs1(3,
        std::vector<std::vector<double>>(3, std::vector<double>(3, 0)));
    coeffs1[0][1][2] = 1;
    coeffs1[1][0][1] = 2;
    coeffs1[2][0][0] = 3;
    Polynomial p1(coeffs1);

    std::vector<std::vector<std::vector<double>>> coeffs2(3,
        std::vector<std::vector<double>>(3, std::vector<double>(3, 0)));
    coeffs2[0][1][2] = 1;
    coeffs2[1][0][1] = 2;
    coeffs2[2][0][0] = 3;
    Polynomial p2(coeffs2);


    Polynomial p3 = p1 + p2;
    std::cout << p3.toString() << std::endl;

    Polynomial p4 = p1 - p2;
    std::cout << p4.toString() << std::endl;

    Polynomial p5 = p1 * 2.0;
    std::cout << p5.toString() << std::endl;

    return 0;
}