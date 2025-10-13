#include <iostream>
extern int globalVar; // Declaration: says globalVar exists elsewhere

int main() {
    std::cout << "Value of globalVar: " << globalVar << std::endl;
    return 0;
}