#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    cout << arr[i] << " ";
}

void sort01(int arr[], int n)
{
    int left = 0;
    int right = n-1;

    while(left<right)
    {
        if(arr[left]==0)
        left++;
        else if(arr[right]==1)
        right--;
        else if(arr[left]==1 && arr[right]==0)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[8] = {1,1,0,0,0,0,1,0};

    print(arr,8);
    cout << endl;
    sort01(arr,8);
    print(arr,8); 
    return 0;
}