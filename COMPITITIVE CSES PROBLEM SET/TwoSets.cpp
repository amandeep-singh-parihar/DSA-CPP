#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> solve(ll n)
{
    vector<ll> ans;
    ll sum=0;
    if(n%2==0)
    {
        cout<<"NO";
    }else{
        cout<<"YES";
        for(ll i=1;i<=n;i++)
        {
            sum+=i;
        }
        ll half=sum/2;
        for(ll i=1;i<=n;i++)
        {
            ans.push_back(i);
        }

        for(ll i=0;i<n;++i)
        {
            ans[i]
        }


    }
}

int main()
{
    
    return 0;
}