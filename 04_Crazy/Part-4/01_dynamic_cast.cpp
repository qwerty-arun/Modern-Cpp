/*
Dynamic Cast:

In C++, dynamic_cast is a runtime-checked cast operator primarily used for safely converting pointers or references within an inheritance hierarchy, especially for downcasting (casting a base class pointer or reference to a derived class type). For dynamic_cast to work, the base class must be polymorphic—meaning it includes at least one virtual function. 

The syntax is:
dynamic_cast<new_type>(expression);

- If the cast is valid (the actual object pointed to matches the target type), dynamic_cast returns the appropriately typed pointer or reference. If the cast is invalid, it returns nullptr for pointers or throws a std::bad_cast exception for references.

- dynamic_cast involves runtime overhead because it verifies the object's actual type using Run-Time Type Information (RTTI). This mechanism ensures safer type conversions compared to static_cast, which does no runtime checks and can cause undefined behavior if used incorrectly for downcasting.
*/

#include <iostream>
#include <typeinfo> // For std::bad_cast

class Base {
public:
    virtual void speak() { std::cout << "I am Base\n"; }
    virtual ~Base() = default; // Polymorphic base class
};

class Derived : public Base {
public:
    void speak() override { std::cout << "I am Derived\n"; }
    void derivedOnly() { std::cout << "Derived class specific function\n"; }
};

int main() {
    Base* basePtr = new Derived();  // Base pointer to Derived object

    // Safe downcast using dynamic_cast
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->speak();            // Outputs: I am Derived
        derivedPtr->derivedOnly();      // Outputs: Derived class specific function
    } else {
        std::cout << "Cast failed\n";
    }

    // Attempt invalid cast: Base object, not Derived
    Base* plainBasePtr = new Base();
    Derived* invalidCast = dynamic_cast<Derived*>(plainBasePtr);
    if (invalidCast) {
        invalidCast->speak();
    } else {
        std::cout << "Invalid cast detected\n";  // This will print
    }

    delete basePtr;
    delete plainBasePtr;
    return 0;
}

/*
Explanation:
- dynamic_cast safely converts basePtr (a Base* pointing to a Derived object) to Derived*.
- If the cast is valid, derivedPtr is non-null, so we can call derived-class methods safely.
- The second cast tries to convert a Base* pointing to a plain Base object, so it fails and returns nullptr.
- This shows how dynamic_cast prevents unsafe type conversions at runtime.
*/