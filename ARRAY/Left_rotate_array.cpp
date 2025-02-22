// Left rotate array
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O(N+K)
// SC O(K)
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    // make the temp vector with initial k elements
    vector<int> temp(k);
    for (int i = 0; i < k; ++i)
    {
        temp[i] = nums[i];
    }

    // shif the remaining elements in the array
    for (int i = k; i < n; ++i)
    {
        nums[i - k] = nums[i];
    }

    // fill the array's last k element with the temp k element
    int j = 0;
    for (int i = n - k; i < n; ++i)
    {
        nums[i] = temp[j++];
    }
}

// Brute
// TC O(N+K)
// SC O(K)
void _rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    // make the temp vector with initial k elements
    vector<int> temp(k);
    for (int i = 0; i < k; ++i)
    {
        temp[i] = nums[i];
    }

    // shif the remaining elements in the array
    for (int i = k; i < n; ++i)
    {
        nums[i - k] = nums[i];
    }

    // fill the array's last k element with the temp k element
    for (int i = n - k; i < n; ++i)
    {
        nums[i] = temp[i - (n - k)];
    }
}

// optimal (Reversal Algorithm)
// TC O(N)
// SC O(1)
void __rotate(vector<int> &nums, int k)
{
    int k = k % nums.size();
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}
/*
🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹 Approach: Reverse Algorithm🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹🔹
1. Find the effective rotation:
    🔹Since rotating an array of size N by N results in the same array,
    → We take k = k % N to avoid unnecessary rotations.

2. Reverse the first k elements:
    🔹This moves the first k elements to their final position but in reverse order.

3. Reverse the remaining N - k elements:
    🔹This moves the last N - k elements to their final position but in reverse order.

4. Reverse the entire array:
    🔹This restores the correct order.
*/

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    __rotate(nums, 3);
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}