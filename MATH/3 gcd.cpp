#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int findGCD(int a, int b)
{
    if (b == 0)
        return a;

    return findGCD(b, a % b);
}

int main()
{
    // find the gcd of two
    int a, b;
    cin >> a >> b;
    cout << findGCD(a, b) << endl;
    /*
    a*b/GCD = lcm
    */
    return 0;
}