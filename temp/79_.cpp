#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, -1, 0, 1};
    int m, n;
    bool check(int i, int j)
    {
        if(i>=0 && i<m && j>=0 && j<n) return true;
        return false;
    }

    bool helper(vector<vector<char>>& board, string &word, int idx, map<pair<int,int>,int>& vis, int i, int j)
    {
        if(idx >= word.size()) return true;
        bool a = false;

        for(int itr=0; itr<4; itr++)
        {
            int x = i + dx[itr];
            int y = j + dy[itr];

            if(check(x,y) && (word[idx] == board[x][y]) && (!vis[{x, y}]))
            {
                vis[{x,y}] = 1;
                a = helper(board,word,idx+1,vis,x,y);
                vis[{x,y}] = 0;
            }

            if(a) return true;
        }
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        int size = word.size();


        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == word[0])
                {
                    map<pair<int,int>, int> vis;
                    vis[make_pair(i,j)] = 1;
                    
                    bool ans = helper(board, word, 1, vis, i, j);
                    vis[make_pair(i,j)] = 0;

                    if(ans) return true;
                }
            }
        }

        return false;
    }
};
*/

class Solution {
    int m, n;
    bool check(int &i, int &j)
    {
        if(i>=0 && i<m && j>=0 && j<n) return true;
        return false;
    }

    bool dfs(vector<vector<char>> &b, string &w, int idx,int i, int j)
    {
        if(idx >= w.size()) return true;
        if(check(i,j) == false) return false;
        if(b[i][j] != w[idx]) return false;

        char ch = b[i][j];
        b[i][j] = '*';

        bool a = dfs(b,w,idx+1,i-1,j)||dfs(b,w,idx+1,i+1,j)||dfs(b,w,idx+1,i,j-1)||dfs(b,w,idx+1,i,j+1);

        // reset
        b[i][j] = ch;
        
        return a;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();


        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == word[0])
                {
                    char ch = board[i][j];
                    board[i][j] = '*';
                    if(dfs(board, word, 1, i, j)) {
                        board[i][j] = ch;
                        return true;
                    }
                    board[i][j] = ch;
                }

        return false;
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // vector<vector<char>> board {{'A','A','A','A','A','A','A'},{'A','A','A','A','A','A','A'},{'A','A','A','A','A','A','A'},{'A','A','A','A','A','A','A'},{'A','A','A','A','A','A','B'},{'A','A','A','A','A','B','A'}};
    
    // vector<char> ch{'A','B','C','E'};

    string word = "ABCCED";
    // string word = "SEE";
    // string word = "ABCB";
    // string word = "AAAAAAAAAAAAABB";

    cout << "_" << obj.exist(board, word) << "_";

    return 0;
}