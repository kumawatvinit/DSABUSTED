#include<iostream>
using namespace std;

void wavePrint(int **arr, int n, int m)
{
    for(int j=0; j<m; ++j)
    {
        if(j%2==0)
        {
            for(int i=0; i<n; ++i)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for(int i=n-1; i>=0; --i)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int** arr = new int* [n];
    for(int i=0; i<n; ++i)
    {
        arr[i] = new int[m];
    }

    cout << "Enter elements: " << endl;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin >> arr[i][j];   
        }
    }

    cout << "Your elements: " << endl;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cout << arr[i][j] << " ";   
        }
        cout << endl;
    }

    wavePrint(arr, n , m);
    return 0;
}