// 2914. Minimum Number of Changes to Make Binary String Beautiful
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int minChanges(string s)
{
    int n = s.size();
    int c = 0;
    for (int i = 0; i < n - 1; i += 2)
    {
        if (s[i] != s[i + 1])
        {
            ++c;
        }
    }
    return c;
}
int main()
{
    string str;
    cin >> str;
    cout << minChanges(str) << endl;
    return 0;
}