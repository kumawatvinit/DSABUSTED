#include<bits/stdc++.h>
using namespace std;

class Student {
    int age;

    public:
    char *name;
    
    Student(int age, char *name)
    {
        this->age = age;
        // Shallow copy
        this->name = name;


        // Deep copy
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }

    // Student(Student s)
    // copy constructor called, s1 of main is being copied in here s!
    // But default copy constructor is not accessible now, when we defined our own.
    // Stucked in infinite loop, trying to shallow copy by default const. that doesn't exist,
    // so it will call our copy const. only, again n again, and everytime trying to make
    // a copy of s1 of main.

    Student (Student const &s)
    {
        this->age = s.age;
        this->name = new char[strlen(s.name)+1];

        strcpy(this->name, s.name);
    }

    void Display()
    {
        cout << name << " " << age << endl;
    }
};