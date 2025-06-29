#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

char findKthBit(int n, int k)
{
    if (n == 1)
    {
        return '0';
    }

    int l = (1 << n) - 1;
    if (k < ceil(l / 2.0))
    {
        return findKthBit(n - 1, k);
    }
    else if (k == ceil(l / 2.0))
    {
        return '1';
    }
    else
    {
        char ch = findKthBit(n - 1, l - (k - 1));
        return (ch == '0') ? '1' : '0';
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << findKthBit(n, k);
    return 0;
}