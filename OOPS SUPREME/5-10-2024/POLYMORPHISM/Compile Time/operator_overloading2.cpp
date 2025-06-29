// operator overloading
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class a{
    public:
        int val;

        void operator*(a& b)
        {
            int value1=this->val;
            int value2=b.val;
            cout<<(value1+value2);
        }
};

int main()
{
    a obj1,obj2;
    obj1.val=5;
    obj2.val=10;
    obj1*obj2;
    return 0;
}