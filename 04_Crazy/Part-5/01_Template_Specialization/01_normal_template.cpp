/*
Template Specialization:
Customize how a template behaves for a specific type or set of template arguments.
*/

//Normal Template: allows you to write generic code that works for many data types.
#include <iostream>

template <typename T>
void printType(T value) {
    std::cout << "Generic version: " << value << std::endl;
}

int main() {
    printType(42);        // int
    printType(3.14);      // double
    printType("Hello");   // const char*
}
