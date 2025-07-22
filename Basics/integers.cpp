// Integers:
/*
short int
int 
long 
long int int
*/

#include<iostream>
#include<cstdint>
using namespace std;
int main()
{
    cout<<sizeof(short int)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(long int)<<endl;
    cout<<sizeof(long)<<endl;
    cout<<sizeof(long long int)<<endl;
    cout<<endl;
    cout<<sizeof(int8_t)<<endl; //no matter what system you use, it always uses 8 bits
    cout<<sizeof(int16_t)<<endl;
    cout<<sizeof(int32_t)<<endl;
    cout<<sizeof(int64_t)<<endl;
    cout<<endl;
    cout<<sizeof(uint8_t)<<endl;
    cout<<sizeof(uint16_t)<<endl;
    cout<<sizeof(uint32_t)<<endl;
    cout<<sizeof(uint64_t)<<endl;

    // More fun
    int hex = 0x16;
    int bin = 0b1111;
    cout<<hex<<endl;
    cout<<bin<<endl;
    return 0;
}