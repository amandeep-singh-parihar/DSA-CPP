#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(n)
    {
        int digit=n&1;
        ans+=digit;
        n=n>>1;
    }
    cout<<n<<" ";
    return 0;
}