#include <iostream>
#include <string>
using namespace std;

string api_call()
{
    return "Got some data from web\n";
}

int another_api_call()
{
    return 0;
}

int main()
{
    auto reponse = api_call(); //not a separate data type
    // What if you don't what data is coming up from web? int, float etc.
    auto rep = another_api_call();
    cout << "API Call: "<<reponse<<endl;
    cout << "Another API Call: "<<rep<<endl;

    if(typeid(reponse) == typeid(string))
    {
        puts("Type of both ID is string\n");
    }

    if(typeid(rep) == typeid(int))
    {
        puts("Type of both ID is int\n");
    }
    return 0;
}