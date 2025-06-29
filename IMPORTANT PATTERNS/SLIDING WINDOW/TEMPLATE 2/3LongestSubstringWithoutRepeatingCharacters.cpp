// 3. Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute

int lengthOfLongestSubstring(string s)
{
    int len = 0;
    int maxLen = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        int mp[256] = {0};
        for (int j = i; j < s.size(); ++j)
        {
            if (mp[s[j]] == 1)
                break;

            mp[s[j]] = 1;
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

int main()
{
    string str;
    cin >> str;
    cout << lengthOfLongestSubstring(str);
    return 0;
}