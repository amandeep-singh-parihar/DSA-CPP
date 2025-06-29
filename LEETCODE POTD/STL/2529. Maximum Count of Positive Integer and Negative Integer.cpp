#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// simple brute approach
int _maximumCount(vector<int> &nums)
{
    int pos = 0, neg = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0)
            ++pos;
        else if (nums[i] < 0)
            ++neg;
    }
    return max(pos, neg);
}

// STL approach -> using lambda
int maximumCount(vector<int> &nums)
{
    auto P = [](int num)
    { return num > 0; };
    auto N = [](int num)
    { return num < 0; };
    int pos = count_if(nums.begin(), nums.end(), P);
    int neg = count_if(nums.begin(), nums.end(), N);
    return max(pos, neg);
}

int __maximumCount(vector<int> &nums)
{
    int n = nums.size();
    int firstP = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
    int firstZ = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    return max(n - firstP, firstZ);
}

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    cout << maximumCount(nums);
    return 0;
}