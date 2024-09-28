#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maxSubArrayHelper(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return nums[start];
    }

    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int mid = start + (end - start) / 2;
    int maxLeftSum = maxSubArrayHelper(nums, start, mid);
    int maxRightSum = maxSubArrayHelper(nums, mid + 1, end);

    int leftBorderSum = 0, rightBorderSum = 0;
    for (int i = mid; i >= start; --i)
    {
        leftBorderSum += nums[i];
        maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
    }

    for (int i = mid + 1; i <= end; ++i)
    {
        rightBorderSum += nums[i];
        maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
    }
    int crossBorderSum = maxRightBorderSum + maxLeftBorderSum;
    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}
int maxSubArray(vector<int> &nums)
{
    return maxSubArrayHelper(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}