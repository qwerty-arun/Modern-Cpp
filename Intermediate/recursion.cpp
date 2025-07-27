#include<iostream>

int factorial(int); //function prototype

int main()
{
    std::cout<<factorial(5)<<std::endl;
    return 0;
}

int factorial(int n)
{
    if(n==0)
        return 1;
    return n * factorial(n-1);
}