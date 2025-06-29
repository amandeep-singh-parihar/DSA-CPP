//1331. Rank Transform of an Array
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int>arrayRankTransform(vector<int>&arr)
{
    if(arr.empty()) return {};
    vector<int>res;
    vector<int>temp=arr;
    sort(temp.begin(),temp.end());
    unordered_map<int,int>mp;
    mp[temp[0]]=1;
    for(int i=1;i<temp.size();++i)
    {
        if(temp[i]>temp[i-1])
        {
            mp[temp[i]]=mp[temp[i-1]]+1;
        }else{
            mp[temp[i]]=mp[temp[i-1]];
        }
    }

    for(auto it:arr)
    {
        res.push_back(mp[it]);
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    vector<int>ans=arrayRankTransform(arr);
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}