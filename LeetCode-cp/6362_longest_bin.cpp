#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int cnt0 = 0, cnt1 = 0;
        bool zero = 1;
        int maxi = 0;
        
        for(auto &i: s)
        {
            if(i == '0' && zero) {
                cnt0++;
            }
            else if(i == '0') {
                if(cnt0 == cnt1) {
                    maxi = max(maxi, cnt0+cnt1);
                }
                else {
                    maxi = max(maxi, 2*min(cnt0, cnt1));
                }
                
                cnt0 = 1, cnt1 = 0;
                zero = 1;
            }
            // zero chal rha tha, lekin 1 aa gaya
            else if(i == '1' && zero) {
                cnt1++;
                zero = 0;
            }
            else {
                cnt1++;
            }
        }
        
        if(cnt0 == cnt1) {
            maxi = max(maxi, cnt0+cnt1);
        }
        else {
            maxi = max(maxi, 2*min(cnt0, cnt1));
        }
        
        return maxi;
    }
};

int main()
{
    Solution obj;
    cout << obj.findTheLongestBalancedSubstring("01000111");

    return 0;
}