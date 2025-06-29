#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class A{
    public:
    int A;
};

class B:public A{

};

class C:public A{

};


int main()
{
    A obj;
    cout<<obj.A;    
    return 0;
}