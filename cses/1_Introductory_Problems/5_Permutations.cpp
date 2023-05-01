#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int n)
{
    if(n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return;
    }

    int i = 2;
    for(; i<=n; i+=2) {
        cout << i << " ";
    }

    i = 1;
    for(; i<=n; i+=2) {
        cout << i << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    

    solve(n);

    return 0;
}