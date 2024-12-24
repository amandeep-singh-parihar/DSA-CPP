//Count the Reversals
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int countRev (string s)
{
    if(s.size() & 1)
    {
        return -1;
    }
    stack<char>st;
    for(int i=0;i<s.size();++i)
    {
        if(!st.empty() && s[i]=='}' && st.top()=='{')
        {
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    int count=0;
    while(!st.empty())
    {
        int top1=st.top();
        st.pop();
        int top2=st.top();
        st.pop();
        if(top1==top2)
        {
            count++;
        }else{
            count+=2;
        }
    }
    return count;
}

int main()
{
    string str;
    cin>>str;
    cout<<countRev(str)<<endl;
    return 0;
}