//2938. Separate Black and White Balls
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
#define ll long long

ll minimumSteps(string &s)
{
    ll count = 0;
    ll ans = 0;
    int n = s.size();
    #pragma unroll
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '0')
        {
            count++;
        }
        else
        {
            ans += count;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << minimumSteps(s);
    return 0;
}