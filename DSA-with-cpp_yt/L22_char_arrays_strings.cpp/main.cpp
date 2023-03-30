#include<iostream>

using namespace std;

int getlength(char name[])
{
    int i=0;

    while(name[i]!='\0') ++i;

    return i;
}

void reverse(char name[], int n)
{
    int s=0, e=n-1;

    while(s<e)
    {
        swap(name[s++], name[e--]);
    }
}

int main()
{
    char name[20];

    cout<<"Enter your name: "<<endl;
    cin>>name;

    cout<<"Your name is "<<name<<endl;

    int len = getlength(name);

    cout<<"Length: "<<len<<endl;

    reverse(name,len);
    cout<<"Reversed name: "<<name<<endl;

    return 0;
}