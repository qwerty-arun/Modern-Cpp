/*
Function Pointers: 

Function pointers in C++ are pointers that store the address of a function, allowing you to invoke functions indirectly through the pointer. They enable flexible and dynamic function calls, useful for callbacks, event handling, or implementing function tables.Function pointers in C++ are pointers that store the address of a function, allowing you to invoke functions indirectly through the pointer. They enable flexible and dynamic function calls, useful for callbacks, event handling, or implementing function tables.

Syntax:
return_type (*pointerName)(parameter_types);

Example:
int (*funcPtr)(int, int);
*/
#include <iostream>
using namespace std;

// Function prototypes matching a common signature
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b)
{
    if (b == 0)
    {
        cout << "Error: Divide by zero\n";
        return 0;
    }
    return a / b;
}

int main()
{
    // Define a function pointer type for operations
    typedef int (*OperationFunc)(int, int);

    // using keyword, we can define an alias
    // using OperationFunc = int(*)(int, int);

    // Array of function pointers (function table)
    OperationFunc operations[] = {add, subtract, multiply, divide};

    char op;
    int x, y;

    cout << "Enter two integers: ";
    cin >> x >> y;

    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    // Map character to index for operations array
    int opIndex = -1;
    switch (op)
    {
    case '+':
        opIndex = 0;
        break;
    case '-':
        opIndex = 1;
        break;
    case '*':
        opIndex = 2;
        break;
    case '/':
        opIndex = 3;
        break;
    default:
        cout << "Invalid operation\n";
        return 1;
    }

    // Call the selected function via pointer
    int result = operations[opIndex](x, y);
    cout << "Result: " << result << endl;

    return 0;
}
