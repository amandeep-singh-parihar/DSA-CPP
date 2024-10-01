#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void solve(vector<int>&nums,vector<vector<int>>&res,int start)
{
    if(start==nums.size())
    {
        res.push_back(nums);
        return;
    }

    for(int i=start;i<nums.size();++i)
    {
        swap(nums[i],nums[start]);
        solve(nums,res,start+1);
        swap(nums[i],nums[start]);
    }
}

vector<vector<int>>permute(vector<int>&nums)
{
    vector<vector<int>>res;
    int start=0;
    solve(nums,res,start);
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
    cout<<"****************"<<"\n";
    vector<vector<int>>ans=permute(arr);
    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[i].size();++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}