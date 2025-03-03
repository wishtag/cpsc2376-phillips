#pragma once
#include "Fraction.h"
#include <iostream>

class MixedFraction : public Fraction {
private:
	int whole;
public:
	MixedFraction(int whole, int n, int d); // Initializes a mixed fraction
	MixedFraction(const Fraction& fraction); // Converts a fraction to mixed form

	friend std::ostream& operator<<(std::ostream& out, const MixedFraction& frac);
};