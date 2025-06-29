#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class car{
    public:
        string name;
        int weight;
        int age;

        void speedUp(){
            cout<<"Speeding up"<<endl;
        }

        void pressBreak()
        {
            cout<<"Break pressed"<<endl;
        }
};

class scorpio:public car{

};

int main()
{
    scorpio a1;
    a1.speedUp();
    return 0;
}