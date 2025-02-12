#include <iostream>
#include <string>

void greet(std::string name = "Guest", std::string prefix = "Hello")
{
    std::cout << "\n" << prefix << ", " << name << "\n\n";
}

int main()
{
    int choice;
    std::string name;
    std::string greeting;
    while (true)
    {
        std::cout << "1. Default Greeting\n2. Greet by Name\n3. Custom Greeting\nChoose an option: ";
        std::cin >> choice;

        while (std::cin.fail() || choice > 3 || choice < 1)
        {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> choice;
        }

        std::cin.ignore(256, '\n');  // Clear the newline from input buffer

        switch (choice)
        {
        case 1:
            greet();
            break;
        case 2:
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            greet(name);
            break;
        case 3:
            std::cout << "Enter Greeting Prefix: ";
            std::getline(std::cin, greeting);
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            greet(name, greeting);
            break;
        default:
            break;
        }
    }
}
