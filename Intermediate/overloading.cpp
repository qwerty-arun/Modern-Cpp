#include<iostream>
using namespace std;

int addme(int a, int b)
{
    return a + b;
}

float addme(float a, float b)
{
    return a + b;
}

int main()
{
    cout<<addme(1,2)<<endl;
    cout<<addme(4.4,2.7)<<endl;
    return 0;
}