#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    bool isPrime=true;

    for(int i=2; i<n;i++)
    {
        if(n%i==0)
        {
            isPrime=false;
            break;
        }
    }
    if(isPrime)
    cout<<"Prime number";
    else 
    cout<<"Not a prime number!";
}
