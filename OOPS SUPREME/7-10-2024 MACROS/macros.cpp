#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

#define pi 3.14159265359
#define MAXX(x,y)(x>y?x:y)
#define Flo float

Flo circleArea(Flo r){
    return pi*r*r;
}

Flo peri(Flo r){
    return 2*pi*r;
}

void fun()
{
    int x=6;
    int b=17;
    int c=MAXX(x,b);
}

void fun2()
{
    int c=6;
    int d=17;
    int r=MAXX(c,d);
}

void fun3()
{
    int q=6;
    int w=17;
    int e=MAXX(q,w);
}

int main()
{
    cout<<circleArea(1)<<endl;
    cout<<peri(1)<<endl;
    return 0;
}