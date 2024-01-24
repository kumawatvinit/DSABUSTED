#include <bits/stdc++.h>
using namespace std;

void printMap(map<pair<int, int>, int> &mp)
{
    cout << "map" << endl;
    for (auto x : mp)
    {
        cout << x.first.first << "-" << x.first.second << ": " << x.second << endl;
    }
    cout << endl;
}

void print(map<pair<int, int>, bool> &mp)
{
    cout << "zeroes" << endl;
    for(auto x: mp)
    {
        cout << x.first.first << "-" << x.first.second << endl;
    }
    cout << endl;
}

class Solution {
public:
    int helper(map<pair<int, int>, bool>& zeroes, map<pair<int, int>, int>& mp)
    {
        if (zeroes.empty() || mp.empty()) return 0;
        int mini = INT_MAX;


        print(zeroes);
        printMap(mp);

        pair<int, int> firstZero = zeroes.begin()->first;
        zeroes.erase(firstZero);

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            pair<int, int> key = it->first;
            int value = it->second;

            mp[key] -= 1;
            if (mp[key] == 1) {
                mp.erase(it);
            }
                

            mini = min(mini, abs(key.first - firstZero.first) + abs(key.second - firstZero.second) +
                helper(zeroes, mp));

            if (value == 2) {
                mp[key] = 2; // Restore the original value
            }
            else {
                mp[key] += 1;
            }
        }
        zeroes[firstZero] = true; // Restore the zero position

        cout << "mini: " << mini << endl;
        return mini;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        map<pair<int, int>, int> mp;
        map<pair<int, int>, bool> zeroes; // Map to store positions of '0's

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] > 1) mp[{i, j}] = grid[i][j];
                if (grid[i][j] == 0) zeroes[{i, j}] = true;
            }
        }

        return helper(zeroes, mp);
    }
};


int main()
{
    // vector<vector<int>> grid{{1,1,0},{1,1,1},{1,2,1}};
    // [[1,3,0],[1,0,0],[1,0,3]]
    vector<vector<int>> grid{{1, 3, 0}, {1, 0, 0}, {1, 0, 3}};

    Solution s;
    cout << s.minimumMoves(grid);

    return 0;
}