#include<bits/stdc++.h>
using namespace std;

int *getProductArrayExceptSelf(int *arr, int n)
{
    long long mul = 1;
    int cnt = 0;

    for(int i=0; i<n; ++i)
    {
        if(arr[i] == 0) cnt++;
        else mul*= arr[i];
    }

    if(cnt == 0) {
        for(int i=0; i<n; ++i)
            arr[i] = mul/arr[i];
    }
    else if(cnt == 1) {
        for(int i=0; i<n; ++i)
        {
            if(arr[i] == 0) {
                arr[i] = mul;
            } else arr[i] = 0;
        }
    }
    else if(cnt > 1) {
        for(int i=0; i<n; ++i) arr[i] = 0;
    }

    return arr;
}

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i=0; i<n; ++i) cin>>arr[i];

    arr = getProductArrayExceptSelf(arr, n);

    for(int i=0; i<n; ++i) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}