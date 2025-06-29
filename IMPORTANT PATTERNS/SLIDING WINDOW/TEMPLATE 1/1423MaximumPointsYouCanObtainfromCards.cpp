// 1423. Maximum Points You Can Obtain from Cards
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int lsum = 0;
    int rsum = 0;
    int maxSum = 0;
    // this is for calc the lsum
    for (int i = 0; i <= k - 1; ++i)
    {
        lsum = lsum + arr[i];
    }
    maxSum = lsum;
    // this is for calc the, we maintain the rightIndex
    int rightIdx = n - 1;
    for (int i = k - 1; i >= 0; --i)
    {
        lsum = lsum - arr[i];
        rsum = rsum + arr[rightIdx];
        rightIdx--;
        maxSum = max(maxSum, (lsum + rsum));
    }
    return maxSum;
}

int main()
{
    int k;
    cin >> k;
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    cout << solve(arr, k);
    return 0;
}