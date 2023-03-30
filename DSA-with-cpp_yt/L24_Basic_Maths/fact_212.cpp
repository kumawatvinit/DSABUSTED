#include<iostream>
using namespace std;
int m = 1000000000 + 7;

int fact(int n, int m)
{
    int ans=1;

    if(n<=2) return n;
    else return (n%m)*(fact(n-1, m)%m);
}

int main()
{
    cout << "Factorial of 212: " << fact(212, m)<< endl;

    return 0;
}