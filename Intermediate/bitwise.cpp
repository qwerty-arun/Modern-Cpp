#include<iostream>
using namespace std;

int main()
{
    unsigned int a = 6;
    unsigned int b = 5;

    unsigned int x = a & b;
    unsigned int y = a | b;
    unsigned int z = a ^ b;
    unsigned int left = x << 1;
    unsigned int right = x >> 1;
    int c = 1;

    cout <<"Value of x is: "<<x<<endl;
    cout <<"Value of y is: "<<y<<endl;
    cout <<"Value of z is: "<<z<<endl;
    cout <<"Negate c: "<<~c<<endl;
    cout <<"Left Shift x: "<<left<<endl;
    cout <<"Right Shift x: "<<right<<endl;
    return 0;
}