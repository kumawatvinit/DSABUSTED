#include<bits/stdc++.h>
using namespace std;
#include "C2_2_CopyConstr.cpp"

int main()
{
    char name[] = "abcd";

    Student s1(20, name);
    s1.Display();

    name[3] = 'e';
    Student s2(24, name);
    s2.Display();
    s1.Display();

    Student s3(s1);
    s1.name[0] = 'u';
    s1.Display();
    s3.Display();

    return 0;
}