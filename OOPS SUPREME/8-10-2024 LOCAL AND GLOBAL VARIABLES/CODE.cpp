#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int x=2; //GLOBAL VARIABLES

void fun(){
    int x=60;
    cout<<x<<endl;
    cout<<::x<<endl;
}

int main()
{
    ::x=4; //global x
    int x=20; //local to main() fx
    cout<<x<<endl;
    cout<<::x<<endl; //accessing global with ::

    {
        int x=50;
        {
            int x=44;
            cout<<x<<endl;
        }
        cout<<x<<endl;
        cout<<::x<<endl;
    }
    fun();
    return 0;
}