#include<iostream>
using namespace std;

int apowerb(int a, int b)
{
    if(b<1) {
        return 1;
    }
    
    int temp = apowerb(a,b/2);
    if(b%2) 
    {
        return a*temp*temp;
    }
    return temp*temp;
}

int main()
{
    cout << apowerb(2,5) << endl;
    cout << apowerb(7,3) << endl;
    cout << apowerb(3,6) << endl;
    cout << apowerb(3,11) << endl;

    return 0;
}