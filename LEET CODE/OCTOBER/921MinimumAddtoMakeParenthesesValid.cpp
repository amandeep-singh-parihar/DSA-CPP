//921. Minimum Add to Make Parentheses Valid
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int minAddToMakeValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    return st.size();
}

int main()
{
    string s;
    cin>>s;
    cout<<minAddToMakeValid(s);
    return 0;
}