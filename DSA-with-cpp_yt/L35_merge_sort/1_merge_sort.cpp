#include<bits/stdc++.h>
#define fr(i,n) for(int j = i; j<n; j++) 
#define prnt(arr, n) fr(0,n) {cout << arr[i] << " "; cout << endl;} 
using namespace std;

void merge1(int *arr, int s, int e)
{
    int mid = s+(e-s)/2;
    int i = s, j = mid+1;


}

void merge(int *arr, int s, int e)
{
    int mid = s+(e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int * first = new int[len1];
    int * second = new int[len2];

    // Copy both part in two arrays
    for(int i=s; i<len1+s; i++) {
        first[i-s] = arr[i];
    }

    for(int i=mid+1; i<len2+mid+1; i++) {
        second[i-mid-1] = arr[i];
    }

    // merge first and second
    int i=0, j=0, mainarrayIndex = s;
    if(i<len1 && j<len2)
    {
        if(first[i] < second[j]) {
            arr[mainarrayIndex++] = first[i++];
        } else {
            arr[mainarrayIndex++] = second[j++];
        }
    }

    while(i<len1) {
        arr[mainarrayIndex++] = first[i++];
    }

    while(j<len2) {
        arr[mainarrayIndex++] = second[j++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e)
{
    if(s>=e) return;

    int mid = s+(e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);


    merge(arr, s, e);
}

void print(int *arr, int n)
{
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[5] = {2,5,1,6,9};
    int n = 5;

    // int i=0;
    // fr(0,5) {
    //     cout << (i++) << endl;
    // }

    // cout << endl;
    // prnt(arr, 5);
    print(arr, n);
    mergeSort(arr,0,n-1);
    print(arr, n);


    return 0;
}