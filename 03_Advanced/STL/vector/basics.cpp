#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    vector<int> nums;
    vector<string> heros {"batman", "flash", "superman", "robin"};
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(9);

    for(auto element: nums)
        cout<<element<<endl;

    cout<<"Size: "<<nums.size()<< "\nCapacity: "<<nums.capacity()<<"\nMax Size: "<<nums.max_size()<<endl;

    for(auto i= nums.begin(); i!=nums.end(); i++) //begin(nums) or end(nums) also works
        cout<<*i<<" ";

    return 0;
}