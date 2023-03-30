#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{

    vector<int> v;    
    
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    for(auto i:v) cout<<i<<" "; cout<<endl;

    // Element present Or not
    cout<<"Finding 6: "<<binary_search(v.begin(),v.end(),6)<<endl;

    cout<<"lower_bound: "<<lower_bound(v.begin(), v.end(), 6)-v.begin()<<endl;
    cout<<"upper_bound: "<<upper_bound(v.begin(), v.end(), 6)-v.begin()<<endl;

    int a=3, b=5;
    cout<<"max: "<<max(a,b)<<", min: "<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a: "<<a<<", b: "<<b<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());

    cout<<abcd<<endl;

    rotate(v.begin(),v.begin()+1, v.end());

    for(auto i:v) cout<<i<<" "; cout<<endl;

    sort(v.begin(), v.end());
/*
    Based on INTROSORT
                ||
                \/
    Combination of QUICK Sort, HEAP sort and INSERTION sort
*/
    for(auto i:v) cout<<i<<" "; cout<<endl;

    return 0;
}