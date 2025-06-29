#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// get the max sum in the subarray of size k

int main()
{
    int k;
    cin >> k;
    vector<int> nums = {-1, 2, 3, 4, 5, -1};
    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += nums[i];

    // cout << sum << " " << endl;

    int maxSum = sum;
    int l = 0, r = k;
    while (r < nums.size())
    {
        sum -= nums[l++];
        sum += nums[r++];
        maxSum = max(maxSum, sum);
    }
    cout << maxSum << endl;
    return 0;
}