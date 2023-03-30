#include<iostream>
using namespace std;

int main()
{
    // int *p=NULL;

    // cout << *p << endl;

/*
    int i = 5;
    int *p = NULL;
    p = &i;

    int *q = &i;

    cout << p << ", *p: " << *p << endl;
    cout << q << ", *q: " << *q << endl;
    */

    int num = 5;
    int a = num;

    a++;

    cout << "a: " << a << ", num: " << num << endl;

    int *p = &num;
    (*p)++;
    cout << "p: " << p << ", *p: " << *p << ", num: " << num << endl;

    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    *p = *p +1;
    cout << p << endl;
    cout << *p << endl;

    p++;
    cout << p << endl;
    cout << *p << endl;

    return 0;
}