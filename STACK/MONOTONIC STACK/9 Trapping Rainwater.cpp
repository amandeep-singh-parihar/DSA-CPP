#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Better
// TC O(3N)
// SC O(2N)
vector<int> prefixMax(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n);

    prefix[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        prefix[i] = max(prefix[i - 1], nums[i]);
    }

    return prefix;
}
vector<int> suffixMax(vector<int> &nums)
{
    int n = nums.size();
    vector<int> suffix(n);

    suffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        suffix[i] = max(suffix[i + 1], nums[i]);
    }

    return suffix;
}
int trap(vector<int> &height)
{
    int total = 0;
    int n = height.size();
    vector<int> prefix = prefixMax(height);
    vector<int> suffix = suffixMax(height);
    for (int i = 0; i < n; ++i)
    {
        int left = prefix[i];
        int right = suffix[i];
        if (height[i] < left && height[i] < right)
        {
            total += min(left, right) - height[i];
        }
    }

    return total;
}

// MOre Better
// TC O()
// SC O(N)
vector<int> _suffixMax(vector<int> &nums)
{
    int n = nums.size();
    vector<int> suffix(n);

    suffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        suffix[i] = max(suffix[i + 1], nums[i]);
    }

    return suffix;
}
int _trap(vector<int> &height)
{
    int total = 0;
    int n = height.size();
    // vector<int> prefix = prefixMax(height);
    int left = INT_MIN;
    vector<int> suffix = _suffixMax(height);
    for (int i = 0; i < n; ++i)
    {
        left = max(left,height[i]);
        int right = suffix[i];
        if (height[i] < left && height[i] < right)
        {
            total += min(left, right) - height[i];
        }
    }

    return total;
}

int main()
{
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << _trap(nums);
    return 0;
}