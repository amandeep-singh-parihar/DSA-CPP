#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int ___longestSubarrayWithSumK(vector<int> nums, long long k)
{
    int n = nums.size();
    int l = 0, r = 0, maxLen = 0;
    int sum = 0;
    while (r < n)
    {
        sum += nums[r];
        if (sum == k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        while (l <= r && sum > k)
        {
            sum -= nums[l];
            ++l;
        }
        ++r;
    }
    return maxLen;
}

int main()
{
    vector<int> a = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    cout << ___longestSubarrayWithSumK(a, 3);
    return 0;
}