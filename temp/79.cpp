#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(vector<vector<char>>& board, string &word, int idx, map<pair<int,int>,int>& vis, int i, int j)
    {
        if(idx >= word.size()) return true;
        if(i<0 || j<0) return false;

        int m = board.size(), n = board[0].size();
        bool a = false;

        // i+1, j
        if(((i+1) < m) && (j < n))
        {
            if((word[idx] == board[i+1][j]) && (!vis[{i+1, j}])) {
                vis[{i+1, j}] = 1;
                a = a || helper(board, word, idx+1, vis, i+1, j);

                // reset
                vis[{i+1, j}] = 0;
            }
        }
        if(a) return a;

        // i-1, j
        if(((i-1) >= 0) && ((i-1) < m) && (j < n))
        {
            if((word[idx] == board[i-1][j]) && (!vis[{i-1, j}])) {
                vis[{i-1, j}] = 1;
                a = helper(board, word, idx+1, vis, i-1, j);

                // reset
                vis[{i-1, j}] = 0;
            }
        }
        if(a) return a;

        // i, j+1
        if(i < m && ((j+1) < n))
        {
            if((word[idx] == board[i][j+1]) && (!vis[{i, j+1}])) {
                vis[{i, j+1}] = 1;
                a = helper(board, word, idx+1, vis, i, j+1);

                // reset
                vis[{i, j+1}] = 0;
            }
        }
        if(a) return a;

        // i, j-1
        if(i < m && ((j-1) < n) && (j>=0))
        {
            if((word[idx] == board[i][j-1]) && (!vis[{i, j-1}])) {
                vis[{i, j-1}] = 1;
                a = helper(board, word, idx+1, vis, i, j-1);

                // reset
                vis[{i, j-1}] = 0;
            }
        }

        return a;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int size = word.size();

        // cout << m << n << endl;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // search for first letter of word
                if(board[i][j] == word[0])
                {
                    int itr = 0;

                    // unordered_map<pair<int,int>,int> vis;
                    map<pair<int,int>, int> vis;

                    vis[make_pair(i,j)] = 1;
                    
                    bool ans = helper(board, word, 1, vis, i, j);

                    if(ans) return true;
                }
            }
        }

        return false;
    }
};


int main()
{
    Solution obj;
    // vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board {{'A','A','A','A','A','A','A'},{'A','A','A','A','A','A','A'},{'A','A','A','A','A','A','A'},{'A','A','A','A','A','A','A'},{'A','A','A','A','A','A','B'},{'A','A','A','A','A','B','A'}};
    
    // vector<char> ch{'A','B','C','E'};

    // string word = "ABCCED";
    // string word = "SEE";
    // string word = "ABCB";
    string word = "AAAAAAAAAAAAABB";

    cout << "_" << obj.exist(board, word) << "_";

    return 0;
}