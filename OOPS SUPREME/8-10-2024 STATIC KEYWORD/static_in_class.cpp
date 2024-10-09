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
public:
    int x, y;

    void print() const
    {
        cout << x << " " << y << endl;
    }
};

int main()
{
    abc obj1 ={1,2};
    abc obj2={4,5};
    obj1.print();
    obj2.print();
    return 0;
}