#include<iostream>
#include<string>
using namespace std;

class User
{
    int _secret = 22;

public:
    string name = "default";
    void message(){cout<< "Class is working! User is "<<name<<endl;}

    void get_secret(){cout<< "Secret: "<< _secret<<endl;}

    void set_secret(const int &sec)
    {
        _secret = sec;
    }
};

int main()
{
    User arun = User();
    arun.get_secret();
    arun.set_secret(11);
    arun.get_secret();
    return 0;
}