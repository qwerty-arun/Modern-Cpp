/*
Const-Correctness
Using const in this way enforces good coding practices (known as "const-correctness"), helping prevent accidental modification of objects and making interfaces safer and clearer. Functions marked const can only call other const member functions.

What const Does in Member Functions?

- Placing const after the parameter list in a member function signifies that the function is "read-only" with respect to the class instance: it cannot alter any (non-mutable) member variables of the class.​

- This enables the function to be safely called on const instances of the class, as it guarantees the object's state will not change.
*/
#include <iostream>
using namespace std;

class MyClass
{
public:
    int value;
    int getValue() const
    {
        value += 1;
        return value;
    } // 'const': cannot modify 'value'
    void setValue(int v) { value = v; } // non-const: can modify 'value'
};

int main()
{
    MyClass m;
    m.setValue(5);
    cout << m.getValue();
    return 0;
}