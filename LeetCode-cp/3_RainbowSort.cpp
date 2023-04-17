#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a;
    int prev = -1;

    for(int i=0; i<n; i++) 
    {
        int neww;
        cin >> neww;

        if(prev == neww) {
            continue;
        }
        else {
            prev = neww;
            a.push_back(neww);
        }
    }

    map<int, int> mp;
    for(int i: a)
    {
        if(mp[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        mp[i]++;
    }

    for(int i: a) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    int i=1; 

    while(t--)
    {
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
    return 0;
}