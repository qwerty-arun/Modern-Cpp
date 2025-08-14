#include<iostream>
#include<string>
using namespace std;

class Phone{
    string _name = "";
    string _os= "";
    int _price = 0;
public:
    Phone(); //default constructor
    Phone(const string &name, const string &os, const int &price); //parameterized constructor
    Phone(const Phone &); //copy constructor

    string getName()
    {
        printf("Value of getName is %p\n", this);
        return _os;
    }
    int getPrice();

    ~Phone(); //destructor
};

int Phone::getPrice()
{
    printf("Value of getPrice is %p\n", this);
    return _price;
}

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
    // puts("Overwrite copy constructor");
    _name = "new-"+values._name;
    _os = "skinned-"+values._os; //little modification
    _price = values._price;
}

Phone::~Phone(){
    // cout << "Destructor called for "<< _name << endl;
    // printf("Destructor called for %s\n", _name.c_str());
}

int main(){

    Phone OnePlus8("OP8", "Android-Oxy", 799);
    cout << OnePlus8.getName()<<endl;

    printf("Value of object is %p\n", &OnePlus8);
    cout << OnePlus8.getPrice()<<endl;
    return 0;
}