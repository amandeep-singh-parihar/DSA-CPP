#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class Car{
    public:
        int age;
        int weight;
            

        void speedUp(){
            cout<<"Speeding Up"<<endl;
        }
};

class Scorpio:public Car{

};

class Fortuner:public Car{

};

int main()
{
    Scorpio S11;
    S11.speedUp();

    Fortuner F11;
    F11.speedUp();
    return 0;
}