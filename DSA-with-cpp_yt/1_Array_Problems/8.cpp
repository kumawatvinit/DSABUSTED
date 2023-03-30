#include <iostream>
using namespace std;

int main()
{
    int size;
    cin>>size;

    int *arr = new int[size];

    for(int i=0; i<size; i++)
    cin >> arr[i];

    int a=0,b=0,c=0;

    for(int i=0; i<size; i++)
    {
        switch(arr[i])
        {
            case 0:
                a++;
                break;
            case 1:
                b++;
                break;
            case 2: 
                c++;
                break;
        }
    }

    for(int i=0; i<size; i++)
    {
        if(i<a) arr[i] = 0;
        else if(i<a+b) arr[i]=1;
        else arr[i] = 2;
    }

    for(int i=0; i<size; i++) cout << arr[i] << " ";
    return 0;
}