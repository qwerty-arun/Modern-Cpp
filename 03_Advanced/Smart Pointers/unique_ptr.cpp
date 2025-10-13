// Smart Pointer is a wrapper around real "raw" pointer
// Solves the problem of forgetting 'delete' when we use 'new'

// UNIQUE POINTERS
/*
1. Memory get free as scope ends
2. You cannot copy them
*/

#include<iostream>
#include<memory>
using namespace std;

class User
{
public:
    User(){
        cout << "User created\n";
    }

    ~User(){
        cout << "User destroyed\n";
    }

    void testFunc()
    {
        cout<< "I am a test function of User\n";
    }
};

int main()
{
    {
        // unique_ptr<User> arun = new User(); //Not allowed
        // unique_ptr<User> arun(new User()); //Non fav

        unique_ptr<User> arun = make_unique<User>(); //Cool
        arun->testFunc();

        // unique_ptr<User> arunn = arun; //not allowed
    }
    cout << "Outside code\n";
    return 0;
}