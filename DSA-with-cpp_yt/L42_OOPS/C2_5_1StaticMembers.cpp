#include<bits/stdc++.h>
using namespace std;

class Student {

    public: 

    int rollNumber;
    int age;

    static int totalStudents;   // Total number of students present

    Student() {
        totalStudents++;
    }

    // Static function
    static int getTotalStudents() {
        return totalStudents;
    }
    /*
        Can only access static properties(static data members and static functions)
        'this' keyword nhi hota
    */
};

// Initialize static data members
int Student :: totalStudents = 0; 

// :: Scope resolution operator
// Static members belongs to class, not objects
// Means that member is not dependent on object
