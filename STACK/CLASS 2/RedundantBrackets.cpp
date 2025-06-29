//Redundant Brackets
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision needed

bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(int i=0;i<s.size();++i)
    {
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {
            st.push(s[i]);
        }else{
            if(s[i]==')')
            {
                bool isREDUNDANT=true;
                while(st.top()!='(')
                {
                    if(st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*')
                    {
                        isREDUNDANT=false;
                    }
                    st.pop();
                }
                return isREDUNDANT==true;
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string st;
    cin>>st;
    cout<<findRedundantBrackets(st);
    return 0;
}