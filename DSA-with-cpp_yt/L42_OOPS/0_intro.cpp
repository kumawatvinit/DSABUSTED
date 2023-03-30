#include<iostream>
#include<string.h>
using namespace std;

class Hero
{
private:
    int health;
public:
    // int height;
    char *name;
    char level;
    static int timeToComplete;

    Hero();
    // void print() {
    //     cout<<level<<endl;
    // }
    ~Hero();

    int getHealth() {
        return health;
    }

    void setHealth(int h) {
        health = h;
    }

    char getLevel() {
        return level;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char ch[]) {
        strcpy(this->name, ch);
    }

    // Parameterised constructor 
    Hero(int health)
    {
        // cout<<"this-> "<<this<<endl;
        name = new char[100];
        this->health = health;
    }
    Hero(int health, char level)
    {
        // cout<<"this-> "<<this<<endl;
        name = new char[100];
        this->health = health;
        this->level = level;
    }
    static int random() {
        return timeToComplete;
    }
// Note: Once we create our own constructor,
// then default (built-in) constructor die automatically

    void print();

    // Copy constructor 
    Hero(Hero &temp)
    {
        cout<<"Custom copy constructor called!"<<endl;
        char *ch = new char[strlen(temp.name) + 1];

        strcpy(ch, temp.name);
        this->name = ch;

        this->health = temp.health;
        this->level = temp.level;
    }
    // Default copy constructor died
};

int Hero::timeToComplete = 5;

Hero::Hero()
{
    
    // cout<<"constructor called"<<endl;
    name = new char[100];
}

Hero::~Hero()
{
    cout<<"Destructor bhai has been called\n";
}

void Hero::print() 
{
    cout<<"[ Name: "<<this->name<<", ";
    cout<<"Health: "<<this->health<<", ";
    cout<<"Level: "<<this->level<<" ]"<<endl;
    
}

int main()
{

    cout<< Hero::timeToComplete <<endl;
    cout<< Hero::random() <<endl;







  /*  // static allocation
    Hero a;
    // Destructor will be called automatically

    // Dynamic allocation
    Hero *b = new Hero();
    // For dynamic, we have to manually call destructor 
    delete b;






    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    hero1.print();

    Hero hero2(24, 'M');
    char new_name[] = "Love";
    hero2.setName(new_name);
    hero2.print();

    // hero1.name[0] = 'G';
    hero2 = hero1;
    
    hero1.print();
    hero2.print();


    Hero suresh(70, 'C');

    Hero ritesh(suresh);


    ritesh.print();
    Hero ramesh(12);    //Constructor called!

    cout<<"Size: "<<sizeof(ramesh)<<endl;

//    Size: 1(if no variables in hero i.e. Empty class)
//      for identification of class, it has been given 1 byte
//     *Size: 4(int height)
    

   cout<<&ramesh<<endl;
//    ramesh.setHealth(87);
   ramesh.level = 'A';

   cout<<"Ramesh health is: "<<ramesh.getHealth()<<endl;
   cout<<"Ramesh level is: "<<ramesh.level<<endl;

   Hero *h = new Hero(34, 'Z');  //Constructor called!

//    h->setHealth(90);
//    h->setLevel('B');
   cout<<"Ramesh health is: "<<(*h).getHealth()<<endl;
   cout<<"Ramesh level is: "<<h->level<<endl;
*/
    return 0;
}