#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >>m;

    int *a = new int[m];

    for(int i=0; i<m; i++)
    cin >> a[i];

    int flag=0;

    for(int i=0; i<m; i++)
    if(a[i]==n)
    {
        flag=1;
        break;
    }

    if(flag==1) cout << "TRUE";
    else cout << "FALSE";
    
    return 0;
}