// Loops

# include <iostream>
using namespace std;

int main()
{
    int numbers[]{1,2,3,4,5};
    int i{0};
    while(i<4)
    {
        if(i==3)
        {
            cout<<"Great!"<<endl;
            break;
        }
        cout<<"Current number is: "<<numbers[i] <<endl;
        i++;
    }
    for(int i{0}; i<5; i++)
        cout<<numbers[i]<<endl;
    cout<<"Whatever"<<endl;

    for(int i: numbers) //for each loop
        cout<<i<<endl;

    return 0;
}