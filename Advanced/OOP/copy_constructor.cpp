// Read about the rule of three
// https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three

#include<iostream>
#include<string>
using namespace std;

class User
{
    int _secret = 22;

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
    arun.name = "arun";
    arun.get_secret();
    arun.set_secret(11);
    arun.get_secret();

    const User rock; //const object
    std::cout << rock.get_secret() << endl; //error if const not defined in function

    User peter = arun;
    std::cout << peter.get_secret() << endl; 
    std::cout << arun.get_secret() << endl; 

    return 0;
}