#include<bits/stdc++.h>
using namespace std;

int memR(vector<int>& num, int idx, int target, vector<vector<int>>& dp)
{
    // if(target == 0) return 1;
    if(idx == 0)
    {
        if(num[0] == 0 && target == 0) return 2;
        if(target == 0) return 1;
        return num[0] == target;
    }

    if(dp[idx][target] != -1) return dp[idx][target];

    int left = memR(num, idx-1, target, dp);
    int right = 0;

    if(num[idx] <= target) {
        right = memR(num, idx-1, target-num[idx], dp);
    }

    return dp[idx][target] = left+right;
}

int mem(vector<int>& arr, int idx, int sum, vector<vector<int>>& dp)
{
    if(idx == 0) 
    {
        if(arr[0] == 0 && sum == 0) return 2;
        if(sum == 0) return 1;
        return arr[0] == sum;
    }

    if(dp[idx][sum] != -1) return dp[idx][sum];

    int left = mem(arr, idx-1, sum, dp);
    int right = 0;

    if(arr[idx] <= sum) {
        right = mem(arr, idx-1, sum-arr[idx], dp);
    }

    return dp[idx][sum] = (left+right);
}

int spaceOptimization(vector<int>& num, int n, int target)
{
    vector<int> prev(target+1), curr(target+1);
    curr[0] = prev[0] = 1;
    if(num[0] <= target) prev[num[0]] = 1;
    if(num[0] == 0) curr[0] = prev[0] = 2;

    for(int i=1; i< n; i++)
    {
        for(int j=0; j<= target; j++)
        {
            int left = prev[j];
            int right = 0;

            if(num[i] <= j) {
                right = prev[j-num[i]];
            }

            curr[j] = left + right;
        }
        prev = curr;
    }

    cout << "Start\n";
    for(int i: prev) {
        cout << i << " ";
    }
    cout << "Done\n";

    return prev[target];
}

void print(vector<vector<int>> &ans)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        for(auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "End!\n";
}

int countPartitions(int n, int d, vector<int> &arr, int sum, vector<vector<int>>& dp)
{
    // int sum = 0;
    // for(int i: arr) sum+= i;

    // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    // return memR(arr, n-1, sum, dp);
    return spaceOptimization(arr,n,sum);

    // print(dp, n);

    // return 0;

}

int main()
{
    // vector<int> arr{1, 2, 2, 3};
    vector<int> arr{5, 2, 6, 0};
    // vector<int> arr{1,1,1,1};

    int sum = 0;
    for(int i: arr) sum+= i;

    vector<vector<int>> dp(4, vector<int>(sum+1, -1));

    cout << countPartitions(4,3,arr, sum, dp) << endl;

    // print(dp);

    return 0;
}