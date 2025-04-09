#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void solve(string &str, int i, int j, int n)
{
    if (i > j)
        return;

    // 1 case solve
    swap(str[i], str[j]);

    // R call
    solve(str, i + 1, j - 1, n);
}

int main()
{
    string str = "peednama";
    int i = 0;
    int j = str.size() - 1;
    int n = str.size();
    solve(str, i, j, n);
    cout << str << endl;
    return 0;
}