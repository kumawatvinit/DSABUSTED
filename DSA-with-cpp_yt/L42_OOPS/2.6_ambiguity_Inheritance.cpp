#include<iostream>
using namespace std;

class A {
    public:
    void func() {
        cout << "This is in A" << endl;
    }
};

class B {
    public:
    void func() {
        cout << "This is in B" << endl;
    }
};

class C: public A, public B {
    
};

int main()
{
    C obj;

    // obj.func();
    // :: -> scope resolution operator
    
    obj.A::func();
    obj.B::func();

    return 0;
}