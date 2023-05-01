#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(int n)
{
    vector<ll> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    for(int i=1; i<n; i++)
    {
        if(arr[i] < arr[i-1]) 
        {
            int diff = arr[i-1]-arr[i];
            ans+= diff;

            arr[i]+= diff;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    

    cout << solve(n);    

    return 0;
}