#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class maths
{
public:
    int sum(int a, int b)
    {
        cout << "I am inside the first signature : ";
        return a + b;
    }

    int sum(int x, int y, int z)
    {
        cout << "I am inside the second signature : ";

        return x + y + z;
    }

    int sum(int a, float b)
    {
        cout << "I am inside the third signature : ";

        return a + b;
    }
};

int main()
{
    maths obj;
    cout << obj.sum(1, 1)<<endl;
    cout << obj.sum(1, 1, 1)<<endl;
    cout<<obj.sum(1,2.5f);
    return 0;
}