#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int>twoSum(vector<int>&nums,int target)
{
    vector<int>res;
    for(int i=0;i<nums.size();++i)
    {
        for(int j=i+1;j<nums.size();++j)
        {
            if(nums[i]+nums[j]==target)
            {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}