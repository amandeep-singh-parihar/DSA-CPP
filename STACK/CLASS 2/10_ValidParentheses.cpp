// 20. Valid Parentheses
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (!st.empty() && s[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else if (!st.empty() && s[i] == ']' && st.top() == '[')
        {
            st.pop();
        }
        else if (!st.empty() && s[i] == '}' && st.top() == '{')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.size() == 0;
}

int main()
{
    string str;
    cin >> str;
    cout << isValid(str);
    return 0;
}