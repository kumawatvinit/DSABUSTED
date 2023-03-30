#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for(int i=0; i<size; i++)
    if(arr[i]==key) return true;

    return false;
}

int main()
{
    int arr[] {-69,25,966,594,23,47,32,0,89};

    cout << "Enter the element to search for " << endl;
    int key;
    cin >> key;

    bool found = search(arr,sizeof(arr)/sizeof(arr[0]),key);

    if(found) cout << "Key is present"<< endl;
    else cout << "Key is not present!" << endl;
    return 0;
}