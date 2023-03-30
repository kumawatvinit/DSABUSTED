#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{
    for(int i=0; i<n; i++)
    {

        bool swapped = false;

        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }
}

void print(vector<int>& vec)
{
    for(int &i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

void revBubble(vector<int>& arr, int i)
{
    int n = arr.size();
    if(i>=n) return;

    for(int j=0; j<n-1-i; j++)
    {
        if(arr[j]>arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
    revBubble(arr, i+1);
}

int main()
{
    vector<int> v({3,6,8,1,3,0,23,54,21});
    print(v);
    // bubbleSort(v,v.size());
    revBubble(v,0);
    print(v);

    return 0;
}
