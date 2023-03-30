#include<bits/stdc++.h>
using namespace std;

class Student {
    public:

        int age;
        // If we initialise rollNumber here itself, then it will be same for all
        // Objects of this class, but we want unique for each object.
        const int rollNumber;
        int &x;     // age reference variable

        Student(int r, int age): rollNumber(r), age(age), x(this->age) {
            // Here we can't use 'this', cuz it's clear, inside one is value
            // and outside one is of current object! 
            // rollNumber = r;
        }
        // Constructor and Initialisation list is must, if there are any const data members

        void print()
        {
            cout << "age: " << age << endl << "RollNumber: " << rollNumber << endl << "x: " << x << endl;
        }

};