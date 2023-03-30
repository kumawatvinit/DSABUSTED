#include<bits/stdc++.h>
using namespace std;
#include "C1_7_1Fraction.cpp"

int main()
{
    fraction f1(10, 2);
    fraction f2(15, 4);

    fraction const f3;

    // Only constant functions can be called on a constant object
    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;

    
    return 0;
}

// Constant functions: 
// Which doesn't change any property of current object