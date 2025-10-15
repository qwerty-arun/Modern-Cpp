/*
Brace initialization in C++ (also called uniform initialization) uses curly braces {} and provides a unified way to initialize variables, objects, arrays, and class/struct members. This style was introduced in C++11 and helps prevent narrowing conversions, promotes clarity, and allows direct list initialization.

Key Notes
- Brace initialization prevents narrowing conversions, such as assigning a floating-point value to an integer.
- Classes/structs without constructors will use the braces to initialize public members in the declared order; all members must be initialized when using brace syntax.​
- For containers like std::vector, the braces initialize from a list, while parentheses call other constructors (like size/initial value).​

This syntax works for built-in types, aggregate types, classes, and can make code more expressive and consistent.
*/

#include <iostream>
#include <vector>

int main()
{
    int i{};               // i is value-initialized to 0
    int j{10};             // j is initialized to 10
    int arr[]{1, 2, 3, 4}; // arr is initialized to {1,2,3,4}

    struct Point
    {
        int x;
        int y;
    };

    Point p1{};     // p1.x = 0, p1.y = 0
    Point p2{1, 5}; // p2.x = 1, p2.y = 5

    class Box
    {
    public:
        int w;
        int h;
        Box(int ww, int hh) : w{ww}, h{hh} {} // brace initialization for members
    };
    Box b{7, 8}; // b.w = 7, b.h = 8

    std::vector<int> v1{9, 10, 11};    // Creates vector with elements 9, 10, 11
    std::string name{"Michael Scott"}; // name initialized to "Michael Scott"

    return 0;
}