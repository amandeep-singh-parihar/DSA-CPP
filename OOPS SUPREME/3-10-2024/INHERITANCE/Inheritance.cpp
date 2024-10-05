#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//INHERITANCE
class animal{
    public:
        int age;
        // int weight;

        // void eat()
        // {
        //     cout<<"eating"<<endl;
        // }
};

class dog:private animal{
    public:
    void print()
    {
        cout << this->age;
    }
};




int main()
{
    dog d1;
    d1.print();
    // d1.print();
    // d1.eat();
    return 0;
}