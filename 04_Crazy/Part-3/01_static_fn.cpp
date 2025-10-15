#include <iostream>

class MyClass {
public:
    static void displayMessage() {
        std::cout << "Hello, World!";
    }
};

int main() {
    MyClass::displayMessage(); // Called without an object.
    return 0;
}
