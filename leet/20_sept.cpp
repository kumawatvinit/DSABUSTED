#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequences(vector<int> &a, vector<int> &b)
    {
        int count = 0, maxi = 0;
        int n = a.size(), m = b.size();

        for(int i=0; i<n; i++)
        {
            int start = i;
            count = 0;

            for(int j=0; j<m; j++)
            {
                if(a[i]==b[j]) {
                    while(a[i]==b[j] && j<m) {
                        count++;
                        i++;
                        j++;
                    }
                }

                maxi = max(maxi,count);
                i = start;
                count=0;
            }

            i = start;
            maxi = max(maxi, count);
        }
        maxi = max(maxi, count);

        return maxi;
    }
};

int main()
{
    vector<int>a({1,2,3,2,1});
    vector<int>b({3,2,1,4,5});

    Solution obj;
    cout << obj.longestCommonSubsequences(a,b) << endl;

    return 0;
}