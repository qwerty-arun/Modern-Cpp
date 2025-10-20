/*
Partial Specialization:
- Applies to classes only.
- Customize behavior for a subset of template parameters.
*/
#include <iostream>

// Generic template
template <typename T1, typename T2>
class Pair {
public:
    void print() { std::cout << "Generic Pair\n"; }
};

// Partial specialization when both types are the same
template <typename T>
class Pair<T, T> {
public:
    void print() { std::cout << "Specialized Pair with same types\n"; }
};

int main() {
    Pair<int, double> p1; p1.print();   // Generic Pair
    Pair<int, int> p2;    p2.print();   // Specialized Pair
}
