#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll TwoKnights(ll n)
{
    ll totalcombi = ((n * n) * (n * n - 1)) / 2; // total number of placing two knights
    ll attacks = 4 * (n - 1) * (n - 2);          // they can only attack in a 2*3 or 3*2 box
    return totalcombi - attacks;
}

int main()
{
    ll k;
    cin >> k;
    for (ll i = 1; i <= k; i++)
    {
        cout << TwoKnights(i) << endl;
    }

    return 0;
}