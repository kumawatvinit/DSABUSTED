#include<iostream>
using namespace std;

class Human
{
    private:
    int age;

    

    public:
    int height;
    int weight;
    

    int getAge() {
        return this->age;
    }

    int setWeight(int w) {
        this->weight = w;
    }
};

class Male: public Human {
    public:
    string color;

    void sleep() {
        cout<< "Male sleeping" <<endl;
    }
};
class Female: protected Human {
    public:
    string color;

    void sleep() {
        cout<< "Female sleeping" <<endl;
    }
    
    int getHeight() {
        return this->height;
    }
};

class Bi: private Human {
    public:
    string color;

    void setColor(string s)
    {
        color = s;
    }
    void sleep() {
        cout<< "Bi sleeping" <<endl;
    }
    
    int getHeight() {
        return this->height;
    }
};

int main()
{
    
    Bi person;
    person.color = "Blonde";

    // person.height = 34; Not accessible
    cout << person.getHeight() << endl;
    cout << person.color << endl;
    person.setColor("White");
    cout << person.color << endl;
    person.sleep();

    /*
    Male object1;
    
    object1.setWeight(69);

    // cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;
    cout << object1.color << endl;

    object1.sleep();

    Female object2;

    cout << object2.getHeight();
    object2.sleep();
    */

    return 0;
}