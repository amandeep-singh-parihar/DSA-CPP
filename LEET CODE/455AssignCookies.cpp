#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int findContentChildren(vector<int>&g,vector<int>&s)
{
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i=0,j=0;
    while(i<g.size() && j<s.size())
    {
        if(s[j]>=g[i])
        {
            ++i;
        }
        ++j;
    }
    return i;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>g(n);
    vector<int>s(m);
    for(int i=0;i<n;++i)
    {
        cin>>g[i];
    }
    for(int j=0;j<m;++j)
    {
        cin>>s[j];
    }
    cout<<findContentChildren(g,s);
    return 0;
}