// 1248. Count Number of Nice Subarrays
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int solve(vector<int> &nums, int k)
{
    int r = 0, l = 0, oddCount = 0, count = 0;
    while (r < nums.size())
    {
        if (nums[r] % 2 != 0)
        {
            oddCount++;
        }
        while (oddCount > k)
        {
            if (nums[l] % 2 != 0)
            {
                oddCount--;
            }
            ++l;
        }
        count += r - l + 1;
        ++r;
    }
    return count;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << numberOfSubarrays(arr, k);
    return 0;
}