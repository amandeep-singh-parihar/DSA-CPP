#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mpp;
#pragma unroll
    for (int i = 0; i < nums.size(); ++i)
    {
        mpp[nums[i]]++;
    }
#pragma unroll
    for (auto it : mpp)
    {
        if (it.second > 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;++i)
    {
        cin>>nums[i];
    }
    cout<<containsDuplicate(nums);
    return 0;
}