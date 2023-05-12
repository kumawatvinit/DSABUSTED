#include<bits/stdc++.h>
using namespace std;

#define ll long long

void printMap(map<int, int> &mp)
{
    cout << "Start...\n";

    for(auto &i: mp) {
        cout << i.first << " ";
        cout << ": " << i.second << "\n";
    }
    cout << "End!\n";
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<1) return 0;

        int cnt = 1; 
        int maxi = INT_MIN;

        map<int,int> mp;

        for(auto &i: nums)
        {
            mp[i] = 1;
        }

        printMap(mp);
        
        map<int,int>::iterator itr = mp.begin();
        ll prev = itr->first;
        itr++;

        for( ; itr != mp.end(); itr++)
        {
            if(prev+1ll == itr->first) {
                cnt++;
            }
            else {
                maxi = max(maxi, cnt);
                cnt = 1;
            }

            prev = itr->first;
        }        
        maxi = max(maxi, cnt);

        return maxi;
    }
};

int main()
{
    vector<int> nums{100,4,200,1,3,2};

    Solution obj;
    cout << obj.longestConsecutive(nums);

    return 0;
}