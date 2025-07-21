#include <iostream>
using namespace std;

int main()
{
    int* ptr{nullptr};
    int a = 5;
    ptr = &a;
    cout<< ptr<<endl;
    printf("Value of ptr: %p\n", ptr);
    cout<< *ptr<<endl;
    printf("Value of *ptr: %d\n", *ptr);
    return 0;
}