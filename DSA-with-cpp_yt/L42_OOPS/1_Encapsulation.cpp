#include<iostream>
using namespace std;

// Read only class student
class Student
{
private:
    string name;
    int age;
    int height;
    // All Data Members are private
    // => Encapsulation acheived

public:
    int getAge() {
        return this->age;
    }
};

int main()
{
    Student first;

    cout<< "Sab sahi chal raha hai bhaiya"<<endl;

    return 0;
}