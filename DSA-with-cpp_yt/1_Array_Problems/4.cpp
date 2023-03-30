#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *array = new int[n];

    for(int i=0; i<n; i++) cin>>array[i];

    int temp=0;
    for(int i=0; i<n/2; i++)
    {
        temp = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = temp;
    }

    for(int i=0; i<n; i++) cout<<array[i]<<" ";

    return 0;
}