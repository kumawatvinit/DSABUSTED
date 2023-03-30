#include<bits/stdc++.h>
using namespace std;
#include "C2_10_1PolynomialClass.cpp"

/*
    0 0 3 0 0 4 0 -1 -coefficient
    0 1 2 3 4 5 6 7  -degree
    3x^2 + 4x^5 - x^7
    setCoefficient(degree, coefficient)
    */

int main()
{
/* constructor, print
    polynomial p;
    p.print();

    polynomial p2(15);
    p2.print();
    p2.setcoefficient(2,-3);
    p2.setcoefficient(5,4);
    p2.setcoefficient(7,-1);

    p2.print();
*/

  // +,-,* OperatorOverloading
    polynomial p3(7);
    // p3.print();
    p3.setcoefficient(0,3);
    p3.setcoefficient(2,4);
    p3.setcoefficient(5,-2);
    cout << "p3: ";
    p3.print();

    polynomial p4(7);
    // p4.print();
    p4.setcoefficient(1,-1);
    p4.setcoefficient(2,1);
    p4.setcoefficient(3,1);
    p4.setcoefficient(4,1);
    cout << "p4: ";
    p4.print();

    // +
    polynomial p5 = p3+p4;
    cout << "p5=p3+p4: ";
    p5.print();
    
    // -
    polynomial p6 = p3-p4;
    cout << "p6 = p3-p4: ";
    p6.print();


    polynomial p7(7);
    // p7.print();
    p7.setcoefficient(1,-1);
    p7.setcoefficient(2,1);
    p7.setcoefficient(3,1);
    p7.setcoefficient(4,1);
    cout << "p7: ";
    p7.print();

    p7.setcoefficient(15, 98);
    p7.setcoefficient(100, 87);
    cout << "p7: ";
    p7.print();

    // *
    polynomial p8 = p3*p4;
    cout << "p8 = p3*p4: ";
    p8.print();

    polynomial p9 = p3*p7;
    cout << "p9 = p3*p7: ";
    p9.print();

    return 0;
}