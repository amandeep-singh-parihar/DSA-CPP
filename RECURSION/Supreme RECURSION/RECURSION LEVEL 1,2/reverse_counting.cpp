#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 2
void print(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";

    print(n - 1);
}

int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}