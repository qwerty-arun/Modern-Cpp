#include<iostream>
#include<string>
using namespace std;

//exit strategy for one argument
template<typename T>
void func(T t)
{
    cout <<"One Variable temp: " << t <<endl;
}

//recursion used here
//1, then 2 then 3.4, then 7.8
//for name, the above template will be used
template <typename T, typename... Args>
void func(T t, Args... args)
{
    cout <<"Two Variable temp: " << t << endl;
    func(args...);
}

int main()
{
    string name = "arun";
    func(name);
    func(1, 2, 3.4, 7.8, name);
    return 0;
}