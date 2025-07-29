// Generic Pair
/*
Create a template class Pair<T1, T2> that stores two values of potentially
different types
*/

#include<iostream>

template <typename T>
class ClassName {
    T member;
public:
    ClassName(T val) : member(val) {}
    T getMember() { return member; }
};

int main()
{
    ClassName c("arun");
    std::cout<<c.getMember();
    return 0;
}