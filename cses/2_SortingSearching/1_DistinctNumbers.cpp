#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(vector<ll>& v, ll n)
{
    sort(v.begin(), v.end());
    ll ans = 1;

    for(int i=1; i<n; i++)
    {
        ans+= v[i] != v[i-1];
    }

    return ans;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);

    for(auto i = 0; i<n; i++) {
        cin >> v[i];
    }

    cout << solve(v, n);

    return 0;
}