#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maximumCount(vector<int> &nums)
{
    if (nums.front() > 0 && nums.back() > 0)
        return nums.size();
    if (nums.front() < 0 && nums.back() < 0)
        return nums.size();
    if (nums.front() == 0 && nums.back() == 0)
        return 0;
    int s = 0, e = nums.size() - 1;
    int pos = 0;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] <= 0)
            s = mid + 1;
        else
            e = mid;
    }
    pos = s;
    s = 0, e = nums.size() - 1;
    int neg = 0;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] >= 0)
            e = mid;
        else
            s = mid + 1;
    }
    neg = s;
    return max(neg - 0, (int)nums.size() - pos);
}

int main()
{
    vector<int> nums = {-2, -1, -1, 1, 2, 3};
    cout<<maximumCount(nums);
    return 0;
}