#include <bits/stdc++.h>
using namespace std;
#define mod 1000003

int solve(int n, vector<int> &A)
{
    int ans = 0;

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            ans += A[i] / A[j];
            ans %= mod;
        }
    }

    return ans;
}

int main()
{
    vector<int> A{1, 2, 3, 4, 5};

    cout << solve(5, A) << endl;

    return 0;
}