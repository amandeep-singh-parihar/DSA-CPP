#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void nextPermutation(vector<int> &nums)
{
    int idx=-1,n=nums.size();
    for(int i=n-2;i>=0;--i)
    {
        if(nums[i]<nums[i+1])
        {
            idx=i;
            break;
        }
    }
    if(idx==-1)
    {
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int i=n-1;i>idx;--i)
    {
        if(nums[i]>nums[idx])
        {
            swap(nums[i],nums[idx]);
            break;
        }
    }

    reverse(nums.begin()+idx+1,nums.end());
}

int main()
{
    vector<int> nums = {1,1,5};
    nextPermutation(nums);
    cout << "[";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}