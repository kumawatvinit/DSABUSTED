#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int,string> m;

    m[1] = "babbar";
    m[21] = "love";
    m[13] = "kumar";

    m.insert({5,"bheem"});

    cout<<"Before erase\n";

    for(auto i:m)
    cout<<i.first<<" "<<i.second<<endl;

    cout<<"finding 13 : "<<m.count(13)<<endl; // 0 Or 1

    m.erase(13);
    cout<<"After erasing 13\n";

    for(auto i:m)
    cout<<i.first<<" "<<i.second<<endl;
    return 0;
}