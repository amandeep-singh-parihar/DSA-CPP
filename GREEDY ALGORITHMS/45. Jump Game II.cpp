// 45. Jump Game II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// BRUTE
// TC O(N^N)
// SC O(N)
// NOT UNDERSTAND THIS PART WILL DO THIS FROM THE STRIVER RECURSION
// int solve(vector<int> &arr, int ind, int jumps)
// {
//     int n = arr.size();
//     if (ind >= n - 1)
//         return jumps;

//     int mini = INT_MAX;
//     for (int i = 1; i <= arr[ind]; i++)
//     {
//         mini = min(mini, solve(arr, ind + i, jumps + 1));
//     }

//     return mini;
// }
// int jump(vector<int> &nums)
// {
//     return solve(nums, 0, 0);
// }

// Optimal
// TC O(N)
// SC O(1)
int jump(vector<int> &nums)
{
    int jumps = 0, r = 0, l = 0;
    while (r < nums.size() - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; ++i)
        {
            farthest = max(farthest, i + nums[i]);
        }
        l = r + 1;
        r = farthest;
        jumps++;
    }
    return jumps;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << jump(arr);
    return 0;
}