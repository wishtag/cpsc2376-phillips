#pragma once
#include <stdexcept>
#include <iostream>

class Fraction {
private:
    int num;
    int den;

public:
    Fraction();
    Fraction(int n, int d);

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int d); // Throws exception if d == 0

    void simplify();

    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs); // Throws exception if division by zero occurs
};