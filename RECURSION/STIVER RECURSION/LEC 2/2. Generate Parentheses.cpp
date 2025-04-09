// 22. Generate Parentheses
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(2^N * 2N)
// SC O(2N)
bool isValid(string output)
{
    int cnt = 0;
    for (int i = 0; i < output.size(); ++i)
    {
        if (cnt < 0)
            return false;

        if (output[i] == '(')
            ++cnt;
        else
            --cnt;
    }
    return cnt == 0;
}

void helper(int i, int n, vector<string> &ans, string output)
{
    if (i >= 2 * n)
    {
        if (isValid(output))
        {
            ans.push_back(output);
        }
        return;
    }

    // include '('
    output.push_back('(');
    helper(i + 1, n, ans, output);
    output.pop_back();

    // exclude '(' or include ')'
    output.push_back(')');
    helper(i + 1, n, ans, output);
    output.pop_back();
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string output = "";
    helper(0, n, ans, output);
    return ans;
}

// safaty check no need of isValid function
// TC O(2^2N)
// SC O(2N)

void _helper(int i, int n, vector<string> &ans, string &output, int open,
             int close)
{
    if (i >= 2 * n)
    {
        ans.push_back(output);
        return;
    }
    // include (
    if (open < n)
    {
        output.push_back('(');
        _helper(i + 1, n, ans, output, open + 1, close);
        output.pop_back();
    }
    // exclude (
    if (close < open)
    {
        output.push_back(')');
        _helper(i + 1, n, ans, output, open, close + 1);
        output.pop_back();
    }
}
vector<string> _generateParenthesis(int n)
{
    vector<string> ans;
    string output = "";
    _helper(0, n, ans, output, 0, 0);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> res = _generateParenthesis(n);
    for (auto it : res)
    {
        cout << it << ",";
    }
    cout << endl;
    return 0;
}