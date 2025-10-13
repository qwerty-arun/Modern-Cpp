#include<iostream>
#include<string>
using namespace std;

class Rectangle{
    double _length;
    double _breadth;

public:
    Rectangle(double l=2.0, double b=2.0)
    {
        _length = l;
        _breadth = b;
    }

    double Area()
    {
        return _length * _breadth;
    }

    int compare(Rectangle rectangle)
    {
        return this->Area() > rectangle.Area();
    }
};

int main()
{
    Rectangle rec1(3.0, 3.0);
    Rectangle rec2(4.0, 4.0);

    if(rec1.compare(rec2))
    {
        cout << "Rec2 is smaller";
    }
    else
        cout << "Rec2 is bigger";
    return 0;
}