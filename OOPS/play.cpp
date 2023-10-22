#include<bits/stdc++.h>
using namespace std;

class rectangle{
public:
    int l;
    int b;

    rectangle()
    {
        l=0;
        b=0;
    }

    rectangle(int x,int y)
    {
        l=x,b=y; 
    }
};

int main()
{
    rectangle r1;
    cout<<r1.l<<" "<<r1.b<<endl;


    rectangle r2(5,6);
    cout<<r2.l<<" "<<r2.b<<endl;

    return 0;
}