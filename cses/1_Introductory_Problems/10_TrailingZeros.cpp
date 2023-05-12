#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve()
{
    ll n;
    cin >> n;
    
    ll ans = 0;

    while(n > 4) {
        ans+= n/5;
        n/= 5;
    }

    cout << ans;
}

int main()
{
    // int t;
    // cin>>t;

    int t = 1;

    while(t--) {
        solve();
    }

    return 0;
}