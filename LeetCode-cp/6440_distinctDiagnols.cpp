#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void printMap(unordered_map<int, int> &mp)
    {
        cout << "Start...\n";
    
        for(auto &i: mp) {
            cout << i.first << " ";
            cout << ": " << i.second << "\n";
        }
        cout << "End!\n";
    }
    
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n)
    {
        // cout << i << " " << j << endl;

        // topleft
        int idx = i-1, jdx=j-1;
        unordered_map<int,int> hash1;
        while(idx>=0 && jdx>=0)
        {
            hash1[grid[idx--][jdx--]]++;
        }
        
        // bottomright
        unordered_map<int,int> hash2;
        i++; j++;
        while(i<m && j<n)
        {
            hash2[grid[i++][j++]]++;
        }
        
        
        // printMap(hash1);
        // printMap(hash2);

        cout << endl;

        return hash1.size()-hash2.size();
    }
    
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for(int i=0; i<m; i+=1)
        {
            for(int j=0; j<n; j+=1)
            {
                int t = solve(grid, i, j, m, n);
                ans[i][j] = abs(t);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{1,2,3},{3,1,5},{3,2,1}};
    Solution s;
    vector<vector<int>> ans = s.differenceOfDistinctValues(grid);
    for(auto &i: ans)
    {
        for(auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }



    return 0;
}