#include<bits/stdc++.h>
using namespace std;

#define ll long long

int solve(string &s)
{
    int n = s.size();
    int maxi = 1;
    int cnt = 1;

    for(int i=1; i<n; i++)
    {
        if(s[i] == s[i-1]) {
            cnt++;
        }
        else {
            maxi = max(maxi, cnt);
            cnt = 1;
        }
    }

    return max(maxi, cnt);
}

int main()
{
    string s;

    cin >> s;

    cout << solve(s);    

    return 0;
}