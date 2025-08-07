// const-qualified methods
#include<iostream>
#include<string>
using namespace std;

class User
{
    int _secret = 22; //just a good practice

public:
    string name = "default";
    void message();

    int get_secret() const; //const qualified

    void set_secret(const int &sec)
    {
        _secret = sec;
    }
};

int User::get_secret()const {return _secret;}

void User::message()
{
    cout<< "Class is great"<< name << endl;
}

// Non-const objects can access const methods, but const-objects can't access non-const objects

int main()
{
    User arun = User();
    arun.get_secret();
    arun.set_secret(11);
    arun.get_secret();

    const User rock; //const object
    std::cout << rock.get_secret() << endl; //error if const not defined in function
    return 0;
}