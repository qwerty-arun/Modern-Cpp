#include<iostream>
#include<string>
using namespace std;

int main()
{
    //empty lambda
    []{}();

    //simple
    []{cout<<"Hello World\n";}();

    //what?
    [](){return 100;};
    
    //generalized lambda
    auto sum = [](auto a, auto b){return a+b;};

    cout<<"Sum of 2 and 5: "<< sum(2,5)<<endl;
    cout<<"Sum of 2.4 and 5.7: "<< sum(2.4,5.7)<<endl;

    string a = "abc";
    string b = "def";
    cout<<"Sum of abc and def: "<< sum(a,b)<<endl;
    return 0;
}