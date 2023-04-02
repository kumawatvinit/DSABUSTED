#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> mp(n, 0);
        int ans = 0;
        
        for(int i: reward2) {
            ans+= i;
        }

        for(int i=0; i<n; i++) {
            mp[i] = reward1[i] - reward2[i];
        }

        sort(mp.rbegin(), mp.rend());
        for(int i=0; i<k; i++) {
            ans+= mp[i];
        }

        return ans;
    }
};


int main()
{
    Solution obj;
    vector<int> a{1,4,4,6,4};
    vector<int> b{6,5,3,6,1};
    // vector<int> a{2,2,1,2};
    // vector<int> b{1,2,1,2};
    cout << obj.miceAndCheese(a,b,1);

    return 0;
}