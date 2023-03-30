#include<iostream>
using namespace std;
/*
    Polymorphism:
    If one thing is existing in multiple forms.

    Two types: 
        1. Compile time polymorphism -> static polymorphism
            A. Function overloading
            B. Operator overloading
        2. Run-time polymorphism    -> Dynamic polymorphism
            Method overriding
*/

class A {
    public:

    // Function overloading
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }
    void sayHello(string name) {
        cout << "Hello" << name << endl;
    }
    int sayHello(char name) {
        cout << "Hello Love Babbar!" << endl;
        return 1;
    }
};

class B {
    public:
    int a;
    int b;

    int add() {
        return a+b;
    }

    // Operator overloading
    /*  syntax
        return_type operator which_operator (i/p)
    */
    void operator+ (B &obj) {
        int value1 = this->a;
        int value2 = obj.a;

        cout << "output " << value2-value1 << endl;
    }

    void operator() () {
        cout << "Main parenthesis hu, a: " << this->a << endl;
    }

};

class Animal {
    public:
    void speak() {
        cout << "Speaking..." << endl;
    }
};

class Dog: public Animal {
    public:
    // Method overriding
    void speak() {
        cout << "Barking..." << endl;
    }
};

int main()
{

    Dog obj;
    obj.speak();

    /*
    A obj;
    obj.sayHello();

    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj2 + obj1;
    
    obj1 () ;
    obj2() ;
    */
    return 0;
}