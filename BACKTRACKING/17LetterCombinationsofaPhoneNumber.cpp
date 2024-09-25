#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void solve(vector<string> &res, int i, string output, string digits, vector<string> &mapping)
{
    if (i >= digits.length())
    {
        res.push_back(output);
        return;
    }

    int digit = digits[i] - '0';
    string value = mapping[digit];
    for (int j = 0; j < value.length(); ++j)
    {
        char ch = value[j];
        output.push_back(ch);
        solve(res, i + 1, output, digits, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> res;
    if (digits.length() == 0)
    {
        return res;
    }
    int i = 0;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";
    solve(res, i, output, digits, mapping);
    return res;
}

int main()
{
    string digits;
    cin >> digits;
    vector<string> ans = letterCombinations(digits);
    cout<<"[";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << "";
        if (i < ans.size() - 1)
        {
            cout << ",";
        }
    }
    cout<<"]";
    cout << endl;
    return 0;
}