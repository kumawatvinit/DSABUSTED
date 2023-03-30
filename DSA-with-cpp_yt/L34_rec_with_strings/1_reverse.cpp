#include<iostream>
using namespace std;

void reverse(string& s, int i, int j)
{
    if(i<j) {
        swap(s[i],s[j]);
        reverse(s,i+1,j-1);
    }
}

// Using single pointer
void reverse2(string& s, int p)
{
    int n = s.size();
    if(p<n/2)
    {
        swap(s[p],s[n-p-1]);
        reverse2(s,p+1);
    }
}

int main()
{
    string temp = "abcde";
    reverse(temp, 0, 4);

    cout << temp << endl;

    reverse2(temp,0);
    cout << temp << endl;

    temp+="f";
    reverse2(temp,0);
    cout << temp << endl;

    reverse2(temp,0);
    cout << temp << endl;
    return 0;
}