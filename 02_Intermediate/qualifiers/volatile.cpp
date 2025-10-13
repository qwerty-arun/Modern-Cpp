/*
Tells the compiler that the variable may be changed at any time 
(such as by hardware or another thread), so it should not optimize 
out repeated reads or writes.
*/
// WHEN TO USE
/*
- For variables updated by hardware interrupts, signal handlers, or other threads.
- For memory-mapped hardware registers in embedded system
*/

#include <iostream>
volatile int flag = 0;
int main() {
    while (flag == 0) {
        // Wait for flag to be changed externally
    }
    std::cout << "Flag changed!\n";
    return 0;
}