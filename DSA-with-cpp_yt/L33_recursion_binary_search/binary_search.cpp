#include<iostream>
using namespace std;

int binarySearch(int* arr, int s, int e, int target)
{
    if(s>e) return -1;

    int mid = s+(e-s)/2;

    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target) {
        return binarySearch(arr, s, mid-1, target);
    }
    else {
        return binarySearch(arr, mid+1, e, target);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 7, 8, 9};
    int size = 6;
    int target = 8;

    int ans = binarySearch(arr, 0, size-1, target);

    if(ans==-1)
        cout << target << " not found!" << endl;
    else 
        cout << target <<" found at index: " << ans << endl;

    return 0;
}