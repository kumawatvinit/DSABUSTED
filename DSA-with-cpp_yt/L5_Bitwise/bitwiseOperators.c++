#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 6;

    cout<<" a&b = " << (a&b) << endl;
    cout<<" a|b = " << (a|b) << endl;
    cout<<" ~a = " << (~a) << endl; 
    cout<<" a^b = "<< (a^b) << endl; //xy'+x'y

    cout<< (17>>1)<<endl;   // 17/2
    cout<< (17>>2)<<endl;   // 17/4
    cout<< (19<<1)<<endl;   // 19*2
    cout<< (19<<2)<<endl;   //19*4

    int i=7;
    cout<< (++i)<<endl; //i=8, 8
    cout<<(i++)<<endl;  //i=9, 8
    cout<<(i--)<<endl;  // i= 8,9
    cout<<(--i)<<endl;  //i=7, 7
}