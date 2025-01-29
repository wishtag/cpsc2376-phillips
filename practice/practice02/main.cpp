// If there are any stupid mistakes in this code, I blame it on the
//  fact that recently I've been programming in Python and Lua on
//  top of C++

// I also thought about not passing the file name as a parameter
//  considering that for this program it will always use the same
//  file name, but I figured passing the file name is probably better
//  practice

// I didn't manually close any of the "ifstream"s or "ofstream"s objects
//  because, too my understanding, they are closed once they are out
//  of scope a.k.a. the function finishes

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int getInt(const std::string& prompt) {
    int input;
    std::cout << prompt;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return input;
}

float getFloat(const std::string& prompt) {
    float input;
    std::cout << prompt;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return input;
}

// This function is used specifically for the "Check Balance" option
//  and to run at start up to check if "account_balance.txt", or
//  whatever other file name is passed, exists
void checkBalance(const std::string& name) {
    std::ifstream balance(name);

    if (!balance.is_open()) {
        balance.close();
        std::ofstream initialized_balance(name);
        initialized_balance << "100.00";
        std::cout << "\nInitializing account with $100.00\n";
    } else {
        std::string line;
        getline(balance, line);
        std::cout << "\nYour current balance is: $" << line << "\n";
    }
}

// This function gets the first line from the file name passed and
//  returns that value as a float
float readBalanceFromFile(const std::string& name) {
    std::ifstream file(name);

    if (!file.is_open()) {
        // The only scenario this should be triggered is if
        //  "account_balance.txt" is deleted during runtime
        std::cout << name << " cannot be located please restart the program.";
        exit(1);
    } else {
        std::string line;
        getline(file, line);
        return std::stof(line);
    }
}

// This function writes the value passed as "balance" to the passed
//  file from "name"
void writeBalanceToFile(const std::string& name, const float& balance) {
    std::ofstream file(name);
    file.precision(2);

    file << std::fixed << balance;
}

// This function prompts the user for an amount to deposit, if the amount
//  entered is not more than 1 cent then they are prompted to enter
//  a new number
void deposit(const std::string& name) {
    bool not_valid = true;
    float deposit_amount;
    while (not_valid) {
        deposit_amount = getFloat("Enter deposit amount: $");
        if (deposit_amount >= 0.01) {
            not_valid = false;
        } else {
            std::cout << "Error: Deposit amount must be greater than or equal to $0.01\n";
        }
    }
    
    float balance = readBalanceFromFile("account_balance.txt");
    balance = balance + deposit_amount;
    writeBalanceToFile("account_balance.txt", balance);
    std::cout << "\nDeposit successful. Your new balance is: $" << balance << "\n";
}

// This function prompts the user for an amount to withdraw, if the
//  amount entered is not more than 1 cent or the amount entered 
//  is more than they have in their balance, they are prompted to
//  enter a new number
void withdraw(const std::string& name) {
    bool not_valid = true;
    float withdraw_amount;
    float balance = readBalanceFromFile("account_balance.txt");
    while (not_valid) {
        withdraw_amount = getFloat("Enter withdrawal amount: $");
        if (withdraw_amount >= 0.01 && withdraw_amount <= balance) {
            not_valid = false;
        } else {
            std::cout << "Error: Withdrawal amount must be greater than or equal to $0.01\n";
            std::cout << "       and less than or equal to your current balance.\n";
        }
    }
    
    balance = balance - withdraw_amount;
    writeBalanceToFile("account_balance.txt", balance);
    std::cout << "\nWithdrawal successful. Your new balance is: $" << balance << "\n";
}

int main() {
    std::cout.precision(2);
    std::cout << "\n\n\nWelcome to Your Bank Account!\n" << std::fixed;
    checkBalance("account_balance.txt");
    
    int choice = 0;

    while (choice != 4) {
        std::cout << "\n[1] Check Balance\n";
        std::cout << "[2] Deposit Money\n";
        std::cout << "[3] Withdraw Money\n";
        std::cout << "[4] Exit\n";
        choice = getInt("Selection: ");

        switch (choice) {
            case 1: {
                checkBalance("account_balance.txt");
                break;
            }
            case 2: {
                deposit("account_balance.txt");
                break;
            }
            case 3: {
                withdraw("account_balance.txt");
                break;
            }
            case 4: {
                std::cout << "Thank you for banking with us!\n";
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