#include <iostream>
using namespace std;

int main()
{
    int a, b=1;
    a=10;
    if(++a) //a=11, if(11)
        cout<<b;
    else 
        cout<<++b;
}
