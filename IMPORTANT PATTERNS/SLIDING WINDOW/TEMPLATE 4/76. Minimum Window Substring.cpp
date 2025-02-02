#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute force
// TC O(N*N);
// SC O(256);
// string minWindow(string s, string t)
// {
//     int minLen = 9999999;
//     int startIdx = -1;
//     for (int i = 0; i < s.size(); ++i)
//     {
//         int mpp[256] = {0};
//         int cnt = 0;
//         for (int j = 0; j < t.size(); ++j)
//         {
//             mpp[t[j]]++;
//         }
//         for (int j = i; j < s.size(); ++j)
//         {
//             if (mpp[s[j]] > 0)
//             {
//                 cnt++;
//                 mpp[s[j]]--;
//             }
//             if (cnt == t.size())
//             {
//                 if (j - i + 1 < minLen)
//                 {
//                     minLen = j - i + 1;
//                     startIdx = i;
//                     break;
//                 }
//             }
//         }
//     }
//     return startIdx == -1 ? "" : s.substr(startIdx, minLen);
// }

string minWindow(string s, string t)
{
    int r = 0, l = 0, minLen = INT_MAX, cnt = 0, stIdx = -1;
    int mpp[256] = {0};
    for (int i = 0; i < t.size(); ++i)
    {
        mpp[t[i]]++;
    }
    while (r < s.size())
    {
        if (mpp[s[r]] > 0)
        {
            cnt++;
        }
        mpp[s[r]]--;
        while (cnt == t.size())
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                stIdx = l;
            }
            mpp[s[l]]++;
            if (mpp[s[l]] > 0)
            {
                cnt--;
            }
            ++l;
        }
        ++r;
    }
    return stIdx == -1 ? "" : s.substr(stIdx, minLen);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t);
    return 0;
}