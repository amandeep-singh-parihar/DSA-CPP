#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
class abc
{
    int x;
    int *y;
    const int z;

public:
    // ctor : old style
    //  abc(int a, int b, int z = 0)
    //  {
    //      x = a;
    //      y = new int(b);
    //      this->z = z;
    //  }

    // new way of writing ctor -> working same as above
    // abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z) {}
    abc(int x,int y,int z=0):x(x),y(new int(y)),z(z){};

    int getX() const
    {
        return x;
    }

    void setX(int x)
    {
        this->x = x;
    }

    int getY() const
    {
        return *y;
    }

    void setY(int _val)
    {
        *y = _val;
    }

    int getZ() const
    {
        return z;
    }

    // void setZ(int z)
    // {
    //     this->z = z;
    // }
};

int main()
{
    abc a(1,2,3);
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
    return 0;
}