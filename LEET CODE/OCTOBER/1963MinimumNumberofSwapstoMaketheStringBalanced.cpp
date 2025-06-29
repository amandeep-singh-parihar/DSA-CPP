//1963. Minimum Number of Swaps to Make the String Balanced
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int minSwaps(string s)
{
    stack<char>st;
    for(auto it:s)
    {
        if(it=='[')
        {
            st.push(it);
        }else if(!st.empty())
        {
            st.pop();
        }
    }
    return (st.size()+1)/2;
}

int main()
{
    string s;
    cin>>s;
    cout<<minSwaps(s);
    return 0;
}