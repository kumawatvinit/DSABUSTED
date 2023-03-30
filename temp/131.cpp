#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s)
{
    int start = 0, end = s.size() - 1;

    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

class Solution
{
    vector<vector<string>> ans;

    void generator(const string &s, int idx, vector<string> &temp)
    {
        int size = temp.size();

        // base condn.
        if (idx >= s.size())
        {
            if (size > 0)
            {
                string last = temp[size - 1];

                if (!isPalindrome(last))
                {
                    return;
                }
            }

            ans.push_back(temp);
            return;
        }
        // curr: current character at idx
        

        // either include the curr in previous substring
        if (size > 0)
        {
            string last = temp[size - 1];
            temp.pop_back();
            last += s[idx];
            temp.push_back(last);
            generator(s, idx + 1, temp);

            // revert the changes
            last = temp[size - 1];
            temp.pop_back();
            last.pop_back();
            temp.push_back(last);
        }

        if (size > 0)
        {
            string last = temp[size - 1];

            if (!isPalindrome(last))
            {
                return;
            }
        }

        // or make a new string of curr
        string newString = "";
        newString += s[idx];

        temp.push_back(newString);
        generator(s, idx + 1, temp);

        // reverting changes
        temp.pop_back();
    }

    void print(vector<vector<string>> &vec)
    {
        for (auto &v : vec)
        {
            for (auto &itr : v)
            {
                cout << itr << " ";
            }
            cout << endl;
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        generator(s, 0, temp);
        print(ans);
        cout << "-----------" << ans.size() << "-----------" << endl;
        return ans;
    }
};

int main()
{
    // string s = "abc";
    // string s = "a";
    // string s = "adrtc";
    string s = "abbcddad";
    // string s = "aaaaaaaaaaaaaaaa";
    Solution obj;

    obj.partition(s);

    return 0;
}