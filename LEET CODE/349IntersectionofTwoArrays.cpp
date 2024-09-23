#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int>intersection(vector<int>&arr,vector<int>&brr)
{
    set<int>s1(arr.begin(),arr.end());
    set<int>ans;
    for(auto it:brr)
    {
        if(s1.find(it)!=s1.end())
        {
            ans.insert(it);
            s1.erase(it);
        }
    }

    return vector<int>(ans.begin(),ans.end());
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    vector<int>brr(n);

    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>brr[i];
    }
    
    vector<int>ans=intersection(arr,brr);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}