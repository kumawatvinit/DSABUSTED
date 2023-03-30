#include<bits/stdc++.h>
using namespace std;
#include "C2_6_1OperatorOverloading.cpp"

int main()
{
    fraction f1(10,3);
    fraction f2(5,2);

/*
    fraction f3 = f1.add(f2);
    f1.print();
    f2.print();
    f3.print();
*/ 
/* 1
    fraction f4 = f1+f2;
    f4.print();

    fraction f5 = f1+f1;
    f5.print();

    fraction f6 = f1*f2;
    f6.print();

    if(f4 == f3) {
        cout << "Equal" << endl;
    }
    else{
        cout << "Not equal" << endl;
    }
*/
/* 2
    f1.print();
    ++f1;
    f1.print();


    fraction f7 = ++f1;
    f1.print();
    f7.print();

    cout << "Nested" << endl;
    fraction f8 = ++(++f1);
    f1.print();
    f8.print();
*/
/* 3
    fraction f3 = f1++;
    f1.print();
    f3.print();
// Nesting is not allowed on post-increment
*/

    (f1 += f2) += f2;
    f1.print();
    f2.print();

    return 0;
}