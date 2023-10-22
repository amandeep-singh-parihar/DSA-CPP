#include <bits/stdc++.h>
using namespace std;

class tenth
{

private:
    int rollnumber;
    string name;
    int kaksha;

public:
    int get_rollnumber()
    {
        return rollnumber;
    }

    string get_name()
    {
        return name;
    }

    int get_kaksha()
    {
        return kaksha;
    }

    void set_rollnumber(int r)
    {
        rollnumber = r;
    }

    void set_name(string n)
    {
        name = n;
    }

    void set_kaksha(int k)
    {
        kaksha = k;
    }

    tenth(){
        cout<<"simple constructor"<<endl;
    }
    //parameterised constructor

    tenth(int rollnumber, string name)
    {
        this->name = name;
        this->rollnumber = rollnumber;
        
    }

    void print()
    {
        cout<<"the rollnumber "<<this->rollnumber<<endl;
        cout<<"the name "<<this->name<<endl;
    }

    tenth(tenth& abhay)
    {
        cout<<"yes this is working"<<endl;
        //this-> is the member name of class
        this->name=abhay.name;
        this->rollnumber=abhay.rollnumber;
    }

};

int main()
{
    // tenth t;
    // cout << "size : " << sizeof(tenth) << endl;

    // tenth *ten = new tenth;

    tenth temp(5,"amandeep singh parihar");
    tenth newtemp(temp); //this is copy constructor
    newtemp.print();

    // tenth what;
    // what.print();


    // ten->rollnumber=14;
    // ten->name="amandeep";
    // ten->kaksha=10;

    // cout<<"rollnumber : "<<ten->rollnumber<<endl;
    // cout<<"name : "<<ten->name<<endl;
    // cout<<"kaksha : "<<ten->kaksha<<endl;

    // ten->set_rollnumber(5);
    // ten->set_name("amandeep");
    // ten->set_kaksha(10);

    // cout << "rollnumber : " << ten->get_rollnumber() << endl;
    // cout << "name : " << ten->get_name() << endl;
    // cout << "kaksha : " << ten->get_kaksha() << endl;

    return 0;
}