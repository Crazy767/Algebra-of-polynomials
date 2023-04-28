#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include <string>
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;

class Polynomial {
public:
    Polynomial();

    Polynomial(std::vector<std::vector<std::vector<double>>> coeffs);

    Polynomial operator+(const Polynomial& other) const;

    Polynomial operator-(const Polynomial& other) const;

    Polynomial operator*(double scalar) const;

    std::string toString() const;

    double operator()(double x, double y, double z) const;

    void saveToFile(const std::string& filename) const;
private:
 
 
    std::vector<std::vector<std::vector<double>>> m_coeffs;
};

#endif



