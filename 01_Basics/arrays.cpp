#include<iostream>
using namespace std;

int main()
{
    int a[5]{1,2,3,4,5}; //int a[4] = {1,2,3,4};
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;

    *a = 20;
    *(a+1) = 40; // same as a[1] = 40;
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;

    int *ptr = a;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    ptr++;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    return 0;
}