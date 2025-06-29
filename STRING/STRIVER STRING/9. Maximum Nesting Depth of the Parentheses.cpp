// 1614. Maximum Nesting Depth of the Parentheses
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maxDepth(string s)
{
    int cnt = 0;
    int maxCnt = -1e9;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            ++cnt;
        else if (s[i] == ')')
            --cnt;
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout<<maxDepth(s);
    return 0;
}