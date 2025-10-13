#include <iostream>

using namespace std;

int main()
{
    int rating = 5;
    switch (rating)
    {
    case 1:
        cout << "Very Bad" << endl;
        break; //without this, fall through happens

    case 2:
        cout << "Bad" << endl;
        break;

    case 3:
        cout << "OK" << endl;
        break;

    case 4:
        cout << "Good" << endl;
        break;

    case 5:
        cout << "Very Good" << endl;
        break;

    default:
        cout << "Invalid" << endl;
        break;
    }
}