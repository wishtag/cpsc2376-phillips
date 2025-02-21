#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

    std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " squared: " << n*n << "\n"; });
    
    int sum = std::accumulate(nums.begin(), nums.end(), 0, [](int acc, int n) { return acc + (n * n); });
    
    std::cout << "Sum of squares: " << sum << "\n";
    
    return 0;
}