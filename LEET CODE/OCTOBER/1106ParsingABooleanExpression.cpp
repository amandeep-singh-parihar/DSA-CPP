// 1106. Parsing A Boolean Expression
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

char solve(vector<char> &values, char op)
{
    if (op == '!')
    {
        return values[0] == 't' ? 'f' : 't';
    }

    if (op == '&')
    {
        for (char &ch : values)
        {
            if (ch == 'f')
            {
                return 'f';
            }
        }
        return 't';
    }

    if (op == '|')
    {
        for (char &ch : values)
        {
            if (ch == 't')
            {
                return 't';
            }
        }
        return 'f';
    }
    return 'a'; // this case never be reached
}

bool parseBoolExpr(string expression)
{
    int n = expression.length();

    stack<char> st;

    for (int i = 0; i < n; ++i)
    {
        if (expression[i] == ',')
            continue;

        if (expression[i] == ')')
        {
            vector<char> values;
            while (st.top() != '(')
            {
                values.push_back(st.top());
                st.pop();
            }
            st.pop();
            char op = st.top();
            st.pop();
            st.push(solve(values, op));
        }
        else
        {
            st.push(expression[i]);
        }
    }
    return st.top() == 'f' ? false : true;
}

int main()
{
    string expression;
    cin >> expression;
    cout << endl;
    cout << parseBoolExpr(expression);
    return 0;
}