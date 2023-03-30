#include <bits/stdc++.h>
using namespace std;

class Bus
{
public:
    void print();
};

void Test();

class Truck
{
private:
    int x;

protected:
    int y;

public:
    int z;

    /*
    friend void Bus ::print();
    // Friend don't have access to "this" pointer, since they are not member of class
    
    */
    friend void Test();
    

    friend class Bus;

};

void Bus::print()
{
    Truck t;
    t.x = 10;
    t.y = 20;

    cout << t.x << " " << t.y << endl;
}

void Test() {
    // Access truck private

    Truck t;
    t.x = 11;
    t.y = 26;

    cout << "In Test: " << t.x << " " << t.y << endl;
}

int main()
{
    Bus b;

    b.print();

    Test();

    return 0;
}