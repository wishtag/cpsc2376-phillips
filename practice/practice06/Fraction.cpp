#include "Fraction.h"
#include <iostream>

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
    num = n;
    den = d;
    simplify();
}

int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
    den = d;
    simplify();
}

void Fraction::simplify() {
    if (den <= 0) throw std::invalid_argument("Denominator cannot be zero or negative");

    // Compute GCD using Euclidean algorithm
    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a; // GCD is stored in 'a' after loop exits

    // Simplify the fraction
    num /= gcd;
    den /= gcd;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.getNumerator() << "/" << frac.getDenominator();
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    char slash;
    in >> frac.num >> slash >> frac.den;
    frac.simplify();
    if (frac.den == 0) throw std::invalid_argument("Denominator cannot be zero");
    return in;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.getNumerator() * rhs.getDenominator() + rhs.getNumerator() * lhs.getDenominator();
    int denominator = lhs.getDenominator() * rhs.getDenominator();
    return Fraction(numerator, denominator);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.getNumerator() * rhs.getDenominator() - rhs.getNumerator() * lhs.getDenominator();
    int denominator = lhs.getDenominator() * rhs.getDenominator();
    return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.getNumerator() * rhs.getNumerator();
    int denominator = lhs.getDenominator() * rhs.getDenominator();
    return Fraction(numerator, denominator);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.getNumerator() == 0) throw std::invalid_argument("Denominator cannot be zero");
    int numerator = lhs.getNumerator() * rhs.getDenominator();
    int denominator = lhs.getDenominator() * rhs.getNumerator();
    return Fraction(numerator, denominator);
}