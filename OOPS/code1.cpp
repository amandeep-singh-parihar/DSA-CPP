#include <bits/stdc++.h>
using namespace std;

class hero
{

private:
    int health;

public:
    // properties of class

    hero()
    {
        cout << "constructor called" << endl;
    }

    char level;

    int getHealth()
    {
        return health;
    }

    void setHealth(int h)
    {
        health = h;
    }

    char getlevel()
    {
        return level;
    }

    void setlevel(char l)
    {
        level = l;
    }
};

int main()
{

    cout << "1st" << endl;
    hero aman;
    cout << "2nd" << endl;
    hero *h = new hero;

    // creation of object here h1 is the object of hero

    // static allocation
    // hero h1;

    // cout << "health is : " << h1.getHealth() << endl;
    // h1.setHealth(100);
    // h1.setlevel('A');
    // cout << "size is : " << sizeof(h1) << endl;
    // cout << "health is : " << h1.getHealth() << endl;
    // cout << "level is : " << h1.level << endl;

    // dynamically

    // hero *b = new hero;
    // b->setHealth(50);
    // b->setlevel('A');

    // cout << "size is : " << sizeof(*b) << endl;
    // cout << "health is : " << b->getHealth() << endl;
    // cout << "level is : " << b->getlevel() << endl;

    return 0;
}