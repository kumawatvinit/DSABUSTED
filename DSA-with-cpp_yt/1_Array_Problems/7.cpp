#include <iostream>
using namespace std;

int main()
{
    int n, size;
    cin >> n >> size;

    int *arr = new int[size];
    for(int i=0; i<size; i++) cin >> arr[i];

    int count=0;

    for(int i=0; i<size; i++)
    if(arr[i]==n) count++;
    
    cout << count;
    return 0;
}