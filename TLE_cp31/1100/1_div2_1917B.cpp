#include<iostream>
#include<unordered_set>

using namespace std;

int solve(string &s, int n)
{
    int ans = 0;
    unordered_set<char> st;

    for(int i=0; i<n; i++) {
        st.insert(s[i]);

        ans+= st.size();
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << solve(s, n) << endl;
    }

    return 0;
}