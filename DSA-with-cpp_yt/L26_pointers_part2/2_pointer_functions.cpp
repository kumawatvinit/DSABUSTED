#include<iostream>
using namespace std;

void print(int * p)
{
    cout << *p << endl;
}

void update(int * p)
{
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;

    cout << "After.......\n";
    p = p + 1;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
}

void val_update(int * p)
{
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;

    cout << "After.......\n";
    *p = *p + 1;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
}

int main()
{
    int value = 5;
    int *p = &value;

    print(p);

    cout << "Before p: " << p << endl;
    cout << "Before *p: " << *p << endl;
    update(p);
    cout << "After p: " << p << endl;
    cout << "After *p: " << *p << endl;

    cout << endl<<endl;
    val_update(p);
    cout << "After p: " << p << endl;
    cout << "After *p: " << *p << endl;

    

    return 0;
}