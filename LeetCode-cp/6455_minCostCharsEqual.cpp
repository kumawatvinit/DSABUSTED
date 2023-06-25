#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll start(string& s, int i, int one)
    {
        if(i<0) return 0;

        if(one) {
            if(s[i]=='1')
            return i+1+ start(s, i-1, 0);
            return start(s, i-1, one);
        }
        else
        {
            if(s[i]=='0')
            return i+1+ start(s, i-1, 1);
            return start(s, i-1, one);
        }
    }

    ll end(string& s, int i, int one)
    {
        if(i>=s.size()) return 0;

        if(one) {
            if(s[i]=='1')
            return s.size()-i+ end(s, i+1, 0);
            return end(s, i+1, one);
        }
        else
        {
            if(s[i]=='0')
            return s.size()-i+ end(s, i+1, 1);
            return end(s, i+1, one);
        }
    }
    long long minimumCost(string s) {
        ll mini = start(s,-1,0)+end(s, 0, 0);

        for(int i=0; i<s.size(); i+=1) {
            ll t = start(s, i, 0) + end(s, i+1, 0);
            mini = min(mini, t);
        }
        return mini;
    }
};

int main()
{
    string s = "010101";
    Solution obj;
    cout << obj.minimumCost(s) << endl;

    return 0;
}