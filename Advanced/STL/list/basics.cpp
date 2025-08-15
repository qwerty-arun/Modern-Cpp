#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
    list<int> mylist;
    for(int i = 3; i<=10; ++i)
        mylist.push_back(i);

    cout<<mylist.front()<<endl;
    cout<<mylist.back()<<endl;
    mylist.pop_back();
    cout<<mylist.back()<<endl;
    mylist.pop_front();
    cout<<mylist.front()<<endl;
    mylist.reverse();
    for(auto i:mylist)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}