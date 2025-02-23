// 189. Rotate Array
#include <bits/stdc++.h>
using namespace std;

// Revision 2

// Brute Force
void _rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Handle cases where k > n

    // Step 1: Store last k elements in a temp array
    vector<int> temp(k);
    for (int i = 0; i < k; ++i)
    {
        temp[i] = nums[n - k + i];
    }

    // Step 2: Shift the first (n-k) elements to the right
    for (int i = n - 1; i >= k; --i)
    {
        nums[i] = nums[i - k];
    }

    // Step 3: Copy temp elements to the start of nums
    for (int i = 0; i < k; ++i)
    {
        nums[i] = temp[i];
    }
}

// Better
// TC O(N)
// SC O(N)
void rotate(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
}
// Optimal
// TC O(N)
// SC O(1)
void __rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    _rotate(nums, k);

    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}