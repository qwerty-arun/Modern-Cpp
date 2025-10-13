// Smart Pointer is a wrapper around real "raw" pointer
// Solves the problem of forgetting 'delete' when we use 'new'

// WEAK POINTERS
/*
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
        shared_ptr<User> tim = make_shared<User>();
        weak_ptr<User> wtim = tim; //no one cares
        shared_ptr<User> timm = tim;
    }
    cout << "Outside code\n";
    return 0;
}