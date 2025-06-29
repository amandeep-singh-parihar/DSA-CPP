// 32. Longest Valid Parentheses
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 1

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int maxLen = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (!st.empty())
            {
                int len = i - st.top();
                maxLen = max(maxLen, len);
            }
            else
            {
                st.push(i);
            }
        }
    }
    return maxLen;
}

int main()
{
    string str;
    cin >> str;
    cout << longestValidParentheses(str);
    return 0;
}