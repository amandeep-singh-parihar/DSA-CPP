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
    int pos = 0, neg = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] < 0)
            neg++;
        if (nums[i] > 0)
            pos++;
    }
    return max(neg,pos);
}

int main()
{
    vector<int> nums = {-2, -1, -1, 1, 2, 3};
    cout<<maximumCount(nums);
    return 0;
}