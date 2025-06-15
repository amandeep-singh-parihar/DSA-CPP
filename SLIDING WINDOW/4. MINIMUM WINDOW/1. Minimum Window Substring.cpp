// 76. Minimum Window Substring
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

string minWindow(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int minLen = 1e9;
    int startIdx = 0;
    if (n > m)
        return "";

    for (int i = 0; i < m; ++i)
    {
        unordered_map<char, int> mp;
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            mp[t[j]]++;
        }
        for (int j = i; j < m; ++j)
        {
            if (mp[s[j]] > 0)
            {
                cnt++;
            }
            mp[s[j]]--;
            if (cnt == n)
            {
                if (j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    startIdx = i;
                    break;
                }
            }
        }
    }
    return s.substr(startIdx, minLen);
}

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t);
    return 0;
}