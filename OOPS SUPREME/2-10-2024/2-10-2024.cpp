#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class Animal
{
    // state of properties
private:
    int weight;

public:
    int age;
    string name;

    // default constructor
    Animal()
    {
        this->weight = 0;
        this->name = "";
        cout << "constructor called" << endl;
    }

    // parameterised constructor
    Animal(int age)
    {
        this->age = age;
        cout << "Parameterised constructor called" << endl;
    }

    Animal(int age, string name)
    {
        this->age = age;
        this->name = name;
        cout << "para2 called" << endl;
    }

    // copy constructor
    Animal(Animal &obj)
    {
        this->age = obj.age;
        this->name = obj.name;
        cout << "I am inside the copy constructor" << endl;
    }

    // behaviour
    void eat()
    {
        cout << "Eating" << endl;
    }

    void sleep()
    {
        cout << "sleeping" << endl;
    }

    int getWeight()
    {
        return weight;
    }

    void setWeight(int weight)
    {
        this->weight = weight;
    }
};

int main()
{
    // object creation

    // static alloction
    // Animal ramesh;
    // ramesh.age = 12;
    // ramesh.name = "Lion";
    // cout << "age : " << ramesh.age << endl;
    // cout << "Name : " << ramesh.name << endl;

    // ramesh.eat();
    // ramesh.sleep();

    // ramesh.setWeight(101);

    // cout << "weight : " << ramesh.getWeight() << endl;

    // dynamic memory alloction
    // Animal *suresh = new Animal;
    // (*suresh).age = 15;
    // (*suresh).name = "billi";

    // // alternate

    // suresh->age = 17;
    // suresh->name = "doggy";

    // cout << suresh->age << endl;
    // cout << suresh->name << endl;
    // suresh->eat();
    // suresh->sleep();

    Animal a(10);
    Animal *b = new Animal(100, "what's in name");

    // object copy
    Animal c = a;

    Animal d(c);

    // cout<<"size of empty class is : "<<sizeof(Animal)<<endl;
    return 0;
}