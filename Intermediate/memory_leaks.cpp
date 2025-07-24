#include<iostream>
using namespace std;

// int main()
// {
//     int* ptr;
//     ptr = new int[10]; //allocate 10 bytes
//     cout <<"Memory space allocated"<<endl;
//     delete [] ptr; //to delete entire block of memory, else it is delete ptr
//     cout <<"Memory space deallocated"<<endl;
//     return 0;
// }

int main()
{
    int *myp;
    try{
        myp = new int[10];
        cout<<"Memory space allocated\n";
    }catch(...){
        cout<<"Failed in allocating memory\n";
    }
    delete [] myp;
    return 0;
}