#include <iostream>
#include <vector>
#include <string>

int getInt(const std::string& prompt) {
    int input;
    std::cout << prompt;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return input;
}

void printVector(const std::vector<int>& mainVector) {
    for (int i = 0; i < mainVector.size(); ++i) {
        std::cout << mainVector.at(i) << " ";
    }
    //std::cout << "\n";
}

void doubleVector(std::vector<int>& mainVector) {
    for (int i = 0; i < mainVector.size(); ++i) {
        mainVector.at(i) *= 2;
    }
}

void sum(const std::vector<int>& mainVector) {
    int sum = 0;
    for (int i = 0; i < mainVector.size(); ++i) {
        sum += mainVector.at(i);
    }
    std::cout << sum;
}

void printMultiples(const std::vector<int>& mainVector, int number) {
    for (int i = 0; i < mainVector.size(); ++i) {
        if (mainVector.at(i) % number == 0) {
            std::cout << mainVector.at(i) << " ";
        }
    }
}

int main() {
    std::vector<int> mainVector;
    int choice = 0;

    while (choice != 5)
    {
        std::cout << "\n[0] Add an item to a vector\n";
        std::cout << "[1] Print the vector\n";
        std::cout << "[2] Double the vector\n";
        std::cout << "[3] Find the sum\n";
        std::cout << "[4] Print multiples of a user-defined value\n";
        std::cout << "[5] Exit\n";
        choice = getInt("Selection: ");

        switch (choice) {
            case 0: {
                mainVector.push_back(getInt("New Number: "));
                break;
            }
            case 1: {
                printVector(mainVector);
                break;
            }
            case 2: {
                doubleVector(mainVector);
                break;
            }
            case 3: {
                sum(mainVector);
                break;
            }
            case 4: {
                printMultiples(mainVector,getInt("Enter a number to find multiples: "));
                break;
            }
            default: {
                std::cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    }
    
	return 0;
}