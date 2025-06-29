#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
int main()
{
    vector<int>arr(26,0);
    string s,t;
    cin>>s>>t;
    for(int i=0;i<s.size();++i)
    {
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }

    int count=0;
    for(int i=0;i<26;++i)
    {
        if(arr[i]>0)
        {
            count+=arr[i];
        }
    }
    cout<<count<<" "<<endl;
    return 0;
}