// better force

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
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); ++j)
        {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    return 0;
}