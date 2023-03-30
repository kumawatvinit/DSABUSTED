#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vect{10, 12, 43, 23};

    for(auto i: vect)
    i+=1;

    for(const auto i: vect)
    cout<<i<<endl;

    for(auto &i: vect)
    i+=2;

    for(const auto i: vect)
    cout<<i<<endl;

    return 0;
}