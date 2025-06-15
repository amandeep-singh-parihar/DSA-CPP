// Longest Subarray With Sum K
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 1

// Brute -> Generate all subarrays and calculate sum of all and when the sum is equal to
// the k take that length and compare it is long or not

// TC O(N^3)
// SC O(1)
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int len = INT_MIN;
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = i; j < a.size(); ++j)
        {
            long long sum = 0;
            for (int q = i; q <= j; ++q)
            {
                sum += a[q];
            }
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

// Better Brute
// TC O(N^2)
// SC O(1)
int _longestSubarrayWithSumK(vector<int> a, long long k)
{
    int len = INT_MIN;
    for (int i = 0; i < a.size(); ++i)
    {
        long long sum = 0;
        for (int j = i; j < a.size(); ++j)
        {
            sum += a[j];
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

// Better
// TC O(N)
// SC O(N)
int __longestSubarrayWithSumK(vector<int> a, long long k)
{
    map<long long, int> preSumMap; // Stores prefix sums and their first occurrence index
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        sum += a[i];  // Update prefix sum
        if (sum == k) // If sum from start to i is k, update maxLen
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;                    // Find remaining sum that should be removed
        if (preSumMap.find(rem) != preSumMap.end()) // If found, update maxLen
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end()) // Store sum only if it's not already present
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
/*
🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹 Steps 🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹
1. Maintain a cumulative sum (sum) while iterating through the array.
2. Check if sum equals k:
    If sum == k, the subarray from the start (0) to i has sum k, so update maxLen.
3. Check if (sum - k) exists in the map:
    This means a previous prefix sum rem = sum - k was found at some index j.
    The subarray from j+1 to i has sum k, so update maxLen.
4. Store sum in the hashmap (if not already present) with its index.
*/

// Optimal
// TC O(2N)
// TC O(1)
int ___longestSubarrayWithSumK(vector<int> nums, long long k)
{
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    while (right < nums.size())
    {

        sum += nums[right]; // Add the current element to sum

        // Shrink the window from the left if sum exceeds k
        while (left <= right && sum > k)
        {
            sum -= nums[left];
            ++left;
        }

        // Update maxLen if sum equals k
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        ++right; // Move the right pointer
    }
    return maxLen;
}
/*
🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹 Steps 🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹
    NOTE -> Only works if the array must have positives
1. Expand the window (right pointer) and add nums[right] to sum.
2. If sum exceeds k, move the left pointer to shrink the window.
3. If sum ==k, update maxLen as right - left + 1.
4. Continue until the right pointer reaches the end of the array.
*/

int main()
{
    vector<int> a = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    cout << ___longestSubarrayWithSumK(a, 3);
    return 0;
}