// Advises compiler to store the variable in CPU register for fast access
#include <iostream>
int main() {
    register int i;
    for (i = 0; i < 5; ++i)
        std::cout << i << " ";
    return 0;
}