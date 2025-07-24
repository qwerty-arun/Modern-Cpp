/*
Allows a class member to be modified even if it is a 
part of an object declared as const
*/
#include <iostream>
class Test {
    mutable int counter;
public:
    Test() : counter(0) {}
    void increment() const { counter++; }
    int get() const { return counter; }
};
int main() {
    const Test t;
    t.increment();
    std::cout << t.get() << std::endl; // Output: 1
    return 0;
}