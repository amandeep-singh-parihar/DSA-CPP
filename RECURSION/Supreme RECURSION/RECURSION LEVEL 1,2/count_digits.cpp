// count digits
#include <bits/stdc++.h>
using namespace std;

static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

int digit(int n)
{
    if (n == 0)
        return 0;

    return 1 + digit(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << digit(n);
    return 0;
}