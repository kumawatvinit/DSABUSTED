#include<iostream>
using namespace std;

void update(int **p)
{
    // p = p+1;

    *p = *p+1;

    // **p = **p + 1;
}

int main()
{
    int i = 5;
    int *p = &i;
    int ** p2 = &p;
/*
    cout << endl << endl << " Sab sahi chal rha hai " << endl;

    cout << "p : " << p << endl;
    cout << "*p2 : " << *p2 << endl;
    cout << "&i : " << &i << endl << endl;

    cout << "&p : " << &p << endl;
    cout << "p2 : " << p2 << endl << endl;

    cout << "**p2 : " << **p2 << endl;
*/

    cout << endl << "Before : " << endl;
    cout << i << endl;
    cout << p << endl;
    cout << p2 << endl;

    update(p2);
    cout << endl << "After : " << endl;
    cout << i << endl;
    cout << p << endl;
    cout << p2 << endl;

    return 0;
}