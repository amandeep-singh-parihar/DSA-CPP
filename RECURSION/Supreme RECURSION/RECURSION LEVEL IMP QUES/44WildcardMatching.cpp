#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool isMatchHelper(string& s,int si,string&p,int pi)
{
    //base case1
    if(si==s.size() && pi==p.size())
    {
        return true;
    }
    //base case2
    if(si==s.size() && pi<p.size())
    {
        while(pi<p.size())
        {
            if(p[pi]!='*') return false;
            pi++;
        }
        return true;
    }

    //single character matching
    if(s[si]==p[pi] || p[pi]=='?')
    {
        return isMatchHelper(s,si+1,p,pi+1);
    }

    if(p[pi]=='*')
    {
        //case * as empty
        bool empty = isMatchHelper(s,si,p,pi+1);

        //case * consume one
        bool consume = isMatchHelper(s,si+1,p,pi);
        return empty || consume;
    }
    return false;
}

bool isMatch(string& s,string&p)
{
    return isMatchHelper(s,0,p,0);
}

int main()
{
    string s,p;
    cin>>s>>p;
    cout<<isMatch(s,p);
    return 0;
}