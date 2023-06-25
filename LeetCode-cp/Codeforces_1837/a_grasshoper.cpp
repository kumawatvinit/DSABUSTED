#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x, k;
    cin >> x >> k;

    int i = 0;
    vector<int> ans;

    while(i != x)
    {
        int step = x-i;

        while(step%k == 0) {
            step--;
        }
        ans.push_back(step);

        i+= step;
    }

    cout << ans.size() << "\n";

    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}