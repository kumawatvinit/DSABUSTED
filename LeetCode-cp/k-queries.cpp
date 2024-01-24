#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int h)
{
    int n = arr.size();
    int l = 0, r = n - 1;
    int ans = n + 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] <= h)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid + 1;
            r = mid - 1;
        }
    }

    return n - ans + 1;
}

int main()
{
    int n, k;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int h;
        cin >> h;
        cout << solve(arr, h) << endl;
    }

    return 0;
}