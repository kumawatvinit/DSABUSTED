#include<bits/stdc++.h>
using namespace std;

int fn(string a)
{
    string s = "FBFFBFFBFBFFBFFB";

    if(s.find(a) != string::npos) {
        return 1;
    }
    return 0;
}

int main()
{

    int t;
    cin >> t;

    while(t--)
    {
        int k;
        cin >> k;
        string a;
        cin >> a;

        if(fn(a)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}