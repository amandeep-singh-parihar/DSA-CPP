#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class A
{
public:
    // int physics;
    int chemistry;
    A(){
        chemistry=101;
    }
};

class B
{
public:
    int chemistry;
    B(){
        chemistry=410;
    }
};

class C : public A, public B
{
public:
    int maths;
};

int main()
{
    C obj;
    cout << obj.B::chemistry << " " << obj.maths << " " << endl;
    return 0;
}