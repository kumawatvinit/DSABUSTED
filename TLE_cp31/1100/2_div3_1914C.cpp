#include<iostream>
#include<vector>

using namespace std;

// int solve(vector<int>& a, vector<int>& b, int n, int k, int idx, vector<vector<int>>& dp)
// {
//     if(k == 0 || idx == n) return 0;

//     if(dp[idx][k] != -1) return dp[idx][k];

//     int ans = 0;

//     for(int x=0; x<k; x++) {
//         ans = max(ans, a[idx] + b[idx]*x + solve(a, b, n, k-x-1, idx+1, dp));
//     }

//     return dp[idx][k] = ans;
// }

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);

        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        // vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

        // cout << solve(a,b, n, k, 0, dp) << endl;

        int maxi = 0, ans = 0, curr = 0;

        for(int i=0; i<min(n, k); i++)
        {
            curr+= a[i];
            maxi = max(maxi, b[i]);

            ans = max(ans, curr+(k-i-1)*maxi);
        }

        cout << ans << endl;
    }
}