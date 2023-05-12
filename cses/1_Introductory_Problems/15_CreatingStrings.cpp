#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"


// slow
// void generate_strings(string str, map<int, int> freq, string current_str, map<string, int>& mp) {
//     if (current_str.length() == str.length()) {
//         mp[current_str]++;
//         return;
//     }
//     for (int i = 0; i < str.size(); i++) {
//         if (freq[str[i]-'a'] > 0) {
//             freq[str[i]-'a']--;
//             generate_strings(str, freq, current_str + str[i], mp);
//             freq[str[i]-'a']++;
//         }
//     }
// }

// void printAns(map<string, int>& mp)
// {
//     int n = mp.size();
//     cout << n << endl;

//     for(auto i: mp)
//     {
//         cout << i.first << endl;
//     }
// }

void print(set<string> &ans)
{
    // cout << "Start: \n";
    cout << ans.size() << endl;

    for(auto &i: ans)
    {
        cout << i << endl;
    }
    // cout << "End!\n";
}

void solve(string &s)
{
    // map<string, int> mp;
    // map<int, int> freq;
    // for(char i: s) freq[i-'a']++;

    // generate_strings(s, freq, "", mp);

    // printAns(mp);

    set<string> ans;
    sort(s.begin(), s.end());
    ans.insert(s);

    while(next_permutation(s.begin(), s.end())) {
        ans.insert(s);
    }

    print(ans);
}

int main()
{
    string s;
    cin >> s;

    // s = "abc";
    // s = "aabac";
    // s = "aaaaaaaa";
    solve(s);

    return 0;
}