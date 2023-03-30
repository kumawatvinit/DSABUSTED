#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int *array = new int[size];
    for(int i=0; i<size; i++) cin>>array[i];

    int p=0;
    for(int i=0; i<size; i++)
    {
        if(array[i]<0)
        {
            swap(array[i],array[p]);
            p++;
        }
    }

    for(int i=0; i<size; i++)
    cout << array[i] << " ";
    
    return 0;
}