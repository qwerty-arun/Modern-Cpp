#include<iostream>
#include<string>
using namespace std;

// Without 'move', it can be memory intensive for classes as parameters (they may have 100 of data members)
void swap(int &a, int &b)
{
    int tmp = move(a);
    a = move(b);
    b = move(tmp);
}

string printMe()
{
    return "I am string";
}

int main()
{
    int a =2 , b = 5;
    cout<<"a: "<<a<<" ,b:"<<b<<endl;
    swap(a,b);
    cout<<"a: "<<a<<" ,b:"<<b<<endl;

    string s = printMe();  //makes a reference
    string&& ss = printMe(); //doesn't make a reference or a copy
    return 0;
}