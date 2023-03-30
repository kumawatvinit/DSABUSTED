
/* 
    (*this) is reference to current object

    Avoid  delete this;
    *delete this* will work only for dynamic allocation
    if doing *delete this* on static object, it will
    result into undefined behaviour
*/
/*
#include<iostream>
using namespace std;




class Test
{
    int x;
    int y;

    public: 
    Test(int x, int y) {this->x = x; this->y = y;}
    Test& setX(int x) {
        this->x = x; 
        return *this;
    }
    
    Test & setY(int y) {
        this->y = y;
        return *this;
    }

    void print() {
        cout<<"x: "<<this->x<<", y: "<<this->y<<endl;
    }
};

int main()
{
    
// When a reference to a local object is returned,
// the returned reference can be used to chain function
//  calls on a single object.

    Test obj1(5,6);
    obj1.print();

// CHAIN function calls
    obj1.setX(10).setY(45);
    obj1.print();


    return 0;
}
// /

#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
  int y;
public:
  Test (int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test setX(int a) { x = a; return *this; }
  Test setY(int b) { y = b; return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
  
int main()
{
  Test obj1;
  obj1.setX(10).setY(20);
  obj1.print();
  return 0;
}
*/

#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 10, int y = 20) {
    // cout<<"This constructor has been called\n"; 

    this->x = x; 
    this->y = y;
  }
  void setX(int a) { x = a; }
  void setY(int b) { y = b; }
  void destroy()  {
    // cout<<"this: "<<this<<endl;
    delete this;
    // cout<<"this: "<<this<<endl;
    // cout << "x = " << x << " y = " << y << endl;

  }

  void print() { 
    // cout<<"this: "<<this<<endl;
    cout << "x = " << x << " y = " << y << endl;
  }
};
  
int main()
{
  Test obj;
//   cout<<"&obj: "<<&obj<<endl;

  obj.destroy();
  obj.print();
  return 0;
}