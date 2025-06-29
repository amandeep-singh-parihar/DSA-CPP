//2696. Minimum String Length After Removing Substrings
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int minLength(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();++i)
    {
        if(!st.empty() && st.top()=='A' && s[i]=='B')
        {
            st.pop();
        }else if(!st.empty() && st.top()=='C' && s[i]=='D')
        {
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    return st.size();
}

int main()
{
    string s;
    cin>>s;
    cout<<minLength(s);
    return 0;
}