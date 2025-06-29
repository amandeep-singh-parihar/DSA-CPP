#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
bool isPowerOfTwo(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return (n%2==0 && isPowerOfTwo(n/2));
}

int main()
{
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n);
    return 0;
}