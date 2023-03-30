#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        int n = nums1.size();
        long long sum = 0;
        
        vector<int> temp;
        
        if(k!=0) {
            for(int i=0; i<n; i++)
            {
                int diff = nums1[i]-nums2[i];
                temp.push_back(diff);
                sum+=diff;

                if(diff%k !=0) {
                    return -1;
                }
            }
        }
        else {
            for(int i=0; i<n; i++)
            {
                if(nums1[i] != nums2[i]) {
                    return -1;
                }
            }
            return 0;
        }
        
        if(sum!=0) {
            return -1;
        }
        
        for(int i=0; i<n; i++)
        {
            ans+=abs(temp[i]/k);
        }
        
        return ans/2;
    }
};

int main()
{
  vector<int> a{4,3,1,4};
//   vector<int> a{3,8,5,2};

  vector<int> b{1,3,7,1};
//   vector<int> b{2,4,1,6};


  Solution obj;

//   cout << obj.minOperations(a,b,3);
//   cout << obj.minOperations(a,b,1);
  cout << obj.minOperations(a,b,0);

  return 0;
}