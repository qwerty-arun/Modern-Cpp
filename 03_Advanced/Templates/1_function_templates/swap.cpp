// Write a template function to swap two variables of any type

#include<iostream>

template<typename T>
void swap(T &var1, T &var2)
{
    T temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

int main()
{
    int a = 4, b= 5;
    std::cout<<a<<" "<<b<<std::endl;
    swap(a, b);
    std::cout<<a<<" "<<b<<std::endl;
    return 0;
}