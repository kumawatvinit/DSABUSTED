#include<bits/stdc++.h>

using namespace std;

bool custom_comparator(int a, int b)
{
    return a>b;
}

int main()
{
    int N=0;
    cin>>N;

    int *A = new int[N];

    for(int i=0; i<N; i++)
    {
        cin>>A[i];
    }
    long long int ans=0;

    sort(A, A+N, custom_comparator);

    int i=0;
    for(; i+1<N; )
    {
        ans+= A[i] + A[i+1];
        i+=3;
    }

    if(i==(N-1)) { ans+= A[N-1];}
    cout<<ans<<endl;
    return 0;
}