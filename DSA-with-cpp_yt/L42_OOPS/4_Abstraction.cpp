/*
    "Implementation Hiding"

    Advantages:
    -> Only you can make changes to ur data Or function, and no one else can.
    -> Makes application secure by not allowing anyone else to see the background details.
        e.g. 
            using pow() from math.h header file
    -> Reusability
*/
#include <iostream>
#include <vector>
using namespace std;

void func(vector<int> arr, int k, int n)
{
    int ans = n;
    int sum=0;
    
    int start=0, end=0;
    
    for(int end=0; end<n; end++)
    {
        sum+= arr[end];
        
        while(sum>k)
        {
            sum-= arr[start];
            start++;
            
            ans = min(ans, end-start+1);
            
            if(sum==0)
            {
                break;
            }
        }
        
        if(sum==0)
        {
            ans=-1;
            break;
        }
        
    }
    
    
    cout << ans;
    
}

int main() {
	
	vector<int> arr{ 1, 2, 3, 4 };
    int k = 8;
    int n = arr.size();
  
    func(arr, k, n);
	
	return 0;
}