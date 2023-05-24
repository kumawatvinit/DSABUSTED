#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll a,b;
    cin >> a >> b;

    int left = (2*a-b)/3;
    int right = (2*b-a)/3;
    if(left == right && left  ) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}