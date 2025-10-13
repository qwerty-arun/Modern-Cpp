// Generic Pair
/*
Create a template class Pair<T1, T2> that stores two values of potentially
different types
*/

#include<iostream>

template<typename T1, typename T2>
class Pair{
    T1 member1;
    T2 member2;
public:
    Pair(T1 t1, T2 t2) : member1(t1), member2(t2){}
    T1 getMember1() { return member1; } //use const T1&
    T2 getMember2() { return member2; } //use const T2&
};

int main()
{
    Pair p("arun", 10);
    Pair<std::string, int> p1("arun", 10); // Uses std::string
    std::cout<<p.getMember1()<<std::endl;
    std::cout<<p.getMember2()<<std::endl;
    std::cout<<p1.getMember1()<<std::endl;
    std::cout<<p1.getMember2()<<std::endl;
    return 0;
}