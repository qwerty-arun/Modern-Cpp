#include <iostream>

int main()
{
    // -> int is optional
    auto add = [](int a, int b) -> int
    {
        return a + b;
    };

    std::cout << add(3, 4) << std::endl; // 7
}
