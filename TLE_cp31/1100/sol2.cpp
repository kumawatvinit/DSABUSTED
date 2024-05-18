#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;

    // Read input
    cin >> n;
    cin >> s;

    // Convert string to an array of integers
    vector<int> digits(n);
    for (int i = 0; i < n; ++i)
    {
        digits[i] = s[i] - '0';
    }

    // Compute prefix sums
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        prefixSum[i + 1] = prefixSum[i] + digits[i];
    }

    int maxLength = 0;

    // Check all even length substrings
    for (int len = 2; len <= n; len += 2)
    { // Only even lengths
        for (int i = 0; i <= n - len; ++i)
        {
            int mid = i + len / 2;
            int leftSum = prefixSum[mid] - prefixSum[i];
            int rightSum = prefixSum[i + len] - prefixSum[mid];
            if (leftSum == rightSum)
            {
                maxLength = max(maxLength, len);
            }
        }
    }

    // Output the result
    if (maxLength == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << maxLength << endl;
    }

    return 0;
}
