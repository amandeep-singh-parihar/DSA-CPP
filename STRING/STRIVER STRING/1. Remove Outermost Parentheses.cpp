// 1021. Remove Outermost Parentheses
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(s.size())
// SC O(s.size())
string removeOuterParentheses(string s)
{
    string ans = "";
    stack<char> st;
    int start = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }

        if (st.empty())
        {
            ans += s.substr(start + 1, i - start - 1);
            start = i + 1;
        }
    }
    return ans;
}

// TC O(s.size())
// SC O(1)
string _removeOuterParentheses(string s) {
    string ans = "";
    // stack<char> st;
    int cnt = 0;
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            // st.push(s[i]);
            ++cnt;
        } else {
            // st.pop();
            --cnt;
        }

        if (cnt==0) {
            ans += s.substr(start + 1, i - start - 1);
            start = i + 1;
        }
    }
    return ans;
}

int main()
{
    string s = "(()())(())";
    cout << removeOuterParentheses(s);
    return 0;
}