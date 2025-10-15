#include <iostream>
using namespace std;

// Class A has a parameterized constructor
class A {
    int value;
public:
    A(int v) {
        value = v;
        cout << "A's constructor called with value = " << value << endl;
    }

    int getValue() const {
        return value;
    }
};

// Class B contains an object of class A as a member
class B {
    A aObj;  // member object of class A
    int num;

public:
    // Member initializer list used to initialize 'aObj' and 'num'
    B(int x, int y) : aObj(x), num(y) {
        cout << "B's constructor called with num = " << num << endl;
    }

    void display() const {
        cout << "Values: aObj.value = " << aObj.getValue()
             << ", num = " << num << endl;
    }
};

// Driver function
int main() {
    B obj(10, 20);
    obj.display();
    return 0;
}
