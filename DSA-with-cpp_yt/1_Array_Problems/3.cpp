#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    int min=arr[0],max=arr[0];

    for(int i=0; i<n; i++)
    {
        if(arr[i]>max) max = arr[i];
        if(arr[i]<min) min = arr[i];
    }

    cout << "MAX : " << max << endl;
    cout << "MIN : " << min << endl;

    return 0;
}