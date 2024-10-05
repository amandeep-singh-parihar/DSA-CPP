//DOWNCASTING DOWNCASTING DOWNCASTING DOWNCASTING
//DOWNCASTING DOWNCASTING DOWNCASTING DOWNCASTING
//DOWNCASTING DOWNCASTING DOWNCASTING DOWNCASTING
//DOWNCASTING DOWNCASTING DOWNCASTING DOWNCASTING
//DOWNCASTING DOWNCASTING DOWNCASTING DOWNCASTING
//DOWNCASTING DOWNCASTING DOWNCASTING DOWNCASTING
//DOWNCASTING DOWNCASTING DOWNCASTING DOWNCASTING
//DOWNCASTING DOWNCASTING DOWNCASTING DOWNCASTING

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

class dog:public animal
{
    public:
        void speak()
        {
            cout<<"Barking"<<endl;
        }  
};

int main()
{
    //downcasting
    dog* d=(dog*)new animal();
    d->speak();//always run the function of that which it is the pointer so here barking will print
    //only if we don't use virtual keyword
    return 0;
}