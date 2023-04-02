#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> mp;
        
        for(int &i: nums) mp[i]++;
        
        while(mp.size() > 0)
        {
            vector<int> temp;
            for(auto &i: mp)
            {
                temp.push_back(i.first);
                
                mp[i.first]--;
            }

            auto it = mp.begin();
            while(it != mp.end())
            {
                if(it->second == 0)
                {
                    it = mp.erase(it);
                }
                else {
                    it++;
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};

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

int main()
{
    Solution obj;
    vector<int> v{1,3,4,1,2,3,1};

    vector<vector<int>> ans = obj.findMatrix(v);
    print(ans);

    return 0;
}