/*
std::array<>

std::array in C++ is a container that encapsulates fixed-size arrays with safer and more convenient features than built-in C-style arrays. It provides array operations in a standard container interface.

Key Features of std::array
- Fixed size known at compile time (template parameter).
- Supports standard container operations like .size(), .begin(), .end().
- Elements stored contiguously in memory like C arrays.
- Provides member functions for safer element access (.at() throws on out-of-bounds).
- Supports range-based for loops and STL algorithms seamlessly.
- The size of the array is part of the type, e.g., std::array<int, 5>.

Advantages over C-style arrays
- Size is part of the type, safer to pass around.
- Full STL container interface and interoperability.
- Array size information is preserved.
- Safer element access options.

Conclusion:
std::array is defined in the <array> header and is widely used in modern C++ for fixed-size collections.
*/

#include <iostream>
#include <array>

int main() {
    std::array<int, 5> numbers = {1, 2, 3, 4, 5};

    // Access using []
    std::cout << "First element: " << numbers[0] << "\n";

    // Access using at() - throws if out-of-bounds
    std::cout << "Second element: " << numbers.at(1) << "\n";

    // Modify an element
    numbers[0] = 10;

    // Iterate using range-based for loop
    std::cout << "Elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Fill all elements with a single value
    numbers.fill(0);

    std::cout << "After fill: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
