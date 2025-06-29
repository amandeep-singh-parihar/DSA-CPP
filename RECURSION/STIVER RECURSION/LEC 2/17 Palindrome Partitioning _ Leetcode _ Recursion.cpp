// L17. Palindrome Partitioning | Leetcode | Recursion | C++ | Java
// 131. Palindrome Partitioning
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC: O(2^n * n)
// SC: O(2^n * n) (for output) + O(n) (call stack + path)

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end])
            return false;
    }
    return true;
}

void helper(int idx, vector<vector<string>> &res, vector<string> &path, string s)
{
    if (idx == s.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = idx; i < s.size(); ++i)
    {
        if (isPalindrome(s, idx, i))
        {
            path.push_back(s.substr(idx, i - idx + 1));
            // substr(start, length) to get the correct length
            // simply i-idx+1
            helper(i + 1, res, path, s);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    helper(0, res, path, s);
    return res;
}

int main()
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for (auto it : ans)
    {
        for (auto _it : it)
        {
            cout << _it << " ";
        }
        cout << endl;
    }
    return 0;
}