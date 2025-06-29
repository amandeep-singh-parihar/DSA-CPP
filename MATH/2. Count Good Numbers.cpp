// 1922. Count Good Numbers
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
#define ll long long
const int M = 1e9 + 7;
ll findPower(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll half = findPower(a, b / 2);
    ll result = (half * half) % M;
    if (b % 2 == 1)
    {
        result = (result * a) % M;
    }
    return result;
}

int countGoodNumbers(long long n)
{
    return (ll)findPower(5, (n + 1) / 2) * findPower(4, n / 2) % M;
}

int main()
{
    ll n;
    cin >> n;
    cout << countGoodNumbers(n);
    return 0;
}