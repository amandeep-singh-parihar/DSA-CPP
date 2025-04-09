// 3211. Generate Binary Strings Without Adjacent Zeros
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(2^N)
// SC O(2^N)
void helper(int i, int n, string output, vector<string> &ans, char prev)
{
    if (i >= n)
    {
        ans.push_back(output);
        return;
    }

    helper(i + 1, n, output + '1', ans, '1');

    if (prev != '0')
    {
        helper(i + 1, n, output + '0', ans, '0');
    }
}

vector<string> validStrings(int n)
{
    string output = "";
    vector<string> ans;
    char prev = '#';
    helper(0, n, output, ans, prev);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> res = validStrings(n);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}