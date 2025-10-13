#include<iostream>
using namespace std;

// Call by value
void lifeUp(int *life)
{
     ++(*life);
}

// Call by reference 1
void lifeInc(int life)
{
    ++life;
}

// Call by reference 2
void incLife(int &life)
{
    ++life;
}

int main()
{
    int life = 10;
    lifeUp(&life);
    cout<<life<<endl; //expect 11
    lifeInc(life);
    cout<<life<<endl; //expect 12, but got 11
    incLife(life);
    cout<<life<<endl; //expect 12
    return 0;
}