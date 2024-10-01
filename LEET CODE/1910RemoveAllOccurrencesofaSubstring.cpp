#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revsion 1
string removeOccurrences(string s,string part)
{
    while(s.find(part)!=string::npos)
    {
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    cout<<removeOccurrences(s,part)<<endl;
    return 0;
}