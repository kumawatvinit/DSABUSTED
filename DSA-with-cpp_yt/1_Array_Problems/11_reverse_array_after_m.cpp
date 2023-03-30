#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>&arr, int m)
{
    int s = m+1, e = arr.size()-1;

    while(s<e)
    {
        swap(arr[s++],arr[e--]);
    }
}

void print(vector<int> arr)
{
    for(auto i:arr) cout<<i<<" "; cout<<endl;
}

int main()
{
    vector<int> arr = {10, 4, 5, 2, 3, 6, 1, 3, 6};

    int m = 3;
    
    print(arr);
    reverse(arr,m);
    print(arr);

    return 0;
}