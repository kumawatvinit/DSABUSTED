#include<iostream>
#include<typeinfo>

using namespace std;

void (*f[10])(int, int);

void func1(int a, int b)
{
    cout<<"func1 = "<<a<<", "<<b<<endl;
}
void func2(int a, int b)
{
    cout<<"func2 = "<<a<<", "<<b<<endl;
}
void func3(int a, int b)
{
    cout<<"func3 = "<<a<<", "<<b<<endl;
}

int main()
{
    f[0] = func1;
    // cout<<typeid(*f[0]).name()<<endl;
    f[1] = func2;
    f[2] = func3;

    (*f[0])(1,2);
    (*f[1])(3,4);
    (*f[2])(5,6);

    return 0;
}