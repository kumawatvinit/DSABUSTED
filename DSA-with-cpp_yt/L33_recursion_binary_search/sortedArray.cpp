#include<iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
    if(size==0 || size==1) {
        return true;
    }

    if(arr[0]>arr[1]) {
        return false;
    }
    else {
        return isSorted(arr+1, size-1);
    }
}

int sum(int *arr, int size) 
{
    if(size==0) return 0;
    return arr[0] + sum(arr+1,size-1);
}

int main()
{
    int arr[] = {2,3,4,61,82,99};
    int arr2[] = {2,3,4,5,2,9};
    int size = 6;

    if(isSorted(arr, size)) {
        cout << "arr is Sorted" << endl;
    }
    else {
        cout << "Unsorted!" << endl;
    }

    cout << sum(arr2, size) << endl;
    return 0;
}