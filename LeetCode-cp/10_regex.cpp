#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(string &s, int sdx, string &p, int pdx, vector<vector<int>>& dp)
    {
        if(dp[sdx][pdx] != 0) return dp[sdx][pdx] == 1;

        int pSize = p.size(), sSize = s.size();
        bool ans = 0;

        if(pSize == pdx) ans = sSize == sdx;
        else {
        bool currIdx = (sdx < sSize) && ((s[sdx] == p[pdx])||(p[pdx] == '.'));

        // * (wild card)
        if(pdx+1 < pSize && p[pdx+1] == '*')
        {
            // either don't consider "_*" both chars
            // OR 
            // considerr, means, pattern will be same for next call also
            /*
            s: aaavewe
            p: a*erge*.g*4*
            */
            ans = helper(s, sdx, p, pdx+2, dp) ||
             (currIdx && helper(s, sdx+1, p, pdx, dp));
        }
        else
        ans = currIdx && helper(s, sdx+1, p, pdx+1, dp);
        }
        // Either the last char, OR 
        // no '*' applicable on currIdx

        dp[sdx][pdx] = ans ? 1: -1;
        return ans;
    }
public:
    bool isMatch(string s, string p) 
    {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
        return helper(s,0, p, 0, dp);
    }
};


int main()
{
    Solution obj;

    cout << obj.isMatch("aa","a*");

    return 0;
}