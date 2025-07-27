#include<iostream>
using namespace std;

int getno()
{
    return 1;
}

void interesting()
{
    puts("I am interesting");
}

int main()
{
    int huh = getno(); //call the function
    void (*pointer)() = interesting; //just points to interesting, not running it

    cout<<huh<<endl;
    pointer();
    (*pointer)();
    return 0;
}