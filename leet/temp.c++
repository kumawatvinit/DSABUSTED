#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        
        while(i>=0 && nums[i] > nums[i+1])
        {
            i--;
        }
        if(i==-1) {
            reverse(nums.begin(), nums.end());
        } 
        else {
            
            int j = i+1;
            
            while(j<n) {
                if(nums[i] < nums[j]) {
                    j++;
                }
                else {
                    break;
                }
            }
            
            swap(nums[i], nums[j-1]);
            
            
            reverse(nums.begin()+i+1, nums.end());
        }
        
        
    }
};

void print(vector<int> &nums)
{
    for(auto &i: nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    Solution obj;
    
    vector<int> nums{7,6,5,9,5,2,4,4,5};
    print(nums);
    obj.nextPermutation(nums);

    print(nums);
    cout << "7,6,5,9,5,2,4,5,4 -Answer" << endl;

    return 0;
}
// [7,6,5,9,5,2,4,5,4]