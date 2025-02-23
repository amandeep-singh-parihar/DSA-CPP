// 75. Sort Colors
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Better
// TC O(2N)
// SC O(1);
void sortColors(vector<int> &nums)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
            c0++;
        else if (nums[i] == 1)
            c1++;
        else
            c2++;
    }
    for (int i = 0; i < c0; ++i)
        nums[i] = 0;
    for (int i = c0; i < c0 + c1; ++i)
        nums[i] = 1;
    for (int i = c0 + c1; i < nums.size(); ++i)
        nums[i] = 2;
}

// DUTCH NATIONAL FLAG ALGORITHM
// TC O(N)
// SC O(1)
void _sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++, mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    return 0;
}