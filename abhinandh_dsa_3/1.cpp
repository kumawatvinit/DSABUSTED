// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long int
// int max_len = 0;

/*
n=4, m=2
s = "abcd"
str = ["cba", "ba"]

we take "cba" from the string array str so it is matched with the first three letters from S
Hence, "abc" is beautiful string

Note, we could take the string "ba" but will give us only two letters from the prefix of string S.

So, the longest prefix length from S that can be divided into beautiful substrings is 3.



e.g. 2
n=5, m=3
s="abcda"
str = ["a", "b", "dc"]

we divide S into following beautiful substrings -> "a", "b", "cd", "a"
all of these above substrings after reversing them are present in the string array str.
Hence, we are able to divide the string S into beautiful substrings.
so, the longest prefix length from S that can be divided into beautiful substrings is 5.


e.g. 3
n=4, m=1
s="badc"
str=["ab"]
answer = 2
Since, we take "ab" from the string array str so it is matched with the first two letters from S
but further we cannot divide the string S into beautiful substrings.
like "d", "c" OR "dc" any of them are not present in the string array str.
So, the longest prefix length from S that can be divided into beautiful substrings is 2.

// Understand the problem from above examples.
int solve(int n, int m, string s, vector<string> str)
{

}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isBeautifulSubstring(string &substring, vector<string> &str)
{
    string reversed = substring;
    reverse(reversed.begin(), reversed.end());
    return find(str.begin(), str.end(), reversed) != str.end();
}

int solve(int n, int m, string s, vector<string> &str, unordered_map<string, int> &memo)
{
    if (n == 0)
    {
        return 0;
    }

    if (memo.find(s) != memo.end())
    {
        return memo[s];
    }

    int maxLength = 0;

    for (int i = 1; i <= n; ++i)
    {
        string prefix = s.substr(0, i);

        if (isBeautifulSubstring(prefix, str))
        {
            int remainingLength = n - i;
            int remainingPrefix = solve(remainingLength, m, s.substr(i), str, memo);

            if (remainingPrefix == remainingLength)
            {
                // We can divide the whole string
                maxLength = n;
            }
            else
            {
                // We need to check all possibilities and maximize the prefix length
                maxLength = max(maxLength, i + remainingPrefix);
            }
        }
    }

    memo[s] = maxLength;
    return maxLength;
}

int main()
{
    // Example
    int n = 5, m = 3;
    string s = "abcda";
    vector<string> str = {"a", "b", "dc", "cba"};

    // int n = 4, m = 2;
    // string s = "abcd";
    // vector<string> str = {"cba", "ba"};

    // int n=4, m=1;
    // string s = "badc";
    // vector<string> str = {"ab"};

    unordered_map<string, int> memo;
    cout << solve(n, m, s, str, memo) << endl;

    return 0;
}
