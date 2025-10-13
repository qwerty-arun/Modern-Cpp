// Stack has predefined size
// Heap is predefined but can grow

#include<iostream>
using namespace std;

struct User{
    const int id;
    int age;
    User(): id(001), age(22){} //Without this, error. Why?
};

int main()
{
    int score = 100; //Stack memory
    User mike;

    //heap
    int* heap = new int;
    *heap = 20;

    User* nike = new User();

    delete heap;
    delete nike;
    return 0;
}