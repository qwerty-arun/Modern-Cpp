#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {5, 1, 4, 2, 3};

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b; // sort descending
    });

    for (int n : nums)
        std::cout << n << " ";
}
