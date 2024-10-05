#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class animal{
    public:
        void speak()
        {
            cout<<"Speaking"<<endl;
        }
};

//overriding
class dog:public animal{
    public:
        void speak()
        {
            cout<<"Barking"<<endl;
        }
};

int main()
{
    dog d;
    d.speak();
    return 0;
}