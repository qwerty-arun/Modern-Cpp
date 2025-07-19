#include <iostream>
#include <concepts>

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template <Number T>
T square(T x) {
    return x * x;
}

int main() {
    std::cout << square(5) << "\n";     // Works (int)
    std::cout << square(2.5) << "\n";   // Works (double)
    // std::cout << square("hi");       // Compile-time error!
}