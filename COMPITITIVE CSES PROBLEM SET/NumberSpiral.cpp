#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll spiral(ll y, ll x)
{
    if (y > x)
    {
        ll innerarea = (y - 1) * (y - 1);
        if (y % 2 == 0)
        {
            return (2 * y - x) + innerarea;
        }
        else
        {
            return innerarea + x;
        }
    }
    else
    {
        ll innerarea = (x - 1) * (x - 1);
        if (x % 2 == 0)
        {
            return innerarea + y;
        }
        else
        {
            return (2 * x - y) + innerarea;
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    ll y, x;
    ll output[n];

    for(ll i=0;i<n;i++)
    {
        cin>>y>>x;

        output[i]=spiral(y,x);

    }
    for(ll i=0;i<n;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}