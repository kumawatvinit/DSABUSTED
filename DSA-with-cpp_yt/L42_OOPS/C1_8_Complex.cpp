#include<bits/stdc++.h>
using namespace std;

class ComplexNumbers
{
    private: 
    int real;
    int imaginary;

    public:
    ComplexNumbers(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void print()
    {
        cout << this->real << " + " << this->imaginary << "i" << endl;
    }

    void plus(ComplexNumbers const &c2)
    {
        this->real = this->real + c2.real;
        this->imaginary = this->imaginary + c2.imaginary;

        print();
    }

    void multiply(ComplexNumbers const &c2)
    {
        int temp = this->real*c2.real - this->imaginary*c2.imaginary;
        this->imaginary = this->real*c2.imaginary + this->imaginary*c2.real;

        this->real = temp;
        print();
    }
};
