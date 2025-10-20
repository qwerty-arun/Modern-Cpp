//Lambdas can access variables from the scope they are defined in through the capture list []

/*
Capture Modes: 

[]          -> Capture nothing
[=]         -> Capture all variables by value
[&]         -> Capture all variables by reference
[=, &x]     -> Capture all by value except 'x' by reference
[&, x]      -> Capture all by reference except 'x' by value
*/
#include <iostream>

int main() {
    int x = 10, y = 20;

    // Capture by value
    auto byValue = [x, y]() {
        std::cout << x + y << std::endl;
    };

    // Capture by reference
    auto byRef = [&x, &y]() {
        x++;
        y++;
    };

    byValue();  // prints 30
    byRef();    // modifies x and y
    std::cout << x << " " << y << std::endl; // prints 11 21
}
