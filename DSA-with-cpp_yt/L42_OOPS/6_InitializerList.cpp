/*
    Situations where initialization of data members inside 
    constructor doesn’t work and Initializer List must be used

    1) For initialization of non-static const data members:
        Cuz no memory is allocated separately for const data member
    2) For initialization of reference members: 
    3) For initialization of member objects which do not have 
    default constructor:
        OR 4) For initialization of base class members : 

        
        #include <iostream>
        using namespace std;

        class A {
        int i;
        public:
        A(int );
        };

        A::A(int arg) {
        i = arg;
        cout << "A's Constructor called: Value of i: " << i << endl;
        }

        // Class B contains object of A
        class B {
        A a;
        public:
        B(int );
        };

        B::B(int x):a(x) { //Initializer list must be used
        cout << "B's Constructor called";
        }

        int main() {
        B obj(10);
        return 0;
}    
    5) When constructor’s parameter name is same as data member
        data member must be initialized either using 
        this pointer or Initializer List
    
    6) For Performance reasons: 
    It is better to initialize all class variables in Initializer List
     instead of assigning values inside body.
*/

#include<iostream>
using namespace std;

class Point
{
    int x;
    int y;

    public:

    // Point(int i=0, int j=0) {
    //     x = i;
    //     y = j;
    // }

    Point(int i=0, int j=0): x(i), y(j) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

int main()
{
    Point temp;

    cout << "x: " << temp.getX()<<endl;
    cout << "y: " << temp.getY()<<endl;


    Point temp2(12, 35);

    cout << "x: " << temp2.getX()<<endl;
    cout << "y: " << temp2.getY()<<endl;
    
    return 0;
}