#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

const int MOD = 1000000007;

int numRollsToTarget(int n, int k, int target)
{
    if (target < 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    if (n == 0 && target != 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;

    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        ans = ans + numRollsToTarget(n - 1, k, target - i);
    }
    return ans % MOD;
}

int main()
{
    int n,k,target;
    cin>>n>>k>>target;
    cout<<numRollsToTarget(n,k,target);
    return 0;
}