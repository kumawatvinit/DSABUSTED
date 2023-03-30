#include <iostream>
using namespace std;

int main()
{
    int a[10];
    cout << "Enter 10 elements : " << endl;

    for(int i=0; i<10; i++)
    cin >> a[i];
    
    cout << "Elements :\n";
    for(int i=0; i<10; i++)
    cout << "a[" << i << "] : " << a[i]<<endl;

}