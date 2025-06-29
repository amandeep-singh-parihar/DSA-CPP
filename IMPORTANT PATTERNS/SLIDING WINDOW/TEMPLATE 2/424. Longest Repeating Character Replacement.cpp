// 424. Longest Repeating Character Replacement
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O(N*N)
// SC O(1);
// int characterReplacement(string s, int k)
// {
//     int maxLen = 0;
//     int maxFreq = 0;
//     for (int i = 0; i < s.size(); ++i)
//     {
//         unordered_map<char, int> mpp;
//         for (int j = i; j < s.size(); ++j)
//         {
//             mpp[s[j]]++;
//             maxFreq = max(maxFreq, mpp[s[j]]);
//             int changes = (j - i + 1) - maxFreq;
//             if (changes <= k)
//             {
//                 maxLen = max(maxLen, j - i + 1);
//             }
//             else
//                 break;
//         }
//     }
//     return maxLen;
// }

// Better
// TC O(N+N)
// SC O(1);
// int characterReplacement(string s, int k)
// {
//     int maxLen = 0, maxFreq = 0;
//     int r = 0, l = 0;
//     unordered_map<char, int> mpp;
//     while (r < s.size())
//     {
//         mpp[s[r]]++;
//         maxFreq = max(maxFreq, mpp[s[r]]);
//         while ((r - l + 1) - maxFreq > k)
//         {
//             mpp[s[l]]--;
//             ++l;
//         }
//         maxLen = max(maxLen, r - l + 1);
//         ++r;
//     }
//     return maxLen;
// }


// Optimal
// TC O(N)
// SC O(1);
int characterReplacement(string s, int k)
{
    int maxLen = 0, maxFreq = 0;
    int r = 0, l = 0;
    vector<int>mpp(26,0);
    while (r < s.size())
    {
        mpp[s[r]-'A']++;
        maxFreq = max(maxFreq, mpp[s[r]-'A']);
        if ((r - l + 1) - maxFreq > k)
        {
            mpp[s[l]-'A']--;
            ++l;
        }
        maxLen = max(maxLen, r - l + 1);
        ++r;
    }
    return maxLen;
}


int main()
{
    string str;
    int k;
    cin >> str >> k;
    cout << characterReplacement(str, k);
    return 0;
}