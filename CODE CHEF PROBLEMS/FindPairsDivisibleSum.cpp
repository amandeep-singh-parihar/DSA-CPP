#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<vector<int>>solve(vector<vector<int>>&arr,int k)
{
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();++i)
    {
        int sum=arr[i][0]+arr[i][1];
        if(sum%k==0)
        {
            vector<int>temp;
            temp.push_back(arr[i][0]);
            temp.push_back(arr[i][1]);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>arr(n,vector<int>(2));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<2;++j)
        {
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>res=solve(arr,k);
    for(int i=0;i<res.size();++i)
    {
        cout<<"(";
        for(int j=0;j<res[i].size();++j)
        {
            cout<<res[i][j];
            if(j<res[i].size()-1)
            {
                cout<<", ";
            }
        }
        cout<<")";
        cout<<endl;
    }
    return 0;
}