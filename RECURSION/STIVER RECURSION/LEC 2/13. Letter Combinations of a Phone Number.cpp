// 17. Letter Combinations of a Phone Number
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void helper(int idx, vector<string> &ans, vector<string> &keypad, string output, string digits)
{
    if (idx == digits.size())
    {
        ans.push_back(output);
        return;
    }

    int digit = digits[idx] - '0';
    string value = keypad[digit];
    for (int i = 0; i < value.size(); ++i)
    {
        char ch = value[i];
        output.push_back(ch);
        helper(idx + 1, ans, keypad, output, digits);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.size() == 0)
        return ans;
    vector<string> keypad(10);
    keypad[2] = "abc";
    keypad[3] = "def";
    keypad[4] = "ghi";
    keypad[5] = "jkl";
    keypad[6] = "mno";
    keypad[7] = "pqrs";
    keypad[8] = "tuv";
    keypad[9] = "wxyz";
    string output = "";
    helper(0, ans, keypad, output, digits);
    return ans;
}

int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}