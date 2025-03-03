#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

int main() {
    Fraction frac1(6,5);
    //MixedFraction frac2(1,1,5);
    MixedFraction frac2(frac1);

    std::cout << frac1 << "\n";
    std::cout << frac2 << "\n";
}