#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int ans=0, i=0, digit=0, n=0;

    cout<<"Enter a binary number n: ";
    cin>>n;

    if(n==0)
    {
        cout<<0;
        return 0;
    }
    while (n>0)
    {
        // digit=n&1;
        // n=n>>1;
        digit = n%10;

        ans = ans + digit*pow(2,i);
        n=n/10;i++;
    }
    cout<<ans;
}