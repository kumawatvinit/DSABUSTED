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

    void Display()
    {
        cout << name << " " << age << endl;
    }
};