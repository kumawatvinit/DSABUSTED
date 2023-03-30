#include <iostream>

using namespace std;

bool isEven(int num)
{
    if(num&1) return false;
    return true;
}

int main()
{
    int num;
    cout << "Enter num : ";
    cin >> num;

    if(isEven(num))
    cout << "Number is even";
    else
    cout << "Number is Odd!";
}