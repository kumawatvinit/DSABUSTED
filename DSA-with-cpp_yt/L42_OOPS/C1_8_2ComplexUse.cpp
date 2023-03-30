#include<bits/stdc++.h>
using namespace std;
#include "C1_8_Complex.cpp"

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    c1.print();
    c2.print();

    int choice;
    cin >> choice;

    if(choice==1) {
        c1.plus(c2);
    }
    else if(choice==2) {
        c1.multiply(c2);
    }

    return 0;
}