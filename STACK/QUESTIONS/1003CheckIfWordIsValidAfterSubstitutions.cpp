// 1003. Check If Word Is Valid After Substitutions
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool isValid(string s)
{
    if (s[0] != 'a')
        return false;

    stack<int> st;
    for (char ch : s)
    {
        if (ch == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'b')
        {
            if (!st.empty() && st.top() == 'a')
            {
                st.push('b');
            }
            else
            {
                return false;
            }
        }
        else
        {
            // ch=='c'
            if (!st.empty() && st.top() == 'b')
            {
                st.pop();
                if (!st.empty() && st.top() == 'a')
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
    return st.empty();
}

int main()
{
    string s;
    cin >> s;

    if (isValid(s))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}