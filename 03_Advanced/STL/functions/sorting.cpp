#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int numbers[] = {3, 5, 6, 8, 1};
    cout << "Unsorted values: "<<endl;
    for(int n:numbers)
        cout<<n<<" "<<endl;
    
    sort(numbers, numbers+5);
    cout << "Sorted values: "<<endl;
    for(int n:numbers)
        cout<<n<<" "<<endl;

    sort_heap(numbers, numbers+5);
    cout << "Sorted values: "<<endl;
    for(int n:numbers)
        cout<<n<<" "<<endl;
    return 0;
}