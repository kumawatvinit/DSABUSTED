/*  Euclid's algorithm
    gcd(a,b) = gcd(a-b, b)
             = gcd(a%b, b)

    lcm(a,b)*gcd(a,b) = a*b
*/

/*
    Pigeon principle
    Catalon number
    Inclusive-Exclusive principle
*/

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a==0) return b;
    if(b==0) return a;

    while(a != b)
    {
        if(a>b) a-=b;
        else b-=a;
    }

    return a;
}

int main()
{
    int a, b;
    cout << "Enter the values of a and b: ";
    cin >> a >> b;

    cout << gcd(a, b) << endl;

    return 0;
}