#include<iostream>
using namespace std;

// Recursive linear search
bool linearSearch(int *arr, int size, int target)
{
    if(size==0) return false;

    if(arr[0]==target) return true;
    return linearSearch(arr+1, size-1, target);
}

int main()
{
    int arr[] = {3,5,1,2,6,22};
    int size = 6;
    int key = 22;

    bool ans = linearSearch(arr, size, key);

    if(ans)
    cout << "Found" << endl;
    else 
    cout << "Not found" << endl;

    return 0;
}