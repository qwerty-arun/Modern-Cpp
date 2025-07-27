// Try Catch block

#include<iostream>
using namespace std;
int main()
{
    char call_api{'h'};
    try{
        cout<<"Trying to use API values\n";
        cout<<"Did some testing with API value\n";
        throw call_api; //this is always execute, make sure you do some tests and only then, throw
        cout<<"Wont execute\n";
    }catch(int x){
        cout<<"Integer exception handled\n";
    } catch(float y){ //We can have as many catches as we want
        cout<<"Float exception handled\n";
    }
    // What if we can't predict the type of error?
    catch(...)
    {
        cout<<"Something went wrong\n";
    }
    cout<<"Keep moving with rest of code\n";
    return 0;
}