#include<iostream>
using namespace std;

int main()
{
    // int n;
    // cin >> n;
    int row, col;
    cin >> row >> col;

    // Creating a 2D array
    int** arr = new int*[row];
    for(int i=0; i<row; i++)
    {
        arr[i] = new int[col];
    }

    
    for(int j=0; j<row; j++) {
        for(int i=0; i<col; i++)
        {
            cin >> arr[j][i];
        }
    }
    for(int j=0; j<row; j++) {
        for(int i=0; i<col; i++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    

    // Releasing memory

    for(int i=0; i<row; i++)
    {
        delete[] arr[i];
    }
    delete []arr;

    cout << "After...\n";
    for(int j=0; j<row; j++) {
        for(int i=0; i<col; i++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    // Jagged array
    int ** jgd = new int*[6];

    jgd[0] = new int[4];
    jgd[1] = new int[14];
    jgd[2] = new int[54];
    jgd[3] = new int[1];
    jgd[4] = new int[41];
    jgd[5] = new int[12];

    return 0;
}