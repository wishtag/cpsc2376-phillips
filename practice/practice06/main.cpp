#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

int main() {
    Fraction fraction;
    int choice = 0;
    while (choice != 8) {
        std::cout << "Current Fraction: " << fraction << "\n\n";
        std::cout << "Options:\n";
        std::cout << "1. Enter a fraction manually\n";
        std::cout << "2. Add a fraction\n";
        std::cout << "3. Subtract a fraction\n";
        std::cout << "4. Multiply by a fraction\n";
        std::cout << "5. Divide by a fraction\n";
        std::cout << "6. Display as Mixed Fraction\n";
        std::cout << "7. Clear Fraction\n";
        std::cout << "8. Exit\n";


        std::cin >> choice;

        while (std::cin.fail() || choice > 8 || choice < 1) {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> choice;
        }

        std::cin.ignore(256, '\n');

        switch (choice) {
        case 1: {
            std::cout << "Enter a fraction:\n";
            std::cin >> fraction;
            break;
        }
        case 2: {
            Fraction fraction2;
            std::cout << "Enter a fraction to add:\n";
            std::cin >> fraction2;
            fraction = fraction + fraction2;
            break;
        }
        case 3: {
            Fraction fraction2;
            std::cout << "Enter a fraction to subtract:\n";
            std::cin >> fraction2;
            fraction = fraction - fraction2;
            break;
        }
        case 4: {
            Fraction fraction2;
            std::cout << "Enter a fraction to multiply by:\n";
            std::cin >> fraction2;
            fraction = fraction * fraction2;
            break;
        }
        case 5: {
            Fraction fraction2;
            std::cout << "Enter a fraction to divide by:\n";
            std::cin >> fraction2;
            fraction = fraction / fraction2;
            break;
        }  
        case 6: {
            MixedFraction mixedFraction(fraction);
            std::cout << "Your fraction as a mixed fraction is: " << mixedFraction << "\n";
            break;
        }
        case 7: {
            fraction.setNumerator(0);
            fraction.setDenominator(1);
            break;
        }
        }
        
    }
    
    return 0;
}