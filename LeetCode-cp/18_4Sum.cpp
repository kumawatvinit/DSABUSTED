#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &t)
{
    cout << "vec: ";
    for(auto &i: t) {
        cout << i << " ";
    }

    cout << endl;
}

/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        cout << "New nums : ";
        print(nums);

        map<vector<int>, int> mp;
    
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    for(int l=k+1; l<n; l++)
                    {
                        // if(i<j && j<k && k<l)
                        if((nums[i] + nums[j] + nums[k] +nums[l]) == target) {
                            vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            temp.push_back(nums[l]);

                            cout << i << " " << j << " " << k << " " << l << endl;
                            print(temp);

                            mp[temp]++;
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(auto &i: mp)
        {
            ans.push_back(i.first);
        }

        return ans;
    }
};
*/

class Solution {
    
public: 
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 4, 0);
    }

    vector<vector<int>> kSum(vector<int> &nums, long long target, int k, int i)
    {
        vector<vector<int>> ans;

        if(i == nums.size()) {
            return ans;
        }

        long long avg = target/k;

        if(nums[i] > avg || nums.back() < avg) {
            return ans;
        }

        if(k == 2) {
            return TwoSum(nums, target, i);
        }

        int n = nums.size();
        for(int j=i; j<n; j++)
        {
            if(j == i || nums[j-1] != nums[j])
            {
                for(auto &subset: kSum(nums, 0ll + target-nums[j], k-1, j+1))
                {
                    ans.push_back({nums[j]});
                    ans.back().insert(end(ans.back()), begin(subset), end(subset));
                }
            }
        }

        return ans;
    }

    vector<vector<int>> TwoSum(vector<int> &nums, long long target, int i)
    {
        vector<vector<int>> ans;
        unordered_map<long long, int> mp;
        int n = nums.size();

        for(int j = i; j<n; j++) 
        {
            if(ans.empty() || ans.back()[1] != nums[j]) 
            {
                if(mp.find(target-nums[j]) != mp.end()) {
                    ans.push_back({int(target-nums[j]), nums[j]});
                }
            }
            mp[nums[j]]++;
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

    vector<int> nums{1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> ans = obj.fourSum(nums, target);
    print(ans);

    return 0;
}