#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& permu, int n)
{
    int i=n-2;
    vector<int> arr(permu);

    for(; i>=0; --i)
    {
        if(arr[i] < arr[i+1]) {
            break;
        }
    }

    int idx = i, jdx=i;
    i++;

    for(; i<n; ++i)
    {
        if(arr[i] > arr[idx]) {
            jdx = i;
        } else break;
    }

    swap(arr[idx],arr[jdx]);
    sort(arr.begin()+idx+1, arr.end());
    return arr;

}

int main()
{
    vector<int> permu = {2,3,1,4,5};
    int n = permu.size();
    vector<int> ans = nextPermutation(permu, n);

    for(int i=0; i<n; ++i)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}