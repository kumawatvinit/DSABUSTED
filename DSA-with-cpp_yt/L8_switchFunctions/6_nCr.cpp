#include <iostream>

using namespace std;

int fact(int n)
{
    int fact = 1;

    for(int i=1; i<=n; i++)
    fact*=i;

    return fact;
}

int nCr(int n, int r)
{
    int num = fact(n);
    int denom = fact(n-r) * fact(r);

    return num/denom;
    return (fact(n)/(fact(n-r)*fact(r)));
}

int main()
{
    int n,r;

    cout << "Enter n : ";
    cin >> n;
    cout << "Enter r : ";
    cin >> r;

    cout << "Answer : " << nCr(n,r);
}