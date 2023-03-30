#include<bits/stdc++.h>
using namespace std;

class polynomial {
    /*
    0 0 3 0 0 4 0 -1 -coefficient
    0 1 2 3 4 5 6 7  -degree
    3x^2 + 4x^5 - x^7
    */
   int capacity;
   int *degcoeff;

   public:

    // Default Constructor
    polynomial() {
        degcoeff = new int[10];
        capacity = 10;     

        for(int i=0; i<capacity; i++) {
         degcoeff[i] = 0;
        }
    }
    
    polynomial(int n) {
        degcoeff = new int[n];
        capacity = n;     

        for(int i=0; i<capacity; i++) {
         degcoeff[i] = 0;
        }
    }


    // Copy Constructor
    polynomial(polynomial const &p2) {
        capacity = p2.capacity;
        degcoeff = new int[capacity];

        for(int i=0; i<capacity; i++) {
            degcoeff[i] = p2.degcoeff[i];
        }
    }

    // Copy assignment operator
    polynomial operator=(polynomial const &p2) {
        capacity = p2.capacity;
        degcoeff = new int[capacity];

        for(int i=0; i<capacity; i++) {
            degcoeff[i] = p2.degcoeff[i];
        }
    }

    // print
    void print() {
        bool flag = 0;

        int i=0;
        while(i<capacity && degcoeff[i]==0) {
            i++;
        }
        if(i<capacity) {
            if(i==0) {
                cout << degcoeff[i] << " ";
            }
            else {
                if(degcoeff[i]==1 || degcoeff[i]==-1) {
                    cout << (degcoeff[i]>0?"": "-") << "x" << i << " ";
                }
                else {
                    cout << degcoeff[i] << "x" << i << " ";
                }
            }
            
            flag = 1;
        }

        for(++i; i<capacity; i++) {
            if(degcoeff[i]!=0) {
                flag = 1;

                if(degcoeff[i]==1 || degcoeff[i]==-1) {
                    cout << (degcoeff[i]>0?"+ ":"- ") << "x" << i << " ";
                }
                else 
                cout << (degcoeff[i]>0?"+ ":"- ") << abs(degcoeff[i]) << "x" << i << " ";
            }
        }

        if(flag==0) {
            cout << 0;
        }

        cout << endl;
    }

    // setCoefficient(degree, coefficient)
    // double the capacity if required
    void setcoefficient(int d, int coeff)
    {
        if(d<capacity) {
            degcoeff[d] = coeff;
        }
        else {
            int temp = capacity;

            while(d>capacity){
                int *newdeg = new int[capacity*2];
                capacity*=2;

                for(int i=0; i<temp; i++) {
                    newdeg[i] = degcoeff[i];
                }
                delete [] degcoeff;
                degcoeff = newdeg;
            }

            for(int i=temp; i<capacity; i++) {
                degcoeff[i] = 0;
            }
            degcoeff[d] = coeff;
        }
            
    }

    // +
    polynomial operator+(polynomial const &p2)
    {
        polynomial pNew(max(capacity, p2.capacity));

        for(int i=0; i<min(capacity, p2.capacity); i++)
        {
            pNew.degcoeff[i] = degcoeff[i] + p2.degcoeff[i];
        }

        if(capacity<p2.capacity) {
            for(int i=capacity; i<p2.capacity; i++) {
                pNew.degcoeff[i] = p2.degcoeff[i];
            }
        }
        else {
            for(int i=p2.capacity; i<capacity; i++) {
                pNew.degcoeff[i] = degcoeff[i];
            }
        }

        return pNew;
    }

    // -
    polynomial operator-(polynomial const &p2)
    {
        polynomial pNew(max(capacity, p2.capacity));

        for(int i=0; i<min(capacity, p2.capacity); i++)
        {
            pNew.degcoeff[i] = degcoeff[i] - p2.degcoeff[i];
        }

        if(capacity<p2.capacity) {
            for(int i=capacity; i<p2.capacity; i++) {
                pNew.degcoeff[i] = -p2.degcoeff[i];
            }
        }
        else {
            for(int i=p2.capacity; i<capacity; i++) {
                pNew.degcoeff[i] = degcoeff[i];
            }
        }

        return pNew;
    }

    // *
    polynomial operator*(polynomial const &p2)
    {
        polynomial pNew(capacity+p2.capacity);
        pNew.capacity = capacity+p2.capacity;

        for(int i=0; i<pNew.capacity; i++) {
            pNew.degcoeff[i] = 0;
        }

        for(int i=0; i<capacity; i++)
        {
            for(int j=0; j<p2.capacity; j++)
            {
                pNew.degcoeff[i+j]+= degcoeff[i]*p2.degcoeff[j];
            }
        }

        return pNew;
    }

};