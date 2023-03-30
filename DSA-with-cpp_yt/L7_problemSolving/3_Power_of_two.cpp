#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    int ans=1;  // 2^0

    if(n==1) return true;

    for(int i=1; i<=30; i++)
    {
        // int ans = pow(2,i);
        ans*=2;
        
        if(ans==n) return true;
        else if(ans>n) return false;
    }
    return false;
    /*
    return ((n>0)&&((n&(n-1))==0));
    */
}

int main()
{
    int n;

    cin >>n;
    cout << boolalpha << isPowerOfTwo(n);
    return 0;
}