#include <stdio.h>
#include <math.h>
#include <time.h>

int isPrime(int n)
{
    // this function will return 1 if n is prime
    // else return 0

    if (n < 2)
        return 0;

    /*
        check for each no. from 2 to n-1, if it divides n,then return 0;
        15%2
        15%3 = 0, 15/3 = 5
    */
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int optimizedPrime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int fn()
{
    return 1;
}

int main()
{
    // print prime no.s between a range

    // print continuous no.s
    // for (int i = 5; i < 12; i += 2)
    //     printf("%d ", i);

    // print prime no.s starting from 0

    clock_t t; 
    t = clock(); 

    for (int i = 0; i < 80001; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
    
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
 
    printf("\nfun() took %f seconds to execute \n", time_taken); 


    printf("\n\n-------------------\n\n");

    t=clock();

    for (int i =0; i < 80001; i++)
    {
        if (optimizedPrime(i))
        {
            printf("%d ", i);
        }
    }

    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
 
    printf("\nfun() took %f seconds to execute \n", time_taken);

    return 0;
}