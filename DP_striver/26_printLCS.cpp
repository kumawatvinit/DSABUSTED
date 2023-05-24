#include<bits/stdc++.h>
using namespace std;

int mem(string& s, string& t, int idx1, int idx2, vector<vector<int>>& dp)
{
	if(idx1<0 || idx2<0) return 0;

	if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

	if(s[idx1] == t[idx2]) return 1+mem(s,t,idx1-1, idx2-1, dp);

	int left = mem(s,t,idx1-1,idx2,dp);
	int right = mem(s,t,idx1, idx2-1, dp);
	return dp[idx1][idx2] = max(left, right);
}

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

int tabulation(string& s, string& t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m, vector<int>(n));

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(s[i] == t[j])
			{
				int extra = (i>0 && j>0)? dp[i-1][j-1]: 0;
				dp[i][j] = 1 + extra;
			}
			else 
			{
				int left = (i>0)? dp[i-1][j]: 0;
				int right = (j>0)? dp[i][j-1]: 0;

				dp[i][j] = max(left, right);
			}
		}
	}

    // print(dp);

	int len = dp[m-1][n-1];
	int i = m-1, j=n-1;
	int idx = len-1;
	string ans;
	ans.append(len, '$');

	while(i>=0 && j>=0)
	{
		if(s[i] == t[j]) {
			ans[idx--] = s[i];
			i--; j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}
    cout << "Longest common string : \n";
	cout << ans << endl;

	return dp[m-1][n-1];
}

int spaceOptimization(string& s, string& t)
{
	int m = s.size(), n = t.size();
	vector<int> prev(n), curr(n);

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(s[i] == t[j])
			{
				int extra = (i>0 && j>0)? prev[j-1]: 0;
				curr[j] = 1 + extra;
			}
			else 
			{
				int left = (i>0)? prev[j]: 0;
				int right = (j>0)? curr[j-1]: 0;

				curr[j] = max(left, right);
			}
		}
		prev = curr;
	}

	return prev[n-1];
}

int lcs(string s, string t)
{
	// vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
	// return mem(s,t,s.size()-1, t.size()-1, dp);

	return tabulation(s,t);
	// return spaceOptimization(s,t);
}

int main()
{
    // string s, t;
    // cin >> s >> t;

    // cout << lcs("ab", "defg") << endl;
    // cout << lcs("adebc", "dcadb") << endl;
    // cout << lcs("def", "fed") << endl;
    cout << lcs("abcdb", "bcacdhb") << endl;
    

    return 0;
}