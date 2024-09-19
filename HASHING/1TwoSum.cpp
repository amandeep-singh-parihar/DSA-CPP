#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int>twoSum(vector<int>nums,int target)
{
    vector<int>ans;
    unordered_map<int,int>mpp;
    for(int i=0;i<nums.size();++i)
    {
        int moreNeeded=target-nums[i];
        if(mpp.find(moreNeeded)!=mpp.end())
        {
            ans.push_back(mpp[moreNeeded]);
            ans.push_back(i);
            return ans;
        }
        mpp[nums[i]]=i;
    }
    return {-1,-1};
}

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}