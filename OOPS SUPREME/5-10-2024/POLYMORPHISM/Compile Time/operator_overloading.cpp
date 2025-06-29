// operator overloading
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class param
{
public:
    int val;

    void operator+(param &obj2)
    {
        int value1 = this->val;
        int value2 = obj2.val;
        cout << (value1 - value2) << endl;
    }
};

int main()
{
    param a, b;
    a.val = 10;
    b.val = 5;
    a + b;
    return 0;
}