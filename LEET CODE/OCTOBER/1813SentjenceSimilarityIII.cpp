//921. Minimum Add to Make Parentheses Valid
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool areSentencesSimilar(string s1,string s2)
{
    if(s1.length()<s2.length())
    {
        swap(s1,s2);
    }

    vector<string>v1,v2;
    stringstream ss1(s1);
    stringstream ss2(s2);
    string token;
    while(ss1>>token){
        v1.push_back(token);
    }

    while(ss2>>token)
    {
        v2.push_back(token);
    }

    int i=0,j=v1.size()-1;
    int k=0,l=v2.size()-1;
    while(i<v1.size() && k<v2.size() && v1[i]==v2[k])
    {
        ++i,++k;
    }
    while(l>=k && v2[l]==v1[j])
    {
        --j,--l;
    }
    return l<k;
}

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<areSentencesSimilar(s1,s2);
    return 0;
}