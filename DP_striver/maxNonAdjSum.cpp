#include<bits/stdc++.h>
using namespace std;

#define endl "\n"




int main()
{
    vector<int> nums{2, 1, 4, 9};
    
    // Tabulation
    int n = nums.size();
    int prev2 = 0, prev = nums[0];

    for(int i=1; i<n; i++)
    {
        int take = nums[i] + prev2;
        int nonTake = prev;

        prev2 = prev;
        prev = max(take, nonTake);
    }

    cout << prev << endl;
    return 0;
}