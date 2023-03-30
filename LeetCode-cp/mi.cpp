#include<bits/stdc++.h>
using namespace std;

int A;

int helper(vector<int> &vec, int index, int sum, int count)
{
  if(index >= vec.size()) {
    return 0;
  }

  int ans = 0;

  // taking current element
  if(A == ((sum+vec[index])/(count+1))) {
    ans+=1;
  }
  
  ans+= helper(vec,index+1, sum+vec[index], count+1);
  ans+= helper(vec,index+1, sum, count);

  return ans;
}

int main()
{
  int n, a;
  cin >> n >> a;

  vector<int> vec(n);
  for(int i=0; i<n; i++) {
    cin >> vec[i];
  }

  A = a;
  cout << helper(vec,0,0,0);
  
}

// 8 5
// 3 6 2 8 7 6 5 9