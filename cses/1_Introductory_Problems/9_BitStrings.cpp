#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

ll power(ll x)
{
    ll mod = 1e9+7;
    if(x == 1) return 2;

    if(x%2) 
    {
        ll ans = power((x-1)/2)%mod;
        return (2*ans%mod*ans)%mod;
    } 
    ll ans = power(x/2)%mod;
    return (ans*ans%mod);
}

void solve()
{
    int n;
    cin >> n;

    cout << power(n);
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