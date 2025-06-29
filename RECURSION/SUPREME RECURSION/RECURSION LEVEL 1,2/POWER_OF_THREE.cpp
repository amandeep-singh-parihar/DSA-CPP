#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
bool solve(int n)
{
    if(n==0) return false;
    if(n==1) return true;
    return (n%3==0 && solve(n/3));
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}