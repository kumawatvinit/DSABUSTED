#include<iostream>
#include<vector>
#include<map>
#include <numeric>

using namespace std;

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i=0; i<n; i++) cin >> a[i];

        map<int, int> mp;
        long long sum = accumulate(a.begin(), a.end(), 0ll);

        for(int i=0; i<n; i++)
        {
            mp[a[i]]++;
        }

        long long next = mp.rbegin()->first;
        int cnt = n-1-mp[next];

        sum-= next*mp[next];
        // cout << sum << ", " << next << " * " << mp[next] << endl;

        mp[next] = n-1;


        auto x=mp.rbegin();
        for(x++; x!=mp.rend(); x++)
        {
            int copy = x->second;

            if(sum >= next) x->second = mp[next];
            else x->second = cnt;

            next = x->first;
            cnt -= copy;
            sum-= next*copy;

            // cout << sum << ", " << next << " * " << copy << endl;
        }

        // if(sum != 0) {
        //     cout << "\t\tERROR\n\t\t" << sum <<"\n";

        // }
        // else
        // {
            for(int i=0; i<n; i++) cout << mp[a[i]] << " ";
            cout << endl;
        // }
        
    }

    return 0;
}