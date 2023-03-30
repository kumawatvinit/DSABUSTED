#include<iostream>

using namespace std;

void merge(int ans[], int a[], int n, int b[], int m)
{
    int i=0, j=0, k=0;

    while(i<n && j<m)
    {
        if(a[i]<b[j]) ans[k++] = a[i++];
        else ans[k++] = b[j++];
    }

    while(i<n)  ans[k++] = a[i++];
    while(j<m)  ans[k++] = b[j++];
}

void print(int ans[], int n)
{
    for(int i=0; i<n; ++i) cout<<ans[i]<<" "; cout<<endl;
}

int main()
{
    int a[5] = {1,3,5,7,9};
    int b[3] = {2,3,6};

    int ans[8] = {0};
    merge(ans, a, 5, b, 3);
    print(ans,8);

    return 0;
}