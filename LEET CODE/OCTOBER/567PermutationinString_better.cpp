//567. Permutation in String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool checkInclusion(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    if (n > m)
    {
        return false;
    }

    sort(s1.begin(), s1.end());
    for (int i = 0; i <= m - n; ++i)
    {
        string substring = s2.substr(i, n);
        sort(substring.begin(), substring.end());
        if (s1 == substring)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkInclusion(s1, s2);
    cout << endl;
    return 0;
}
// T.C : O(m-n)*nlongn
// S.C : O(n)