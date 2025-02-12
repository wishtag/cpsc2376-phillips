#include <iostream>
#include <string>

template <typename T>
T calculate(T num1, T num2, char op) {
    T result;
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            std::cout << "Error: Division by zero.\n";
            result = 0;
        }
        break;
    default:
        std::cout << "Error: Invalid operation.\n";
        result = 0;
        break;
    }
    return result;
}

int main()
{
    std::string input1, input2;
    char operation = '+';

    std::cout << "Enter first number: ";
    std::cin >> input1;

    std::cout << "Enter second number: ";
    std::cin >> input2;

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    if (input1.find('.') != std::string::npos or input2.find('.') != std::string::npos)
    {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);

        double result = calculate(num1, num2, operation);
        std::cout << "Result: " << result << "\n";
    }
    else
    {
        int num1 = std::stoi(input1);
        int num2 = std::stoi(input2);

        int result = calculate(num1, num2, operation);
        std::cout << "Result: " << result << "\n";
    }


	return 0;
}