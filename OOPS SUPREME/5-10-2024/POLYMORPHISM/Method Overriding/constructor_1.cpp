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
        animal()
        {
            cout<<"Inside animal construtor"<<endl;
        }
};

class dog:public animal{
    public:
        dog()
        {
            cout<<"Inside dog constructor"<<endl;
        }
};

int main()
{
    dog* a=(dog*)new animal();
    return 0;
}