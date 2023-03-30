#include <iostream>
using namespace std;

int main()
{
    int a=1;
    int b=a++;  //b=1, a=2
    int c=++a;  //c=3, a=3
    cout<<b;    //13
    cout<<c;
}