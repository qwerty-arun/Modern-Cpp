#include<iostream>
#include<cstdint>
using namespace std;

#define PI 3.141592 

enum MsOffice: uint8_t{
    BOLD = 7,
    ITALIC = 9,
    UNDERLINE = 11,
    CROSSED,
};

int main()
{
    int myAttr = CROSSED; 
    cout << myAttr<<endl;
    return 0;
}