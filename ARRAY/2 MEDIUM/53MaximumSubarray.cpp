// 53. Maximum Subarray
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O(N^3)
// SC O(1)
int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i; j < nums.size(); ++j)
        {
            int sum = 0;
            for (int k = i; k <= j; ++k)
            {
                sum += nums[k];
                maxi = max(sum, maxi);
            }
        }
    }
    return maxi;
}

// Better Brute
// TC O(N^2)
// SC O(1)
int _maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); ++j)
        {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// KADANE'S ALGORITHM KADANE'S
// TC O(N)
// SC O(1)
int __maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

// FOLLOW UP QUESTION FIND THAT SUBARRAY
// int ___maxSubArray(vector<int> &nums)
// {
//     int maxi = INT_MIN;
//     int sum = 0;
//     int start = 0;
//     int ansStart = -1, ansEnd = -1;
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         if (sum == 0)
//             start = i;
//         sum += nums[i];
//         if (sum > maxi)
//         {
//             maxi = sum;
//             ansStart = start;
//             ansEnd = i;
//         }
//         if (sum < 0)
//             sum = 0;
//     }
//     // Print that array
//     for(int i = ansStart;i<=ansEnd;++i)
//     {
//         cout<<nums[i]<<" ";
//     }
//     cout<<endl;
//     return maxi;
// }

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << __maxSubArray(nums);
    return 0;
}