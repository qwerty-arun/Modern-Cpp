#include <iostream>

int main() {
    auto greet = []() {
        std::cout << "Hello from a lambda!\n";
    };

    greet(); // call the lambda
}
