#include<bits/stdc++.h>
using namespace std;


void generate(string &str, int a[])
{
    for(int i=0; i<str.size(); i++) {
        str[i] = char('0' + a[str[i]]-'A');
    }
}

int main()
{
    int t;
    cin >> t;

    int a[26] = {0};
    int num = 0;

    while(t--)
    {
        int n;

        for(int i=0; i<26; i++) cin >> a[i];

        cin >> n;

        unordered_map<string, int> mp;
        int flag = 0;

        for(int i=0; i<n; i++) {
            string str;
            cin >> str;
            generate(str, a);

            mp[str]++;

            if(mp[str] > 1) {
                flag = 1;
            }
        }

        cout << "Case #" << num << ": " << (flag? "YES\n": "NO\n"); 
        num++;


    }

    return 0;
}