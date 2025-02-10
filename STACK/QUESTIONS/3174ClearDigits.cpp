// 3174. Clear Digits
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

string clearDigits(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (isdigit(ch))
        {
            if (!st.empty())
                st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str = "qm93xjkpaaovhqckjhg5j1o4rndtg3bobgeke";
    // output must be "xjkpaaovhqckjhrndtbobgeke"
    cout << clearDigits(str);
    return 0;
}