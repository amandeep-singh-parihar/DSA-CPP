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
    int open=0,close=0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            ++open;
        }
        else if (open>0 && s[i]==')')
        {
            --open;
        }
        else
        {
            ++close;
        }
    }
    return open+close;
}

int main()
{
    string s;
    cin>>s;
    cout<<minAddToMakeValid(s);
    return 0;
}