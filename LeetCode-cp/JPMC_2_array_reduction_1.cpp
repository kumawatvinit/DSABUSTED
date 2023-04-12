#include<bits/stdc++.h>
using namespace std;

int reductionCost(vector<int> num)
{
    priority_queue<int, vector<int>, greater<int> > pq;

    int ans = 0;

    for(int &i: num)
    {
        pq.push(i);
    }

    while(pq.size()>1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        ans+= a+b;
        pq.push(a+b);
    }
    
    return ans;
}


int main()
{
    
    // vector<int> num{4,6,8};
    // vector<int> num{1,2,3};
    vector<int> num{1,2,3,4};
    
    cout << reductionCost(num);
    return 0;
}