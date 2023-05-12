#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void tower(int n, int src, int dest, int by, int & count, vector<pair<int,int>>& ans)
{
    if(n == 1) {
        count++;
        ans.push_back({src,dest});
        return;
    }

    tower(n-1, src, by, dest, count, ans);
    ans.push_back({src,dest});
    count++;
    tower(n-1, by, dest, src, count, ans);
}

void printAns(vector<pair<int,int>>& ans, int count)
{
    cout << count << "\n";

    for(auto i: ans) {
        cout << i.first << " " << i.second << "\n";
    }
}

void solve(int n)
{
    int count = 0;
    vector<pair<int,int>> ans;

    tower(n,1,3, 2, count, ans);

    printAns(ans, count);
}

int main()
{
    int n;
    cin >> n;

    solve(n);

    return 0;
}