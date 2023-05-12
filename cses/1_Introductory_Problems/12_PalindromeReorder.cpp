#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve(string& s)
{
    vector<int> mp(26);

    for(char i: s) mp[i-'A']++;

    int odds = 0;
    for(int i: mp) {
        if(i%2) odds++;
    }
    if(odds > 1) {
        cout << "NO SOLUTION";
        return;
    }


    string ans = "";
    string mid = "";

    for(int i=0; i<26; i++)
    {
        if(mp[i]%2 == 0)
        {
            int t = mp[i]/2;
            while(t--) ans+= char('A' + i);
        }
        else 
        {
            mid = char('A' + i);
            int t = mp[i]/2;
            while(t--) ans+= char('A' + i);
        }
    }

    string temp = string(ans.rbegin(), ans.rend());
    ans+= mid + temp;
    cout << ans;
}

int main()
{
    string s;
    cin >> s;

    solve(s);

    return 0;
}