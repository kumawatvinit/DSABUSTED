#include<bits/stdc++.h>
using namespace std;

#define ll long long

void print(vector<ll> &ans)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        cout << i << " ";
    }
    cout << "End!\n";
}

int main()
{
    int n, x, p;
    cin >> n >> x;

    vector<ll> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    print(arr);

    for(int i=n-1; i>=0; i--)
    {
        x--;

        if(x == 0)
        {
            if(i>0 && arr[i] == arr[i-1]) {
                p = -1;
            }
            else {
                p = arr[i];
            }
            break;
        }
    }

    cout << p;
}
