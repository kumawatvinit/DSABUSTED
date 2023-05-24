#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> customer(n);
    vector<ll> apartments(m);

    for(int i=0; i<n; i++) cin >> customer[i];
    for(int i=0; i<m; i++) cin >> apartments[i];

    sort(customer.begin(), customer.end());
    sort(apartments.begin(), apartments.end());

    int j=0, ans = 0;
    for(int i=0; i<m && j<n; )
    {
        if(apartments[i] <= customer[j]+k && apartments[i] >= customer[j]-k) {
            ans++;
            j++;
            i++;
        }
        else if(customer[j]-k > apartments[i]) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << ans;

    return 0;
}