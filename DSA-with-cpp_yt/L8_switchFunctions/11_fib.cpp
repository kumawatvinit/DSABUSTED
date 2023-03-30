#include <iostream>
using namespace std;

int NthFibonacciNumber(int n)
{
    int a=0, b=1,c=0;
    
    if(n==1) return 0;
    else if(n==2) return 1;

    for(int i=3; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }

    return c;
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << n << "th fibonacci number : " <<
    NthFibonacciNumber(n);
}
