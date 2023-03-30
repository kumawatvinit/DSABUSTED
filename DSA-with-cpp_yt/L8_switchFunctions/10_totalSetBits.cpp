#include <iostream>
using namespace std;

int setBits(int a, int b)
{
    int ans = 0;

    while(a!=0)
    {
        if(a&1)
        ans++;
        a>>=1;
    }
    while(b!=0)
    {
        if(b&1)
        ans++;
        b>>=1;
    }
    return ans;
}

int main()
{
    int a, b;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;

    cout << "Total set bits : " << setBits(a,b);
}