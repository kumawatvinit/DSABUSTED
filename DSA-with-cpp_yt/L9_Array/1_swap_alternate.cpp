#include <iostream>
using namespace std;

int main()
{
    int size=6;
    int arr[6] {1,2,3,4,5,6};
    // int arr[5] {1,2,7,8,5};
    // int *arr = new int[size];

    for(int i=0; i<size-1; )
    {
        swap(arr[i],arr[i+1]);
        i=i+2;
    }
    
    for(int i=0; i<size; i++) cout << arr[i] << " ";
    return 0;
}