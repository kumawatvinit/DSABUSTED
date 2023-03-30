#include<iostream>
using namespace std;

void rowWiseSum(int arr[][4], int row, int col)
{
    for(int i=0; i<3; ++i)
    {
        int sum=0;
        for(int j=0; j<4; ++j)
        {
            sum+=arr[i][j];
        }

        cout << "Sum of row " << i+1 << " : " << sum << endl;
    }
}

void colWiseSum(int arr[][4], int row, int col)
{
    for(int j=0; j<4; ++j)
    {
        int sum=0;
        for(int i=0; i<3; ++i)
        {
            sum+=arr[i][j];
        }

        cout << "Sum of col " << j+1 << " : " << sum << endl;
    }
}

void LargestRowSum(int arr[][4], int row, int col)
{
    int max = INT32_MIN;
    int index = 0;
    for(int i=0; i<3; ++i)
    {
        int sum = 0;
        for(int j=0; j<4; ++j)
        {
            sum+=arr[i][j];
        }
        if(sum > max)
        {
            index = i;
            max = sum;
        }
    }
    cout << "Maximum row sum : " << max << ", at index : " << index << endl;
}


int main()
{
    int arr[3][4];

    cout << "Enter elements :" << endl;

    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            cin >> arr[i][j];
        }
    }

    // rowWiseSum(arr, 3, 4);
    LargestRowSum(arr, 3, 4);
    return 0;
}