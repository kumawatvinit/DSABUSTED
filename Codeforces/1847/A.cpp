#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& nums, int idx, int k, vector<vector<int>>& dp)
{
    if(k == 0) {
        int ans = 0;
        while(idx+1 < nums.size()) {
            ans += abs(nums[idx+1]-nums[idx]);
            idx++;
        }
        return ans;
    }

    if(idx >= nums.size()) {
        if(k > 0) return INT_MAX;
        return 0;
    }

    if(dp[idx][k] != -1) return dp[idx][k];

    int ans = INT_MAX;
    int sum = 0;

    for(int i=idx; i<nums.size(); i++)
    {
        if(nums.size()-i-1 < k-1) break;

        // cout << "i: " << i << " , k: " << k << "sum: " << sum << endl;
        int temp = sum+solve(nums, i+1, k-1, dp);
        // cout << "temp: " << temp << endl;


        ans = min(ans, temp);

        // cout << "Another...\n";

        sum+= (i+1<nums.size())? abs(nums[i+1]-nums[i]): 0;
    }

    // cout << "-------------------\n";
    // cout << "idx: " << idx << " , k: " << k << endl;
    // cout << ans << endl;
    // cout << "-------------------\n";

    return dp[idx][k] = ans;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,k;
        cin >> n >> k;

        vector<int> nums(n);

        for(int i=0;i<n;i++)
            cin >> nums[i];

        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        cout << solve(nums, 0, k-1, dp) << "\n";
    }
    

    return 0;
}