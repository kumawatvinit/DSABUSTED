#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream x;
    ofstream o;

    o.open("input.txt");
    char ch = 65;

    o << ch;


    o.close();

    x.open("input.txt");
    cout << !(x.fail());

    x.close();

    cout << " " << x.fail();
    return 0;
}