#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// Sieve of eratosthenes
// T.C. O(n*log(log(n)))

/*
bool isPrime(int n)
{
    if(n<=1) return false;

    for(int i=2; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
} */

int main()
{
    int n;
    cin>>n;

    // Number of primes less than n
    int count = 0;

    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    /*
    if(isPrime(n))
    {
        cout << "It is prime number" << endl;
    }
    else
    cout << "It is not Prime number!" << endl; */

    int upper = sqrt(n);
    for(int i=2; i<n; ++i)
    {
        if(prime[i])
        {
            cout << i << " ";
            count++;

            if(i>upper) continue;
            else
            {
                for(int j=i*i; j<n; j+=i)
                {
                    prime[j] = false;
                }
            }
        }
    }

    cout << "\nNumber of primes less than " << n << " : " << count << endl;
    return 0;
}