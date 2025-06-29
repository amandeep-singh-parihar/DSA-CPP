// Longest subarray with sum<=k?
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC(2N)
// SC(1)
// Better Solution

int longest_subarray(vector<int> &arr, int k)
{
    int n = arr.size();
    int l = 0, r = 0, sum = 0, maxLen = 0;
    while (r < n)
    {
        sum = sum + arr[r];
        while (sum > k)
        {
            sum = sum - arr[l];
            ++l;
        }
        if (sum <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}

int main()
{
    int k;
    cin >> k;
    vector<int> arr = {2, 5, 1, 7, 10};
    cout << longest_subarray(arr, k);
    return 0;
}