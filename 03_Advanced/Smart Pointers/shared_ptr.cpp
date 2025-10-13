// Smart Pointer is a wrapper around real "raw" pointer
// Solves the problem of forgetting 'delete' when we use 'new'

// SHARED POINTERS
/*
1. Pointers point to same memory 
2. You can copy them
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

    {
        // shared_ptr<User> tim(new User()); //creates heap memory, not good
        shared_ptr<User> tim = make_shared<User>(); //uses stack (continuous block)
        shared_ptr<User> timm = tim;
        // deleting the block is very easy in stack
    }
    cout << "Outside code\n";
    return 0;
}