// 3. Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Optimal
// TC O(N)
// SC O(256)

int lengthOfLongestSubstring(string s)
{
    int hashmap[256];
    memset(hashmap, -1, sizeof(hashmap)); // setting all elements to -1;
    int l = 0, r = 0;
    int maxLen = 0;
    while (r < s.size())
    {
        if (hashmap[s[r]] != -1 && hashmap[s[r]] >= l)
        {
            l = hashmap[s[r]] + 1;
        }
        maxLen = max(maxLen, r - l + 1);
        hashmap[s[r]] = r;
        r++;
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