#include<bits/stdc++.h>
using namespace std;


#define ll long long

class Solution {
    public:
    bool compare(string& a, string b, int i)
    {
        if(i+a.size() <= b.size())
        {
            return a == b.substr(i,a.size());
        }
        return false;
    }
    ll mem(string& s, vector<string>& dictionary, int idx)
    {
        if(idx >= s.size()) return 0;
        
        ll mini = 1+mem(s,dictionary,idx+1);

        for(auto &i: dictionary)
        {
            ll chars = INT_MAX;
            if(compare(i,s, idx)) {
                // cout << i << " " << idx << "\n";
                chars = mem(s,dictionary,idx+i.size());
                mini = min(mini, chars);
            }
        }
        
        return mini;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        return (int) mem(s,dictionary,0);
    }
};

int main()
{
    Solution obj;
    // vector<string> dictionary = {"leet","code","leetcode"};
    // string s = "leetscode";
    vector<string> dictionary = {"hello","world"};
    string s = "sayhelloworld";

    // for(auto i: dictionary)
    // {
    //     cout << obj.compare(i,s,3) << "\n";
    // }

    cout << obj.minExtraChar(s,dictionary);

    return 0;
}