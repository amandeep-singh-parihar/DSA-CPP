//brute force

#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maxSubArray(vector<int> &nums)
{
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();++i)
    {
        for(int j=i;j<nums.size();++j)
        {
            int sum=0;
            for(int k=i;k<=j;++k)
            {
                sum+=nums[k];
                maxi=max(sum,maxi);
            }
        }
    }
    return maxi;
}

int main()
{
    vector<int>nums={5,4,-1,7,8};
    cout<<maxSubArray(nums);
    return 0;
}