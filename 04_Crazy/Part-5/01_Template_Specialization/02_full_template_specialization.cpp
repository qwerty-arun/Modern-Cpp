/*
Full Template Specialization:
- Applies to Functions & Classes.
- Specialize all template parameters (specific case).
*/
#include <iostream>

// Primary (generic) template
template <typename T>
void printType(T value) {
    std::cout << "Generic version: " << value << std::endl;
}

// Specialized template for const char*
template <>
void printType<const char*>(const char* value) {
    std::cout << "Specialized version for strings: " << value << std::endl;
}

int main() {
    printType(42);        // uses generic
    printType(3.14);      // uses generic
    printType("Hello");   // uses specialized version
}
