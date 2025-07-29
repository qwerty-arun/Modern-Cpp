// Write a function template maxOf that returns maximum of two values

#include<iostream>

template<typename T>
T maxOf (T var1, T var2)
{
    return std::max(var1, var2);
}

int main()
{
    std::cout<<maxOf(2, 3);
    return 0;
}