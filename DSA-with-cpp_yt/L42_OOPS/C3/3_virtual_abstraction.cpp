#include<bits/stdc++.h>
using namespace std;

class Vehicle {
    public: 
        string color;

        virtual void print() = 0;
};
// Abstract class
// we can't make any object of this class
// since, on object creation, all properties are being initialised

class Car: public Vehicle {
    public:

    void print() {
        cout << "Car" << endl;
    }
};
/* Car class have 2 options:
    1. Implement all pure vurtual fn's
    2. Become an abstract class

*/


int main()
{
    // Vehicle v;
    // error: cannot declare variable 'v' to be of abstract type 'Vehicle'
    
    Car c;

    return 0;
}

/*
    Normal virtual fn.
    e.g.
    virtual void print() {
        ----
        ----
        ----
    }

    Pure virtual fn.
    There is no definition for this fn.
    e.g.
    virtual void print() = 0;
*/

/*
    In last class, polymorphism, we discussed this example

    // USE CASE
    salary calculation:
    Employees
    HR, Managers, Engineers, Others

    We have an array of pointer to employees,
    HR, mana.... are derived from employees

    both have calculateSalary() fn.
    so we just need to traverse only once, and we will be able to calculate salary.
    e[i]->calculateSalary();

    Here, Employees class must have calc. fn., but we don't know how to calc.,
    so we can't give definition, But in order to use calc. of derived class i.e.
    calc.() of HR or manager, we should have a same fn. in base class also, i.e. in Employees class

    So we will make calculateSalary() of base class "Pure virtual"

*/