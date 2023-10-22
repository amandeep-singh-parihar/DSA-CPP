#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str="! siht si tahw";

    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        st.push(ch);
    }

    string ans="";
    while(!st.empty())
    {
        char ch=st.top();
        ans.push_back(ch);

        st.pop();
    }

    cout<<ans<<endl;
    return 0;
}

//the normal approach of this is more good as the time complexity of that approach is O(n) and space is O(1)
//but here in this stack the time is O(n) but the space is O(n);