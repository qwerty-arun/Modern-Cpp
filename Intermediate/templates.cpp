#include<iostream>
using namespace std;

template<typename Type>
// You can even use class instead of typename
Type addme(Type a, Type b)
{
    return a+b;
}

int main()
{
    cout<<addme(1,3)<<endl;
    cout<<addme(1.2, 5.7)<<endl;
    return 0;
}