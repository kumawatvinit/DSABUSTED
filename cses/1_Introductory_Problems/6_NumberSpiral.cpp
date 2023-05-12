#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve()
{
    ll y,x;
    cin >> y >> x;

    ll row = y%2? (y-1)*(y-1) + 1 : y*y; 
    ll col = x%2? x*x : (x-1)*(x-1) + 1;


    ll ans = 0;

    if(row < col)
    {
        if(col%2) {
            ans = col-y+1;
        }
        else {
            ans = col+y-1;
        }
    } 
    else 
    {
        if(row%2) {
            ans = row+x-1;
        }
        else {
            ans = row-x+1;
        }
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin>>t;

    // int t = 1;

    while(t--) {
        solve();
    }

    return 0;
}