#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//Generate_permutation_of_string
//Generate_permutation_of_string

void solve(string&s,vector<string>&res,int index)
{
    if(index==s.size()){
        res.push_back(s);
        return;
    }

    for(int i=index;i<s.size();++i)
    {
        swap(s[i],s[index]);
        solve(s,res,index+1);
        swap(s[i],s[index]);
    }

}

vector<string>permute(string&s)
{
    vector<string>res;
    solve(s,res,0);
    return res;
}

int main()
{
    string str;
    cin>>str;
    vector<string>res=permute(str);
    for(int i=0;i<res.size();++i)
    {
       cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}