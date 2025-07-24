#include <iostream>
int main() {
    const int num = 50;
    // num = 60; // Error: cannot modify a const variable
    std::cout << "Value of num is: " << num << std::endl;
    return 0;
}