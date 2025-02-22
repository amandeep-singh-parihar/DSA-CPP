// 485. Max Consecutive Ones
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
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, result = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 1)
        {
            ++count;
        }
        else
        {
            count = 0;
        }
        result = max(result, count);
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}