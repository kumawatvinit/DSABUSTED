#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n=0, ans=0, digit=0,i=0;

    cout<<"Enter n: ";
    cin>>n;

    if(n==0)
    {
        cout<<0;
        return 0;
    }
    while(n>0)
    {
        digit = n%2;

        ans = ans + digit*pow(10,i);
        n=n/2;i++;
    }

    cout<<ans;
}