#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> nums{1,2};
    vector<int> nums{3,4,6,8};
    // vector<int> nums{1,2,3,4,5,6};

    int size = nums.size();
    int maxi = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int newGcd = __gcd(nums[i], nums[j]);
            maxi = max(maxi, newGcd);
            cout << newGcd << ", ";
        }
    }

    cout << "\nMax : " << maxi << endl;
    cout << "Answer : " << (maxi*(size/2)) << endl;

    return 0;
}