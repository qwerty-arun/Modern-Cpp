#include<iostream>
#define NULL 0
using namespace std;

void printval(int a)
{
    cout<<"Integer: "<<a<<endl;
}

void printval(double a)
{
    cout<<"Double: "<<a<<endl;
}

void printval(int *a)
{
    printf("Pointer: %p\n", a);
    // cout<<"Pointer: "<<a<<endl;
}

int main()
{
    printval(NULL); //It calls the integer value function, not pointer
    printval(nullptr);
    return 0; 
}