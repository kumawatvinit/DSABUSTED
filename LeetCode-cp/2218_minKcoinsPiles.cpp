#include<bits/stdc++.h>
using namespace std;

class Solution {
    int maxi = 0;
    
    void print(vector<int> &n)
    {
        for(int &i: n)
        cout << i << " ";

        cout << endl;
    }
    void helper(vector<vector<int>>& piles, int k, vector<int> &sum, vector<int> &t)
    {
        if(k <= 0) {
            int s = 0;
            for(auto i: sum) {
                s+= i;
            }

            if(s > maxi) {
                maxi = s;
                print(sum);
            }
        }

        for(int i=0; i<piles.size(); i++)
        {
            int idx = t[i];
            
            if(idx >= piles[i].size()) {
                // nthng
            }
            else 
            {
                t[i]++;
                
                int curr = piles[i][idx];
                sum.push_back(curr);
                helper(piles, k-1, sum, t);

                sum.pop_back();

                t[i]--;
            }
            
        }
        
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> t(piles.size(), 0);
        vector<int> sum;

        helper(piles, k, sum, t);

        return maxi;
    }
};


int main()
{
    Solution obj;

    vector<vector<int>> piles = {{1,100,3},{7,8,9}};
    int k = 2;

    cout << obj.maxValueOfCoins(piles, k);

    return 0;
}