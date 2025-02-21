#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums = { 9, 20, 35, 4, 12 };
    std::cout << "Largest element:" << *std::max_element(nums.begin(), nums.end()) << "\n";
    std::cout << "Smallest element:" << *std::min_element(nums.begin(), nums.end()) << "\n";
    return 0;
}