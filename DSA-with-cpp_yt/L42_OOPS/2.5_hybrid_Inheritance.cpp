#include<iostream>
using namespace std;

class A {
    public:
    void funcA() {
        cout << "Inside class A\n";
    }
};

class B: public A {
    public:
    void funcB() {
        cout << "Inside class B\n";
    }
};

class D {
    public:
    void funcD() {
        cout << "Inside class D\n";
    }
};

class C: public A, public D {
    public:
    void funcC() {
        cout << "Inside class C\n";
    }
};

int main()
{
    A obj1;
    obj1.funcA();

    B obj2;
    obj2.funcA();
    obj2.funcB();

    D obj4;
    obj4.funcD();

    C obj3;
    obj3.funcA();
    obj3.funcC();
    obj3.funcD();

    return 0;
}