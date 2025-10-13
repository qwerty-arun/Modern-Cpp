#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Corners{
    float a,b,c,d;
};

//overriding
ostream& operator << (ostream& stream, const Corners& corner){
    stream << corner.a << " " << corner.b << " "<< corner.c << " "<<corner.d;
    return stream;
}

int main()
{
    vector<int> integer;
    integer.push_back(2);
    integer.push_back(4);
    integer.push_back(6);
    integer.push_back(8);

    for(auto i = integer.begin(); i!=integer.end(); ++i)
    {
        cout << *i <<endl;
    }

    vector<Corners> corners;
    corners.push_back({1.0, 2.0, 3.0, 4.0});
    corners.push_back({5.0, 6.0, 7.0, 8.0});
    for(int i = 0; i < corners.size(); i++)
    {
        cout << corners[i] << endl;
    }
    return 0;
}