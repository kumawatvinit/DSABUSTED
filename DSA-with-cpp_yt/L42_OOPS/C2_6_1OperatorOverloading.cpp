#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while(b!=0)
    {
        if(a<b) {
            swap(a,b);
        }
        int temp = a;
        a = b;
        b = temp%b;
    }

    return a;
}

class fraction {
    private:
    int numerator;
    int denominator;

    public:

    fraction() {
        
    }

    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int n) {
        numerator = n;
    }

    void setDenominator(int d) {
        denominator = d;
    }

    void print() const
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    void simplify()
    {
        int tmp = gcd(this->numerator, this->denominator);
        
        this->numerator = this->numerator/tmp;
        this->denominator = this->denominator/tmp;
    }

    fraction add(fraction const &f2) 
    {
        int lcm = this->denominator*f2.denominator;

        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = x*this->numerator + y*f2.numerator;

        fraction fNew(num, lcm);
        fNew.simplify();

        return fNew;
    }

    fraction operator+(fraction const &f2) const
    {
        int lcm = this->denominator*f2.denominator;

        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = x*this->numerator + y*f2.numerator;

        fraction fNew(num, lcm);
        fNew.simplify();

        return fNew;
    }

    void multiply(fraction const &f2) 
    {
        this->numerator = this->numerator * f2.numerator;
        this->denominator = this->denominator*f2.denominator;

        simplify();
    }

    fraction operator*(fraction const &f2) const
    {
        int num = this->numerator * f2.numerator;
        int den = this->denominator*f2.denominator;

        fraction fNew(num, den);
        fNew.simplify();

        return fNew;
    }

    bool operator==(fraction const &f2) const
    {
        return this->numerator==f2.numerator && this->denominator==f2.denominator;
    }

    // Pre-increment
    fraction& operator++()
    {
        this->numerator = this->numerator + this->denominator;
        simplify();

        return *this;
    }

    // Post-increment
    fraction operator++(int)
    {
        fraction fNew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();

        return fNew;
    }

    fraction& operator+=(fraction const &f2)
    {
        int lcm = this->denominator*f2.denominator;

        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = x*this->numerator + y*f2.numerator;

        numerator = num;
        denominator = lcm;

        simplify();

        return *this;
    }
};
