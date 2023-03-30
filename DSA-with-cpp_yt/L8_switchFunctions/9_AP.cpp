#include <iostream>
using namespace std;

// An = 3n+7

int NthTermOfAP(int n)
{
    return 3*n+7;
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "1st ";
        break;
    
    case 2:
        cout << "2nd ";
        break;
    
    case 3:
        cout << "3rd ";
        break;
    
    default:
        cout << n << "th ";
        break;
    }
    cout << "term : " << NthTermOfAP(n);
}