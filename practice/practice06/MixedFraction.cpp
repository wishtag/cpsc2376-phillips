#include "MixedFraction.h"
#include <iostream>

MixedFraction::MixedFraction(int w, int n, int d) : whole(w), Fraction(n, d) {}

MixedFraction::MixedFraction(const Fraction& fraction) {
	whole = fraction.getNumerator() / fraction.getDenominator();
	setNumerator(fraction.getNumerator() % fraction.getDenominator());
	setDenominator(fraction.getDenominator());
}

std::ostream& operator<<(std::ostream& out, const MixedFraction& frac) {
	out << frac.whole << " " << frac.getNumerator() << "/" << frac.getDenominator();
	return out;
}