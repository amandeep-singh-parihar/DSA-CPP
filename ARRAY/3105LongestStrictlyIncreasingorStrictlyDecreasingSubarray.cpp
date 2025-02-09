// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int longestMonotonicSubarray(vector<int> &nums)
{
    int maxi = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        bool inc = true, dec = true;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[j - 1] < nums[j])
                dec = false;
            else if (nums[j - 1] > nums[j])
                inc = false;
            else
                break;

            if (inc || dec)
                maxi = max(maxi, j - i + 1);
            else
                break;
        }
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << longestMonotonicSubarray(arr);
    return 0;
}