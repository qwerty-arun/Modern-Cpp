/*
Dynamic dispatch in C++ refers to the mechanism that determines which specific function implementation to execute at runtime, based on the actual type of an object being pointed to or referenced, rather than its declared type. This is a cornerstone of polymorphism in C++.

How it works in C++:
- Virtual Functions: Dynamic dispatch in C++ is primarily achieved through virtual functions. When a member function in a base class is declared with the virtual keyword, it indicates that derived classes can override this function, and the specific version to be called should be determined at runtime.

- Pointers and References to Base Class: To leverage dynamic dispatch, you must use pointers or references to the base class type. When you call a virtual function through such a pointer or reference, the C++ runtime examines the actual type of the object it points to and executes the appropriate overridden version of the function in the derived class.

- Vtables and Vpointers: Internally, C++ compilers typically implement dynamic dispatch using vtable (virtual table) and vpointer (virtual pointer) mechanisms. Each class with virtual functions has a vtable, which is an array of function pointers to the virtual functions of that class. Each object of such a class contains a vpointer, which points to the vtable of its actual type. When a virtual function is called, the vpointer is used to look up the correct function address in the vtable and then call it.
*/

#include <iostream>

class Base {
public:
    virtual void greet() {
        std::cout << "Hello from Base!" << std::endl;
    }
};

class Derived : public Base {
public:
    void greet() override { // 'override' keyword is good practice
        std::cout << "Hello from Derived!" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived(); // Base pointer pointing to a Derived object
    basePtr->greet(); // Dynamic dispatch: calls Derived::greet()
    delete basePtr;

    Base baseObj;
    baseObj.greet(); // Static dispatch: calls Base::greet()

    return 0;
}