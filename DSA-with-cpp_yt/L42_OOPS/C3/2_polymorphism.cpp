#include<bits/stdc++.h>
using namespace std;

int main()
{
    

    return 0;
}
/*
Polymorphism
1. Compile time 
    a) Function overloading
        function name same
        different number of arguments and of diff. type,
         and diff. return type

        We can't differentiate two functions by just return type
    Operator overloading

    b) Method/Function overriding
        Same function in both Base class and derived class
        e.g. 
        A(print()) -> B(print())
        Base class  -> Derived class

        All this, i.e. Which function to call is decided on compile time


        Vehicle v;
        Car c;

        v.print();
        c.print();

        Vehicle *v1 = new Vehicle;
        Vehicle *v2;
        // v2 = &v;  ALLOWED

        v2 = &c;        ALLOWED
        
        pointer of type car, can't point to obj of type Vehicle
        // Car * c2;
        // c2 = &v1     // NOT ALLOWED

            Vehicle (Base class) : print()
               |
               V
              Car (derived class) : print()

        You can only access those properties by v2, 
        which are in base class

        v2->print()  !!! It will call vehicle print(), not car one
        ALL this is decided on compile time


2. Run time

    Virtual functions
    Fn's present in base class, and overridden in derived class

    we write virtual in base class fn's

    class Vehicle {
        public:

        virtual print() {
            cout << "Vehicle" << endl;
        }
    }; 

    class Car: public Vehicle {
        public:

        print() {
            cout << "Car" << endl;
        }
    };

    Vehicle v;
    Car c;
    
    Vehicle *v2;
    v2 = &c;

    v2->print();    // Car
    // If we remove print() from Car, then
    // Output: Vehicle
    // Decided on runtime


    // If we remove print() from Vehicle, then
    // We can't access print() of Car, !!!ERROR
    // No function named print()

    // USE CASE
    salary calculation:
    Employees
    HR, Managers, Engineers, Others

    We have an array of pointer to employees,
    HR, mana.... are derived from employees

    both have calculateSalary() fn.
    so we just need to traverse only once, and we will be able to calculate salary.
    e[i]->calculateSalary();

*/