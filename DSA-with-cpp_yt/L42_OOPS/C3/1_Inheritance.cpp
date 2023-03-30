#include<bits/stdc++.h>
using namespace std;

class Vehicle {
    private:
        int maxspeed;

    protected:
        int numTyres;
    
    public: 
        string color;

    Vehicle() {
        cout << "Vehicle's default constructor " << endl;
    }   

    Vehicle(int z) {
        maxspeed = z;
        cout << "Vehicle's parameterized constructor, " << z << endl;
    }  

    ~Vehicle() {
        cout << "Vehicle's destructor " << endl;
    }   

    void print() {
        cout << "Vehicle's print!" << endl;
    }
};

class Car: virtual public Vehicle {
    public:
        int numGears;
    // numTyres, color accessible here
    // maxspeed not accessible

    void print() {
        cout << "Car properties: " << endl;
        cout << "Numtyres: " << numTyres << endl;
        cout << "Color: " << color << endl;
        // cout << "Max speed: " << maxspeed << endl;
        cout << "Num gears: " << numGears << endl;
    }

    // If we want to call some other function first, 
    // before executing the current function, then
    //  we use initialiser list.
    // In inheritance, this is automatically called 
    // when a object of child class is created
    Car(): Vehicle(3) {
        cout << "Car's default constructor " << endl;
    }
    // Car(){
    //     cout << "Car's default constructor " << endl;
    // }

    Car(int x) : Vehicle(x) {
        cout << "Car's parameterised constructor, " << x << endl;
    }
    
    Car(int x, int y) : Vehicle(y) {
        cout << "Car's double parameterised constructor, " << x << y << endl;
        numGears = x;
    }

    ~Car() {
        cout << "Car's destructor " << endl;
    }
        
};

// color, numGears accessible here

class HondaCity: public Car {
    public:

        HondaCity() {
            cout << "Honda city constructor " << endl;
        }

        HondaCity(int a) : Car(a) {
            cout << "Honda city parameterised constructor, " << a << endl;
        }

        HondaCity(int a, int b) : Car(a, b) {
            cout << "Honda city double parameterised constructor, " << a << b << endl;
        }

        ~HondaCity() {
            cout << "Honda city destructor " << endl;
        }
};

class Truck: virtual public Vehicle {
    public:
        int weightLimit;

        // Truck() {
        //     cout << "Truck's constructor" << endl;
        // }
        Truck(): Vehicle(4) {
            cout << "Truck's constructor" << endl;
        }
        void print() {
            cout << "Truck properties!" << endl;
        }
};

class Bus : public Car, public Truck {
    public:

        // Bus() {
        //     cout << "Bus's constructor" << endl;
        // }

        Bus(): Vehicle(5) {
            cout << "Bus's constructor" << endl;
        }
        // After using VIRTUAL
        // Bus will directly call vehicle constructor, 
        // When Car and Truck calling Vehicle(3) and Vehicle(4)
        // However, Bus calling Vehicle(5)
        // And Vehicle(5) only executing

        void print() {
            cout << "Bus print!" << endl;
        }
};

class Teacher {
    public:
        string name;
        int age;

        Teacher() {
            cout << "Teacher's constructor" << endl;
        }

        void print() {
            cout << "Teacher" << endl;
        }
};

class Student {
    public:
        string name;

        Student() {
            cout << "Student's constructor" << endl;
        }

        void print() {
            cout << "Student: " << name << endl;
        }
};

class TA: public Teacher, public Student {
    public:
        
        TA() {
            cout << "TA's constructor" << endl;
        }

        void print() {
            cout << "TA" << endl;
        }
}; 

int main()
{
    /*
    Vehicle v;
    v.color = "Blue";
    // v.maxspeed = 100;    -private
    // v.numTyres = 4;      -protected(Can only be accessed by class itself Or derived classes)


    Car c;
    c.color = "Black";
    c.numGears = 5;
    // c.numTyres = 4;      -protected
    c.print();

    Car d(5);
    */  

    // HondaCity h(7);
    // HondaCity object(5,9);

/*
    TA t;
    t.print();
    t.Student :: print();
    t.Teacher :: print();
    // t.name = "abcd";     -error
    t.Student :: name = "abcd";
    t.Student :: print();
*/

    Bus b;
    cout << "------------" << endl;
    b.print();   // -error, vehicle, car, truck all have print, So
    // error: request for member 'print' is ambiguous

    cout << "------------" << endl;
    b.Car :: print();
    cout << "------------" << endl;
    b.Truck :: print();
    cout << "------------" << endl;

    return 0;
}

