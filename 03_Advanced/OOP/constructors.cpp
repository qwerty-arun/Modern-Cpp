#include<iostream>
#include<string>
using namespace std;

class Phone{
    string _name = "";
    string _os= "";
    int _price = 0;
    // Phone(); //default constructor but disabled (not accessible)
public:
    Phone(); //default constructor
    Phone(const string &name, const string &os, const int &price); //parameterized constructor
    Phone(const Phone &); //copy constructor
    string getName(){return _os;}
    ~Phone(); //destructor
};

Phone::Phone() : _name(), _os("Andy"), _price()
{
    puts("Default Constructor");
}

Phone::Phone(const string &name, const string &os, const int &price) : _name(name), _os(os), _price(price)
{
    puts("This is parameter constructor");
}

Phone::Phone(const Phone &values)
{
    puts("Overwrite copy constructor");
    _name = "new-"+values._name;
    _os = "skinned-"+values._os; //little modification
    _price = values._price;
}

Phone::~Phone(){
    cout << "Destructor called for "<< _name << endl;
    printf("Destructor called for %s\n", _name.c_str());
}

int main(){
    Phone samsung;
    cout << samsung.getName()<<endl;

    Phone OnePlus8("OP8", "Android-Oxy", 799);
    cout << OnePlus8.getName()<<endl;

    Phone OnePlus8S = OnePlus8;
    cout << OnePlus8S.getName()<<endl;

    return 0;
}