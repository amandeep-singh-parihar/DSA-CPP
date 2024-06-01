// KADANE'S ALGORITHM
// KADANE'S ALGORITHM
// KADANE'S ALGORITHM

#include <bits/stdc++.h>
using namespace std;
#define ll long long
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maxSubArray(vector<int> &nums)
{
    ll sum = 0, maxi = LONG_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

int main()
{
    vector<int> nums = {4, 3, 1, 5, 6};
    cout << maxSubArray(nums);
    return 0;
}

