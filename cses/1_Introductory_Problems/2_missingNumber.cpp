#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;

    ll sum = n*(n+1)/2;
    int x;

    for(int i=0; i<n-1; i++) {
        cin >> x;
        sum-= x;
    }

    cout << sum;

    return 0;
}