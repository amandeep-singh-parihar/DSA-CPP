// 1004. Max Consecutive Ones III
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// convert the problem into finding the maximum consecutive ones with at most K zeros.
// BRUTE

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; ++i)
    {
        int zeros = 0;
        for (int j = i; j < n; ++j)
        {
            if (nums[i] == 0)
            {
                ++zeros;
            }
            if (zeros <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
                break;
        }
    }
}

int main()
{

    return 0;
}