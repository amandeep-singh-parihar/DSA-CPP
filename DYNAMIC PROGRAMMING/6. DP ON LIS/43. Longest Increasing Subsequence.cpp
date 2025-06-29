// DP 43. Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Binary Search
// TC O(N log N)
// SC O(N)
int lengthOfLIS(vector<int> &nums)
{
    vector<int> temp;
    temp.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
        }
        else
        {
            // it means it is smaller and go to right of that index
            // [10,9,2,5,3,7,101,18]
            // lets say the the temp till now is [2,5]
            // and we are at the 3 now three is smaller that 5 so it will come before 5 so it will come right of 2
            int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            // here the lowerbound of 3 is 5 here as 5>=3 so at index 1
            // now temp[1] = nums[4]
            // temp[1] = 3 -> [2,3]
            temp[index] = nums[i];
        }
    }
    return temp.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums);
    return 0;
}