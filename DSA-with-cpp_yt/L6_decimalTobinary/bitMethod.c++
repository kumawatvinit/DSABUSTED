#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int ans = 0, bit=0, i=0;

    int n;
    cout<<"Enter n: ";
    cin>>n;

    if(n==0)
    {
        cout<<0;
        return 0;
    }
    while(n!=0)
    {
        bit = n&1;
        n=n>>1;

        ans = ans + bit*pow(10,i);
        i++;
    }
    cout<<ans;
}