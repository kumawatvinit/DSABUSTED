#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
bool sieve[N+1];

void createSieve()
{
    sieve[0] = false;
    for(int i=2; i<N; ++i)
    {
        sieve[i] = true;
    }

    for(int i=2; i*i<=N; ++i)
    {
        if(sieve[i])
        {
            for(int j=i*i; j<=N; j++)
            {
                sieve[j] = false;
            }
        }
    }
}

vector<int> generatePrimes(int N)
{
    vector<int> ds;
    for(int i=2; i<=N; i++) {
        if(sieve[i]) {
            ds.push_back(i);
        }
    }

    return ds;
}

int main()
{
    createSieve();
    int t;
    cin>>t;

    int l, r;

    while(t--)
    {
        cin >> l >> r;

        // Step 1: Generate primes till <=sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));


        // Step 2: create a dummy array of size r-l+1 and make 
        // everyone as 1

        int dummy[r-l+1];
        for(int i=0; i<r-l+1; i++) {
            dummy[i] = 1;
        }

        // Step 3: Mark all multiple of primes as false

        for(auto pr: primes) {
            int firstMultiple = ((l/pr)*pr)<=l? ((l/pr)*pr): ((l/pr)*pr);

            for(int j=max(firstMultiple, pr*pr); j<=r; j+=pr)
            {
                dummy[j-l] = 0;
            }
        }

        int count=0;
        for(int i=l; i<=r; i++) {
            if(dummy[i-l]) {
                cout << i << " ";
                count++;
            }
        }
        cout << "\ncount: " << count << endl;
    }

    return 0;
}