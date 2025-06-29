#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int solve(vector<int>&arr,int k)
{
    int miniSum=abs(k-arr[0]);
    int close=arr[0];
    for(int i=1;i<arr.size();++i)
    {
        int diff=abs(arr[i]-k);
        if(diff<miniSum)
        {
            miniSum=diff;
            close=arr[i];
        }
        else if(diff==miniSum && arr[i]<close)
        {
            close=arr[i];
        }
    }
    return close;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    cout<<solve(arr,k);
    return 0;
}