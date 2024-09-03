#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int fib(int n)
{
    if(n<0) return -1;
    if(n==1) return 0;
    if(n==2) return 1;

    int ans=fib(n-1)+fib(n-2);
    // cout<<ans<<" ";
    return ans;

}

int main()
{
    int n;
    cin>>n;
    int ans=fib(n);
    cout<<ans;
    return 0;
}