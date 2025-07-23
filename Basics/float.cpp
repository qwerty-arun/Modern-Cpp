// Float data types: float, double, long double

#include<iostream>
using namespace std;

int main()
{
    cout<<"Float: "<<sizeof(float)<<endl;
    cout<<"Float: "<<sizeof(double)<<endl;
    cout<<"Float: "<<sizeof(long double)<<endl;

    float value = 20.2 + 20.2;
    if(value == 40.4)
    {
        puts("You got it right\n");
    }
    printf("My value: %f\n", value); //prints 2.200001
    printf("My value: %1.30f\n", value); 
    cout<<value<<endl; //prints 20.2
    return 0;
}