#include<iostream>
using namespace std;

int main()
{
    char my_string[] = "hello";
    char huh[] = {'h', 'e', 'l', 'l','o', '\0'};
    cout<<my_string<<endl;
    cout<<sizeof(my_string)<<endl;
    cout<<huh<<endl;
    cout<<sizeof(huh)<<endl;

    for(int i{0}; my_string[i]; i++)
        cout<<my_string[i];
    cout<<endl; 
    for(char* cp = huh; *cp != '\0'; cp++)
        cout<<*cp;
    cout<<endl; 

    for(char i: my_string)
        cout<<i<<endl;
    return 0;
}