#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class abc{
    public:
    int x;
    int *y;

    abc(int _x,int _y):x(_x),y(new int (_y)){}

    void print() const{
        printf("X: %d\nPTR Y:%p\nContent of Y (*y):%d\n",x,y,*y);
    }
};

int main()
{
    abc a(1,2);
    a.print();

    abc b=a;
    b.print();
    return 0;
}