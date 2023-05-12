#include<bits/stdc++.h>
using namespace std;


// memoization
int solve(int n, vector<int> &dp)
{
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}


int main()
{
    int n;
    cin>>n;

    // vector<int> dp(n+1, -1);
    // cout << solve(n, dp);

    int prev2 = 0, prev = 1;
    int curr = 0;

    for(int i=2; i<=n; i++)
    {
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }

    cout << curr;

    return 0;
}