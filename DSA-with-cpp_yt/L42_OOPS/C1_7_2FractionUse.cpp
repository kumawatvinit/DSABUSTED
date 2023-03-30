#include<bits/stdc++.h>
using namespace std;
#include "C1_7_1Fraction.cpp"

int main()
{
    fraction f1(10, 2);
    fraction f2(15, 4);

    f1.print();
    f2.print();

    f1.add(f2);

    f1.print();
    f2.print();   

    f1.multiply(f2);
    f1.print();
    
    return 0;
}