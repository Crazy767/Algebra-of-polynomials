#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Monomial {
private:
    float coefficient; 
    int degree; 
public:
   
    Monomial() {
        coefficient = 0.0;
        degree = 0;
    }
    Monomial(float coeff, int deg) {
        coefficient = coeff;
        degree = deg;
    }

    
    Monomial operator+(const Monomial& other) const {
        if (degree != other.degree) {
            throw "Degrees do not match!";
        }
        return Monomial(coefficient + other.coefficient, degree);
    }

    Monomial operator-(const Monomial& other) const {
        if (degree != other.degree) {
            throw "Degrees do not match!";
        }
        return Monomial(coefficient - other.coefficient, degree);
    }

    Monomial operator*(const Monomial& other) const {
        return Monomial(coefficient * other.coefficient, degree + other.degree);
    }

    Monomial operator*(float scalar) const {
        return Monomial(coefficient * scalar, degree);
    }

    Monomial operator/(const Monomial& other) const {
        if (degree < other.degree) {
            throw "Invalid division!";
        }
        return Monomial(coefficient / other.coefficient, degree - other.degree);
    }

    Monomial operator-() const {
        return Monomial(-coefficient, degree);
    }

 
    Monomial derivative() const {
        return Monomial(coefficient * degree, degree - 1);
    }

    void assign(float coeff, int deg) {
        coefficient = coeff;
        degree = deg;
    }

    void print() const {
        cout << coefficient << "x^" << degree;
    }
};

class Polynomial {
private:
    std::vector<Monomial> monomials;

public:
    

  
    Polynomial operator+(const Monomial& m) const {
        Polynomial result = *this;
        result.addMonomial(m);
        return result;
    }

   
    Polynomial operator+(const Polynomial& p) const {
        Polynomial result = *this;
        for (const auto& m : p.monomials) {
            result.addMonomial(m);
        }
        result.simplify();
        return result;
    }

 
    Polynomial operator-(const Monomial& m) const {
        Polynomial result = *this;
        result.addMonomial(-m);
        return result;
    }


    Polynomial operator-(const Polynomial& p) const {
        Polynomial result = *this;
        for (const auto& m : p.monomials) {
            result.addMonomial(-m);
        }
        result.simplify();
        return result;
    }

    Polynomial operator*(const Monomial& m) const {
        Polynomial result;
        for (const auto& mon : monomials) {
            result.addMonomial(mon * m);
        }
        result.simplify();
        return result;
    }

    
    Polynomial operator*(double k) const {
        Polynomial result;
        for (const auto& mon : monomials) {
            result.addMonomial(mon * k);
        }
        result.simplify();
        return result;
    }


    Polynomial operator*(const Polynomial& p) const {
        Polynomial result;
        for (const auto& m1 : monomials) {
            for (const auto& m2 : p.monomials) {
                result.addMonomial(m1 * m2);
            }
        }
        result.simplify();
        return result;
    }

    Polynomial operator/(const Monomial& m) const {
        Polynomial result;
        for (const auto& mon : monomials) {
            result.addMonomial(mon / m);
        }
        result.simplify();
        return result;
    }

   
    Polynomial operator/(const Polynomial& p) const {
        if (p.monomials.size() == 0) {
            throw std::invalid_argument("Division by zero");
        }
        if (degree() < p.degree()) {
            return Polynomial();
        }
        Monomial factor = p.monomials.back();
        Polynomial result;
        Polynomial remainder = *this;
        while (remainder.degree() >= p.degree()) {
            Monomial leadMon = remainder.monomials.back();
            double k = leadMon.coefficient() / factor.coefficient();
            Monomial term = k * (leadMon / factor);
            result.addMonomial(term);
            remainder = remainder - p * term;
        }
        result.simplify();
        return result;
    }

    Polynomial derivative() const {
        Polynomial result;
        for (const auto& mon : monomials) {
            result.addMonomial(mon.derivative());

        }
        result.simplify();
        return result;
    }
   
    int degree() const {
        if (monomials.empty()) {
            return 0;
        }
        return monomials.back().degree();
    }

  
    void addMonomial(const Monomial& m) {
        if (m.coefficient != 0.0) {
            monomials.push_back(m);
        }
    }


    void simplify() {
        sort(monomials.begin(), monomials.end(), [](const Monomial& m1, const Monomial& m2) {
            return m1.degree() > m2.degree();
            });
        for (size_t i = 0; i < monomials.size() - 1; ++i) {
            if (monomials[i].degree() == monomials[i + 1].degree()) {
                monomials[i] = monomials[i] + monomials[i + 1];
                monomials.erase(monomials.begin() + i + 1);
                --i;
            }
        }
        monomials.erase(
            remove_if(monomials.begin(), monomials.end(), [](const Monomial& m) { return m.coefficient() == 0.0; }),
            monomials.end());
    }

   
    void print() const {
        if (monomials.empty()) {
            cout << "0";
        }
        else {
            for (size_t i = 0; i < monomials.size(); ++i) {
                if (i != 0) {
                    if (monomials[i].coefficient() >= 0) {
                        cout << " + ";
                    }
                    else {
                        cout << " - ";
                    }
                }
                monomials[i].print();
            }
        }
    }
    };

    int main() {
        Monomial m1(3.0, 2);
        Monomial m2(2.0, 3);
        Monomial m3(4.0, 1);
        Monomial m4(5.0, 0);
        Polynomial p1;
        p1.addMonomial(m1);
        p1.addMonomial(m2);
        p1.addMonomial(m3);
        p1.addMonomial(m4);

        Polynomial p2;
        Monomial m5(2.0, 3);
        Monomial m6(1.0, 1);
        Monomial m7(2.0, 0);
        p2.addMonomial(m5);
        p2.addMonomial(m6);
        p2.addMonomial(m7);

        Polynomial p3 = p1 + p2;
        Polynomial p4 = p1 - p2;
        Polynomial p5 = p1 * p2;
        Polynomial p6 = p1 / p2;

        p1.print();
        cout << endl;
        p2.print();
        cout << endl;
        p3.print();
        cout << endl;
        p4.print();
        cout << endl;
        p5.print();
        cout << endl;
        p6.print();
        cout << endl;

        return 0;

    }
