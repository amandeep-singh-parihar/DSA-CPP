//this is not fully optimized yet it beats 100% of the online users of cpp


#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void sortColors(vector<int>& nums)
{
    int c0=0,c1=0,c2=0;
    for(int i=0;i<nums.size();++i)
    {
        if(nums[i]==0) c0++;
        else if(nums[i]==1) c1++;
        else c2++;
    }
    for(int i=0;i<c0;++i) nums[i]=0;
    for(int i=c0;i<c0+c1;++i) nums[i]=1;
    for(int i=c0+c1;i<nums.size();++i) nums[i]=2;
}

int main()
{
    vector<int>nums={2,0,2,1,1,0};
    sortColors(nums);
    for(int i=0;i<nums.size();++i)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}