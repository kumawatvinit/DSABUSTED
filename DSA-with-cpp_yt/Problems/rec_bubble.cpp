#include <iostream>
using namespace std;

void rec_Bubble_Sort(int arr[], int n)
{
    if(n==1) return;

    bool swappped = false;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]) 
        {
            swap(arr[i],arr[i+1]);
            swappped = true;
        }
    }
    
    if(swappped==false) return;

    rec_Bubble_Sort(arr,n-1);
}

int main()
{
    int arr[] = {3,6,1,9,4,0,23};

    rec_Bubble_Sort(arr,7);

    for (int i = 0; i < 7; i++)
    cout << arr[i]<<", ";
    
}