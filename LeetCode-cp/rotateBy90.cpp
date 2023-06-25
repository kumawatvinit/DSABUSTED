#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &ans)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        for(auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "End!\n";
}


void rotateMatrixBy90(vector<vector<int>> &arr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i=0; i<n; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for(auto &i: arr)
    {
        for(auto &j: i)
        {
            cin >> j;
        }
    }

    print(arr);
    rotateMatrixBy90(arr, n);
    cout << endl << endl;
    print(arr);

    return 0;
}