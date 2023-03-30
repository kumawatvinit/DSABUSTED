#include<iostream>
using namespace std;

int minMerge(int *arr, int n)
{
    int start=0, end=n-1;
    int ans=0;
    
    // for(int i=0; i<n; ++i)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    while(start<end)
    {
        if(arr[start] == arr[end])
        {
            start++;
            end--;
        }
        else if(arr[start] < arr[end]) 
        {
            start++;
            arr[start]+= arr[start-1];
            ans++;
        }
        else
        {
            end--;
            arr[end]+=arr[end+1];
            ans++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << minMerge(arr, n) << endl;
    return 0;
}