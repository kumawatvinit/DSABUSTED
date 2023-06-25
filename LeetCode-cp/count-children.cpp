#include<bits/stdc++.h>
using namespace std;

vector<long> count_children(long N)
{
    vector<long> children(N,0);
    children[0] = 1;
    children[1] = 1;

    for(int i=2;i<N;i++)
    {
        children[i] = children[i-1] + children[i-2];
    }

    reverse(children.begin(),children.end());
    
    return children;
}

int main()
{
    vector<long> ans = count_children(10);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}