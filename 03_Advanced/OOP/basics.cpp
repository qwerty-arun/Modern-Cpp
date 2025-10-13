#include<iostream>
#include<string>
using namespace std;

class User
{
    int secret = 22;

public:
    string name = "default";
    void message(){cout<< "Class is working! User is "<<name<<endl;}
};

int main()
{
    User arun = User();
    User ram = User();
    ram.name = "ram";
    arun.message();
    ram.message();
    return 0;
}