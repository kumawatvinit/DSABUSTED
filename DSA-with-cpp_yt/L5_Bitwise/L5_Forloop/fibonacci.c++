#include <iostream>
using namespace std;

int main()
{
    // 0,1,1,2,3,5,8,13,21,....
    int a=0, b=1,c=0;
    int n=10;

    cout<<a<<" "<<b<< " ";
    for(int i=1; i<=10; i++)
    {
        c=a+b;
        cout<<c<<" ";
        a=b; b=c;
    }
}