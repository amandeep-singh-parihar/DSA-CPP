//1957. Delete Characters to Make Fancy String
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

string makeFancyString(string s)
{
    string res="";
    res.push_back(s[0]);
    int c=1;
    for(int i=1;i<s.size();++i)
    {
        if(s[i]==res.back())
        {
            ++c;
            if(c<3)
            {
                res.push_back(s[i]);
            }
        }else{
            res.push_back(s[i]);
            c=1;
        }
    }
    return res;
}

int main()
{
    string str;
    cin>>str;
    cout<<makeFancyString(str)<<endl;
    return 0;
}