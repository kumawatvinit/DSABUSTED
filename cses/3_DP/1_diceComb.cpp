#include<bits/stdc++.h>
using namespace std;

#define ll long long

int mod = 1e9+7;

ll count(int n, vector<ll>& dp)
{
    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    ll sum = 0;
    for(int i=1; i<=n && i<=6; ++i)
    {
        sum = (sum + count(n-i, dp))%mod;
    }

    return dp[n] = sum;
}


ll tab(int n)
{
    vector<ll> dp(n+1);
    dp[0] = 1;

    for(int itr=1; itr<=n; itr++)
    {
        ll sum = 0;
        for(int i=1; i<=itr && i<=6; ++i) 
        {
            ll left = dp[itr-i];
            sum = (sum + left)%mod;
        }
        dp[itr] = sum;
    }
    return dp[n];
}

void solve(int n)
{
    // vector<ll> dp(n+1, -1);
    // cout << count(n, dp);

    cout << tab(n) << endl;
}

int main()
{
    int n;
    cin >> n; 

    solve(n);

    return 0;
}