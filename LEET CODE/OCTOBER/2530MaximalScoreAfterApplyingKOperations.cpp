//2530. Maximal Score After Applying K Operations
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

#define ll long long

ll maxKelements(vector<int>&nums,int k)
{
    ll sum=0;
    priority_queue<int>pq(nums.begin(),nums.end());
    while(k--)
    {
        int maxEl=pq.top();
        pq.pop();

        sum+=maxEl;
        maxEl=ceil(maxEl/3.0);
        pq.push(maxEl);
    }
    return sum;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;++i)
    {
        cin>>nums[i];
    }
    cout<<maxKelements(nums,k);
    return 0;
}