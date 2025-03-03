#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

int main() {
    Fraction frac1(6,5);
    Fraction frac2(7,9);
    //MixedFraction frac2(1,1,5);
    MixedFraction frac3(frac1);

    std::cout << frac1 << "\n";
    std::cout << frac2 << "\n";
    std::cout << frac3 << "\n";

    std::cout << frac1 + frac2 << "\n";
}