/*
What It Does
- For variables in functions: retains their value across function calls.
- For class members: creates a member shared by all class objects.
*/

#include <iostream>
void func() {
    static int count = 0;
    count++;
    std::cout << "Count: " << count << std::endl;
}
int main() {
    func();
    func();
    return 0;
}

// Static Class Member

// #include <iostream>
// class Example {
// public:
//     static int count;
//     Example() { count++; }
// };
// int Example::count = 0;
// int main() {
//     Example a, b;
//     std::cout << "Objects created: " << Example::count << std::endl;
//     return 0;
// }
