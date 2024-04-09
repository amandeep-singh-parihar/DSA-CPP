#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> solve(ll n)
{
    vector<ll> ans;
    ll sum=0;
    for(ll i = 1; i<=n;i++)
    {
        sum+=i;
    }
    for(ll i=n;i>=n;i--)
    {
        ans.push_back(i);
    }
    ll mid=n/2;
    
    if(n%4==0)
    {
        ll half=
    }
}

int main()
{
    
    return 0;
}