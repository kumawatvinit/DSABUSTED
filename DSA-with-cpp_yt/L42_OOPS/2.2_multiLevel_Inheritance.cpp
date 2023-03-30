#include<iostream>
using namespace std;

class Animal {
    public:
    int age;
    int weight;

    public:
    void speak() {
        cout << "Speaking " << endl;
    }
};

class Dog: public Animal {

};

class GermanShephered: public Dog {

};

int main()
{
    Dog d;
    d.speak();
    cout << d.age << endl;

    GermanShephered g;
    g.speak();
    cout << g.weight << endl;
    return 0;
}