// 1004. Max Consecutive Ones III
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// BETTER

int longestOnes(vector<int> &nums, int k)
{
    int l = 0, r = 0, maxLen = 0, zeros = 0;
    int n = nums.size();
    while (r < n)
    {
        if (nums[r] == 0)
            ++zeros;

        while (zeros > k)
        {
            if (nums[l] == 0)
            {
                --zeros;
            }
            ++l;
        }
        if (zeros <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        ++r;
    }
    return maxLen;
}

int main()
{

    return 0;
}