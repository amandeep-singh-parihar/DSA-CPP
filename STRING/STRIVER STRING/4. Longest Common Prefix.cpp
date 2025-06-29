// 14. Longest Common Prefix
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// N = strs.size()
// M = strs[0].size()
// TC O(N * M)
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";

    string prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i)
    {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
        {
            ++j;
        }

        prefix = prefix.substr(0, j);
        if (prefix.empty())
            return "";
    }
    return prefix;
}
int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout<<longestCommonPrefix(strs);
    return 0;
}