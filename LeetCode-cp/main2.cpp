#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n=0, m=0;
    cin>>n>>m;

    int *A = new int[n];

    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }

    int size = pow(2,n);
    bool isTrue = false;


    for(int i=1; i<size; i++)
    {
        int ans=0;
        for(int j=0; j<n; j++)
        {
            if((1<<j)&i) ans+=A[j];
        }

        if(ans%m==0) { isTrue = true; break;}
    }
    
    if(isTrue) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}