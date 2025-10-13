#include<iostream>
using namespace std;

int main()
{
    int rating = 5;
    if(rating == 5)
    {
        cout<<"Your rating is "<<rating<<endl;
    }
    else if(rating == 4)
    {
        cout<<"Your rating is "<<rating<<endl;
    }
    else
    {
        cout<<"Nope"<<endl;
    }
    printf("Your rating is %s\n", rating > 4 ? "true" : "false");
    return 0;
}