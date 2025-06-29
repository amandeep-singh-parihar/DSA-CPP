#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision needed
void solve(vector<int> &v, int &n, int &res, int currNum)
{
    if (currNum == n + 1)
    {
        ++res;
        return;
    }
#pragma unroll
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0))
        {
            v[i] = currNum;
            solve(v, n, res, currNum + 1);
            v[i] = 0;
        }
    }
}
int countArrangement(int n)
{
    vector<int> v(n + 1);
    int res = 0;
    solve(v, n, res, 1);
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout<<countArrangement(n);
    return 0;
}