// print name N times
// Print 1-N
// Print N -> 1

#include<iostream>
using namespace std;

// 1 -> N
void print(int i, int n)
{
    if(i>n) return;
    cout << i << ". Vini " << endl;

    print(i+1, n);
}

/*
    TC: O(n)
    SC: o(n) **Internally (stack)
*/

// N -> 1
void revPrint(int i)
{
    if(i<1) return;

    cout << i << " ";
    revPrint(i-1);
}

// Backtracking
// 1 -> N
void rec(int i)
{
    if(i>=1)
    {
        rec(i-1);
        cout << i << " ";
    }
}


// Backtracking
// N -> 1
void rec2(int i, int n)
{
    if(i<=n)
    {
        rec2(i+1, n);
        cout << i << " ";
    }
}


int main()
{
    int n;
    cin >> n;

    /*
    print(1, n);
    cout << endl;

    revPrint(n);
    cout << endl; */

    rec(n);
    cout << endl;

    rec2(1,n);
    cout << endl;

    return 0;
}