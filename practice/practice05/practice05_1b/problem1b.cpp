#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> nums;
    int int_count;
    int input;

    std::cout << "Enter the number of integers: ";
    std::cin >> int_count;

    std::cout << "Enter " << int_count << " integers: ";
    for (int i = 0; i < int_count; ++i)
    {
        std::cin >> input;
        nums.push_back(input);
    }

    std::cout << "The integers in reverse order are: ";
    for (auto it = nums.rbegin(); it != nums.rend(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    return 0;
}
