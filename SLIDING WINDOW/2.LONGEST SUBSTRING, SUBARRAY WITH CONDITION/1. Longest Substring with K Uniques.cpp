#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O(N*N*N)
// SC O(26)
int _longestKSubstr(string &s, int k)
{
    int n = s.size();
    int maxLen = 0;
    for (int i = 0; i < n; ++i)
    {
        int uniqueCount = 0;
        int mp[26] = {0};
        for (int j = i; j < n; ++j)
        {
            for (int z = i; z <= j; ++z)
            {

                if (mp[s[z] - 'a'] == 0)
                    ++uniqueCount;

                mp[s[z] - 'a']++;

                if (uniqueCount == k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else if (uniqueCount > k)
                {
                    break;
                }
            }
        }
    }
    return maxLen;
}

// Better
// TC O(N*N)
// SC O(26)
int __longestKSubstr(string &s, int k)
{
    int n = s.size();
    int maxLen = 0;
    for (int i = 0; i < n; ++i)
    {
        int uniqueCount = 0;
        int mp[26] = {0};
        for (int j = i; j < n; ++j)
        {
            if (mp[s[j] - 'a'] == 0)
                ++uniqueCount;

            mp[s[j] - 'a']++;

            if (uniqueCount == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else if (uniqueCount > k)
                break;
        }
    }
    return maxLen;
}

// Optimal
// TC O(N)
// SC O(26)
int longestKSubstr(string &s, int k)
{
    int n = s.size();
    int r = 0, l = 0, maxLen = -1, uniqueCount = 0;
    int mp[26] = {0};
    while (r < n)
    {
        if (mp[s[r] - 'a'] == 0)
        {
            ++uniqueCount;
        }

        mp[s[r] - 'a']++;

        if (uniqueCount == k)
        {
            maxLen = max(maxLen, r - l + 1);
        }

        while (uniqueCount > k)
        {
            if (mp[s[l] - 'a'] == 1)
                --uniqueCount;
            mp[s[l] - 'a']--;
            ++l;
        }
        ++r;
    }
    return maxLen;
}

int main()
{
    string s = "aabacbebebe";
    int k = 3;
    // string s = "aaaa";
    // int k = 2;
    cout << _longestKSubstr(s, k);
    return 0;
}