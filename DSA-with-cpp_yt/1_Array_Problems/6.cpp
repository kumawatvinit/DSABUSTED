#include <iostream>
using namespace std;

// Kth smallest and kth largest

int main()
{
    int k,size;
    cin >> k >> size;

    int *arr = new int [size];

    for(int i=0; i<size; i++)
    cin >> arr[i];

    // sorting
    int temp=0;

    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i=0; i<size; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Kth smallest  : " << arr[k-1] << endl;
    cout << "Kth largest  : " << arr[size-k] << endl;

    return 0;
}