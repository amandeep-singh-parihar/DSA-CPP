// 2873. Maximum Value of an Ordered Triplet I
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
#define ll long long
// Brute
// TC O(N*N*N)
// SC O(1);
long long maximumTripletValue(vector<int> &nums)
{
    ll maxi = 0;
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                ll val = (1LL * (nums[i] - nums[j]) * nums[k]);
                maxi = max(maxi, val);
            }
        }
    }
    return maxi;
}

// Optimized
// TC O(N+N+N)
// SC O(N+N)

// intuition
// (nums[i]-nums[j])*nums[k]
// to increase the triplet we have to increase the nums[i] decrease the nums[j] and increase the nums[k]
// for any given j
// find the max in the left of j
// find the max in the right of j

long long _maximumTripletValue(vector<int> &nums)
{
    int n = nums.size();
    vector<int> leftMaxi(n, 0);
    vector<int> rightMaxi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        leftMaxi[i] = max(leftMaxi[i - 1], nums[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        rightMaxi[i] = max(rightMaxi[i + 1], nums[i + 1]);
    }

    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        ll val = (1LL * (leftMaxi[i] - nums[i]) * rightMaxi[i]);
        // increasing the leftMaxi[i]
        // decreseasing the nums[i] -> let it be the all values
        // increase the rightMaxi[i]
        res = max(res, val);
    }
    return res;
}

// optimal -> revision needed not understand fully
// TC O(N)
// SC O(1)
long long __maximumTripletValue(vector<int> &nums)
{
    int n = nums.size();
    ll result = 0;
    ll maxDiff = 0;
    ll maxi = 0;
    for (int k = 0; k < n; ++k)
    {
        result = max(result, maxDiff * nums[k]);
        maxDiff = max(maxDiff, maxi - nums[k]);
        maxi = max(maxi, (ll)nums[k]);
    }
    return result;
}

int main()
{
    vector<int> nums = {12, 6, 1, 2, 7};
    cout << _maximumTripletValue(nums);
    return 0;
}