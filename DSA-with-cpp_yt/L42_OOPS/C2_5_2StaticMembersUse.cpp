#include<bits/stdc++.h>
using namespace std;
#include "C2_5_1StaticMembers.cpp"

int main()
{
    cout << Student :: totalStudents << endl;
    Student s;


    // We should not do this, logically incorrect
    cout << ++s.totalStudents <<endl;

    s.totalStudents = 20;
    Student s1;
    cout << s1.totalStudents << endl;
    Student s2;
    Student s3;
    
    cout << Student :: totalStudents << endl;

    // Static function
    cout << Student :: getTotalStudents() << endl;
    return 0;
}