#include<bits/stdc++.h>
using namespace std;


void print(int arr[], int size)
{
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int input[], int s, int e)
{
	int mid = (s+e)/2;
        int size1 = mid + 1 - s ;
        int size2 = e - mid;

        int *arr1 = new int[size1];
        int *arr2 = new int[size2];

	for(int i=s; i<=mid; i++) {
		arr1[i-s] = input[i];
	}
	for(int i=mid+1; i<=e; i++) {
		arr2[i-mid-1] = input[i];
	}

	// merge
	int i=0, j=0, k=s;

	while(i<size1 && j<size2) 
	{
		if(arr1[i] <= arr2[j]) {
			input[k++] = arr1[i++];
		}
		else {
			input[k++] = arr2[j++];
		}
	}

	while(i<size1) {
		input[k++] = arr1[i++];
	}
	while(j<size2) {
		input[k++] = arr2[j++];
	}
}

void helper(int input[], int s, int e)
{
	if(s<e)
	{
		int mid = (s+e)/2;

  		// sort 0 to mid
    	helper(input, 0, mid);
        print(input, mid+1);

        // sort mid+1 to size
    	helper(input, mid+1, e);
        print(input,e+1);

        cout << endl << "\t\t";
    	// merge both
		merge(input, s, e);
        print(input, e+1);
	}
}

void mergeSort(int input[], int size){
	helper(input, 0, size-1);
}


int main()
{
    int arr[] = {2,6,8,5,4,3};
    
    print(arr, 6);
    mergeSort(arr, 6);
    print(arr, 6);
}
