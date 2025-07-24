#include<iostream>
using namespace std;

struct User
{
    const int uId;
    const char *name; //this is a const pointer and not const value
    const char *email;
    int course_count;
};

int main()
{
    User mickey = {001, "mickey", "mickey@cartoon.com", 2};
    User donald = {001, "donald", "donald@cartoon.com", 4};

    User *d = &donald;

    cout << mickey.course_count<<endl;
    cout << mickey.email<<endl;
    donald.course_count = 4;
    donald.email = "donald@huh.com"; //we can change value
    // donald.uId = 400;

    cout << d->course_count<<endl;
    cout << d->name<<endl;
    return 0;
}