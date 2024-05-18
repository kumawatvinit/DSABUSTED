#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> w(n);

        for (int i = 0; i < n; i++)
            cin >> w[i];

        int left = 0, right = n - 1;
        int lSum = 0, rSum = 0;
        int ans = 0;

        while(left <= right)
        {
            if(lSum < rSum)
            {
                lSum += w[left];
                left++;
            }
            else if(lSum > rSum)
            {
                rSum += w[right];
                right--;
            } else {
                ans = left + n-right-1;
                lSum += w[left];
                left++;
            }
        }

        if(lSum == rSum) ans = n;

        cout << ans << endl;

    }

    return 0;
}