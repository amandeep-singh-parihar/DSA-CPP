#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); ++i)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string expression;
    cout << "Enter a string with parentheses: ";
    cin >> expression;

    if (isValidParenthesis(expression))
    {
        cout << "The expression has valid parentheses." << endl;
    }
    else
    {
        cout << "The expression does not have valid parentheses." << endl;
    }

    return 0;
}