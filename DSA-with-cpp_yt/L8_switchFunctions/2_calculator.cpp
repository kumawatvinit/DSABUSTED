#include <iostream>

using namespace std;

int main()
{
    int a,b;
    char ch;

    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;

    cout << "Enter the operation you want to perform" << endl;
    cin >> ch;

    switch (ch)
    {
    case '+':
        cout << (a+b) << endl;
        break;
    
    case '-':
        cout << (a-b) << endl;
        break;

    case '*':
        cout << (a*b) << endl;
        break;

    case '/':
        cout << (a/b) << endl;
        break;

    case '%':
        cout << (a%b) << endl;
        break;
    }


}