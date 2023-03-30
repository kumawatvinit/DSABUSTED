#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    for(int i=0; i<size; i++) cout << arr[i] << " ";
}

void reverse(int arr[], int size)
{
    int start = 0, end = size-1;

    while(start<end)
    {
        swap(arr[start++], arr[end--]);
    }
}

int main()
{
    int arr[6] {1,4,0,5,-2,15};
    int arr2[5] {2,6,3,9,4};

    reverse(arr,6);
    reverse(arr2,5);

    print(arr,6);
    cout << endl;
    print(arr2,5);

    return 0;
}