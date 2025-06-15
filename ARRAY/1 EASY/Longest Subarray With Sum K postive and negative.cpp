// Longest Subarray With Sum K with positive and negative
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 1

#define ll long long

// Brute
// TC O(N^3)
// SC O(N)
int _getLongestSubarray(vector<int> &nums, int k)
{
    int len = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i; j < nums.size(); ++j)
        {
            long long sum = 0;
            for (int q = i; q <= j; ++q)
            {
                sum += nums[q];
            }
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

// Optimal
// TC O(N)
// SC O(N)
int getLongestSubarray(vector<int> &nums, int k)
{
    map<ll, int> mp; // Stores prefix sums and their first occurrence index
    ll sum = 0;
    int maxLen = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i]; // Update prefix sum
        if (sum == k)   // If sum from start to i is k, update maxLen
        {
            maxLen = max(maxLen, i + 1);
        }
        ll rem = sum - k;             // Find remaining sum that should be removed
        if (mp.find(rem) != mp.end()) // If found, update maxLen
        {
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }

        if (mp.find(sum) == mp.end()) // Store sum only if it's not already present
        {
            mp[sum] = i;
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

int main()
{
    vector<int> nums = {1, -2, 1, 0, 1, 2, 2};
    cout << getLongestSubarray(nums, 4);
    return 0;
}