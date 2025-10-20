/*
By default, lambdas capturing by value can't modify captured variables.
- Use `mutable` to allow modifications (they affect only the copy inside the lambda).
*/
#include <iostream>

int main() {
    int x = 10;

    auto modify = [x]() mutable {
        x++;
        std::cout << x << std::endl; // 11
    };

    modify();
    std::cout << x << std::endl; // 10 (original unchanged)
}
