#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
int main()
{
    string str;
    cin >> str;
    stack<char> st;
    for (char ch : str)
    {
        st.push(ch);
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}