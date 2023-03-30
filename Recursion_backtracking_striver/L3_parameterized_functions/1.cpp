// Sum of first n numbers
// factorial n

#include<iostream>
using namespace std;

int sum(int i, int n)
{
    if(i<=n)
    {
        cout << i << " ";
        return i+sum(i+1, n);
    }
    return 0;
}

// Parameterised
void f(int i, int sum)
{
    if(i<1)
    {
        cout << sum << endl;
        return;
    }
    f(i-1, sum+i);
}

int fact(int i)
{
    if(i<1) return 1;

    return i*fact(i-1);
}

int main()
{
    int n;
    cin >> n;

    // cout << endl << sum(1, n) << endl;
    // f(n, 0);

    cout << fact(n) << endl;
    
    return 0;
}