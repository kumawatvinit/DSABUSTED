#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 2, cnt1=1, cnt2=0;

    int i=1;

    while(i<n)
    {
        if(s[i] != s[i-1])
        {   
            cnt1 = cnt2;
            
        }
        else 
        {
            cnt1++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}