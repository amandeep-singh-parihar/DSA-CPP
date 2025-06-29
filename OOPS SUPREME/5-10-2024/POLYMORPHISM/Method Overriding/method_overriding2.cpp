//UPCASTING UPCASTING UPCASTING UPCASTING
//UPCASTING UPCASTING UPCASTING UPCASTING
//UPCASTING UPCASTING UPCASTING UPCASTING
//UPCASTING UPCASTING UPCASTING UPCASTING
//UPCASTING UPCASTING UPCASTING UPCASTING
//UPCASTING UPCASTING UPCASTING UPCASTING
//UPCASTING UPCASTING UPCASTING UPCASTING
//UPCASTING UPCASTING UPCASTING UPCASTING

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
        cout<<"speaking"<<endl;
    }
};

class dog:public animal{
    public:
        void speak()
        {
            cout<<"Barking"<<endl;
        }
};


int main()
{
    // animal* a=new animal();
    // a->speak();    

    // dog* d=new dog();
    // d->speak();

    //UPCASTING
    animal* a=new dog();
    a->speak();//always run the function of that which it is the pointer so here speaking will print
    //only if we don't use virtual keyword
    return 0;
}