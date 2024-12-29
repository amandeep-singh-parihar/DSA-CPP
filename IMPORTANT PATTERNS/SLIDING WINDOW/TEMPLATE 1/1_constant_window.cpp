#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// find maxsum of size of array is k

int constantWindow(vector<int> &arr, int k)
{
    int l = 0;
    int r = k - 1;
    int sum = 0;
    int maxSum = INT_MIN;
    int n = arr.size();

    // calc sum for the first window
    for (int i = 0; i < k; ++i)
    {
        sum += arr[i];
    }
    maxSum = sum;

    while (r < n - 1)
    {
        sum = sum - arr[l];        // Remove the element at the start of the window
        ++l;                       // Move the left pointer
        ++r;                       // Move the right pointer
        sum = sum + arr[r];        // Add the new element at the end of the window
        maxSum = max(maxSum, sum); // update the sum
    }
    return maxSum;
}

int main()
{
    int k;
    cin >> k;
    vector<int> arr = {-1, 1, 3, -1, 5, -1};
    cout << constantWindow(arr, k);
    return 0;
}