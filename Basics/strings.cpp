#include <iostream>
#include <string>

using namespace std;

int main()
{
    string my_color;
    cout << "Enter your fav. color: \n";
    getline(cin, my_color); //can take an entire sentence
    // cin >> my_color; //can take only a word
    cout << "Your color is : " << my_color;
    return 0;
}