#include <iostream>
using namespace std;

int main()
{
    int a=3;
    cout<<a<<endl;

    if(true)
    {
        cout<<a<<endl;
        int a=5;
        cout<<a<<endl;
        int b=6;
        cout<<b<<endl;
    }
    cout<<a<<endl;
    // cout<<b<<endl;
    // can't use 
    // Also can't redeclare in same block
    // changed
}