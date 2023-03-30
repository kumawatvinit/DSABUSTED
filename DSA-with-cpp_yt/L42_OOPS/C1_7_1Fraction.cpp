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

    void add(fraction const &f2) 
    {
        int lcm = this->denominator*f2.denominator;

        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = x*this->numerator + y*f2.numerator;

        this->numerator = num;
        this->denominator = lcm;

        simplify();
    }

    void multiply(fraction const &f2)
    {
        this->numerator = this->numerator * f2.numerator;
        this->denominator = this->denominator*f2.denominator;

        simplify();
    }
};
