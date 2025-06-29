#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 2
bool is(int n)
{
    if(log2(n)==int(log2(n)))
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;

    cout<<is(n);
    return 0;
}