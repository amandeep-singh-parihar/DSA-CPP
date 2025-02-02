// 930. Binary Subarrays With Sum
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N)
// SC O(1)

int solve(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > k)
        {
            sum = sum - nums[l];
            ++l;
        }
        count += r - l + 1;
        ++r;
    }
    return count;
}

int subarraySum(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << subarraySum(arr, k);
    return 0;
}