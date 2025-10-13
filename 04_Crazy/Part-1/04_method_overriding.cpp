/*
Method Overriding:

Method overriding in C++ is a feature in object-oriented programming where a derived class provides its own implementation of a method that is already defined in its base class using the same signature (name, return type, and parameters). This enables runtime polymorphism, allowing the derived class's version of the method to be called through base class pointers or references.

Key Points of Method Overriding
- The base class method must be declared with the virtual keyword to enable overriding.
- The derived class redefines the method with the same signature.
- Overriding methods can use the override keyword (C++11 onwards) to indicate intent and enable compiler checks.
- Method overriding supports dynamic dispatch (calls resolved at runtime).

Why Use override?
- It ensures the function actually overrides a base class's virtual function.
- Helps catch errors if signatures mismatch (e.g., typo in function name).
- Improves code readability.
*/

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {              // Virtual function in base class
        cout << "Animal makes a sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() override {             // Override base class method
        cout << "Dog barks\n";
    }
};

int main() {
    Animal* animal = new Dog(); // Animal pointer to Dog object
    animal->sound();            // Calls Dog's overridden sound()
    delete animal;
    return 0;
}
