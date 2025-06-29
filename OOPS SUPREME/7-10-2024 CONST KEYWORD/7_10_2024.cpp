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
    int z;

public:
    // abc()
    // {
    //     x = 0;
    //     y = new int(0);
    // }

    abc(int a, int b, int z = 0)
    {
        x = a;
        y = new int(b);
        this->z = z;
    }

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

    void setZ(int z)
    {
        this->z = z;
    }
};

void printABC(const abc &a)
{
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}

int main()
{
    abc a(1, 2);
    printABC(a);
    // cout<<a.getX()<<endl;
    // cout<<a.getY()<<endl;
}

int main2()
{
    // const int x=5;
    // cout<<x;

    // 2 . const with pointers
    //  const int *a = new int(2); // CONST data,NON-CONST pointer.
    //  // int const *a=new int(2) // this is same as line 15
    //  cout<<*a<<endl;
    // delete a;
    //  int b=20;
    //  a=&b; //pointer itself can be reassigned
    //  cout<<*a<<endl;

    // CONST pointer but NON-CONST data;
    // int *const a = new int(2);
    // cout << *a << endl;
    // *a = 20;
    // cout << *a << endl;

    // CONST pointer, CONST data
    //  const int *const a=new int(10);
    //  cout<<*a<<endl;
    //  *a=50;//nahi chalega
    //  int b=100;
    //  a=&b;

    return 0;
}