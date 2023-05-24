#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll ans(vector<int>& c, int x, vector<ll>& dp)
{
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];

    ll moves = INT_MAX;

    for(int i: c)
    {
        if(i > x) break;
        moves = min(moves, ans(c, x-i, dp)+1);
    }
    return dp[x] = moves;
}

ll tab(vector<int>& c, int x)
{
    vector<ll> dp(x+1);

    for(int itr = 1; itr <= x; itr++)
    {
        ll moves = INT_MAX;
        for(int i:c)
        {
            if(i > itr) break;
            moves = min(moves, dp[itr-i]+1);
        }
        dp[itr] = moves;
    }

    if(dp[x] == INT_MAX) {
        return -1;
    }
    return dp[x];
}

void solve()
{
    int n,x;
    cin >> n >> x;

    vector<int> coins(n);

    for(int i=0; i<n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());
    // vector<ll> dp(x+1, -1);

    // cout << ans(coins, x, dp) << endl;
    cout << tab(coins, x) << endl;
}

int main()
{
    solve();

    return 0;
}
/*
1≤n≤100
1≤x≤10^6
1≤ci≤10^6
*/