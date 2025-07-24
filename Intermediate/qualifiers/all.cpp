// QUALIFIERS
/*
Modification Qualifiers:
    const -> fixed value for a variable
    volatile -> share data between two threads (processes)
    mutable -> changeable

Life Duration Qualifiers:
    static -> in global state
    extern -> store in external libraries
    register -> suggest CPU to store in registers
*/

#include<iostream>
using namespace std;

int lifeUp()
{
    // int life = 3;
    static int life = 3;
    return ++life;
}

int main()
{
    int life = 3;
    cout<<"Your starting game life is: "<<life<<endl;

    life = lifeUp();
    cout<<"Your updated game life is "<<life<<endl;

    life = lifeUp(); //Why doesn't this update?
    cout<<"Your updated game life is "<<life<<endl;
    return 0;
}