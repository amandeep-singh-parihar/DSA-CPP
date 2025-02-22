// 268. Missing Number
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O(N) + O(NlogN)(this is for sorting)
// SC O(1)
int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    if (nums[0] != 0)
        return 0;
    if (nums[nums.size() - 1] != nums.size())
        return nums.size();

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] + 1 != nums[i + 1])
        {
            return nums[i] + 1;
        }
    }
    return -1;
}

// Optimal
// TC O(N)
// SC O(1)

int _missingNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i <= nums.size(); ++i)
    {
        ans ^= i;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        ans ^= nums[i];
    }
    return ans;
}

// Optimal
// TC O(N)
// SC O(1)
int __missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int expected_sum = (n * (n - 1)) / 2;
    int actual_sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        actual_sum += nums[i];
    }
    return expected_sum - actual_sum;
}

int main()
{
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << __missingNumber(nums) << endl;
    return 0;
}