#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

vector<vector<int>> fin;

ll rec(vector<ll>& v, int idx, ll sum, vector<int>& t)
{
    if(sum == 0 || idx < 0) {
        fin.push_back(t);
        return abs(sum);
    }

    ll left = rec(v,idx-1,sum, t);
    ll right = sum;

    if(v[idx] <= sum) {
        t.push_back(v[idx]);
        right = rec(v,idx-1,sum-v[idx], t);
        t.pop_back();
    }

    return min(left,right);
}

void print(vector<vector<int>> &ans)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        for(auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "End!\n";
}

void solve(vector<ll>& v)
{
    ll sum = 0;
    for(ll i: v) sum+= i;

    vector<int> t;
    ll ans = rec(v, v.size()-1, sum/2, t);
    ans*= 2;

    if(sum%2) {
        ans+=1;
    }
    cout << ans << endl;

    // print(fin);
}

int main()
{
    int n;
    cin >> n;

    vector<ll> v(n);
    // vector<ll> v{3, 2, 7, 4, 1};

    for(int i=0; i<n; i++) cin >> v[i];   


    solve(v);

    return 0;
}