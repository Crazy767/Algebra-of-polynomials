#include "monomial.h"

Monomial::Monomial() {
    coefficient = 0.0;
    x_deg = y_deg = z_deg = 0;
}

Monomial::Monomial(std::string term)
{
    parseTerm(term);
}

Monomial::Monomial(float coefficient, int x_deg, int y_deg, int z_deg) {
    this->coefficient = coefficient;
    this->x_deg = x_deg;
    this->y_deg = y_deg;
    this->z_deg = z_deg;
}

Monomial::Monomial(const Monomial& monomial) {
    coefficient = monomial.coefficient;
    x_deg = monomial.x_deg;
    y_deg = monomial.y_deg;
    z_deg = monomial.z_deg;
}

std::string Monomial::toString() {
    std::stringstream ss;
    if (coefficient != 1.0) {
        ss << coefficient;
    }
    if (x_deg != 0) {
        ss << "x^" << x_deg;
    }
    if (y_deg != 0) {
        ss << "y^" << y_deg;
    }
    if (z_deg != 0) {
        ss << "z^" << z_deg;
    }
    auto s = ss.str();
    return ss.str();
}

std::string Monomial::getVariableString() {
    std::string result;
    if (x_deg > 0) result += "x^" + std::to_string(x_deg);
    if (y_deg > 0) result += "y^" + std::to_string(y_deg);
    if (z_deg > 0) result += "z^" + std::to_string(z_deg);
    return result;
}


bool Monomial::operator==(Monomial& monomial) {
    return (coefficient == monomial.coefficient) && (x_deg == monomial.x_deg) &&
        (y_deg == monomial.y_deg) && (z_deg == monomial.z_deg);
}

bool Monomial::operator!=(Monomial& monomial) {
    return !(*this == monomial);
}

Monomial& Monomial::operator=(Monomial& monomial) {
    coefficient = monomial.coefficient;
    x_deg = monomial.x_deg;
    y_deg = monomial.y_deg;
    z_deg = monomial.z_deg;
    return *this;
}

Monomial Monomial::operator+(Monomial& monomial) {
    if ((x_deg != monomial.x_deg) || (y_deg != monomial.y_deg) ||
        (z_deg != monomial.z_deg)) {
        std::cerr << "Error: Cannot add monomials with different degrees." << std::endl;
        return *this;
    }
    return Monomial(coefficient + monomial.coefficient, x_deg, y_deg, z_deg);
}

Monomial Monomial::operator-(Monomial& monomial) {
    if ((x_deg != monomial.x_deg) || (y_deg != monomial.y_deg) ||
        (z_deg != monomial.z_deg)) {
        std::cerr << "Error: Cannot subtract monomials with different degrees." << std::endl;
        return *this;
    }
    return Monomial(coefficient - monomial.coefficient, x_deg, y_deg, z_deg);
}
Monomial Monomial::operator*(Monomial& monomial) {
    return Monomial(coefficient * monomial.coefficient,
        x_deg + monomial.x_deg, y_deg + monomial.y_deg, z_deg + monomial.z_deg);
}
Monomial Monomial::operator*(float scalar) {
    return Monomial(coefficient * scalar, x_deg, y_deg, z_deg);
}

Monomial Monomial::operator/(Monomial& monomial) {
    if ((monomial.x_deg > x_deg) || (monomial.y_deg > y_deg) || (monomial.z_deg > z_deg)) {
        std::cerr << "Error: Cannot divide monomial by a higher degree monomial." << std::endl;
        return *this;
    }
    return Monomial(coefficient / monomial.coefficient, x_deg - monomial.x_deg,
        y_deg - monomial.y_deg, z_deg - monomial.z_deg);
}

Monomial Monomial::operator/(float scalar) {
    return Monomial(coefficient / scalar, x_deg, y_deg, z_deg);
}

Monomial Monomial::derivative(int variable) {
    if (variable < 0 || variable > 2) {
        std::cerr << "Error: Invalid variable index." << std::endl;
        return Monomial();
    }

    int new_x_deg = x_deg - (variable == 0 ? 1 : 0);
    int new_y_deg = y_deg - (variable == 1 ? 1 : 0);
    int new_z_deg = z_deg - (variable == 2 ? 1 : 0);

    if (new_x_deg < 0 || new_y_deg < 0 || new_z_deg < 0) {
        return Monomial();
    }

    return Monomial(coefficient * x_deg, new_x_deg, new_y_deg, new_z_deg);

}

void Monomial::parseTerm(std::string term) {
    std::stringstream ss(term);

        ss >> coefficient;

    std::string str_degree;
    std::getline(ss, str_degree);

    // Разделение строки степеней на компоненты
    std::stringstream ss_degree(str_degree);
    std::string degree_component;
    int i = 0; 
    while (std::getline(ss_degree, degree_component, ' ')) {
        if (degree_component.empty()) { continue; }
        if (i == 0) {
            x_deg = std::stoi(degree_component);
        }
        else if (i == 1) {
            y_deg = std::stoi(degree_component);
        }
        else if (i == 2) {
            z_deg = std::stoi(degree_component);
        }
        i++;
    }
}