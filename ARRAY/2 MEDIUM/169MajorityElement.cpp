// 169. Majority Element
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

// Brute
// TC O(N^2)
// SC O(1)
int majorityElement(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        int count = 0; // take a counter to count each element
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[i] == nums[j])
                count++; // count the element
        }
        if (count > (nums.size()) / 2) // if the count is more than [n/2]
            return nums[i];            // return the ans
    }
    return -1; // if now element appears more than half
}

// Better using map
// TC O(N)
// SC O(N)
int _majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mpp; // store the occurances of elements in the map
    for (int i = 0; i < nums.size(); ++i)
    {
        mpp[nums[i]]++; // store the occurance in the map
    }
    for (auto it : mpp) // traverse the map
    {
        if (it.second > (nums.size()) / 2) // if frequency of any one element is greater than [n/2]
            return it.first;               // return the element
    }
    return -1; // if not majority element
}

// TC O(NlogN)
// SC O(1)
// Intuition -> if the element is majority than after sorting the array it must be present
// in the middle or must cross the middle
int __majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

// MOORE'S VOTING ALGORITHM
// TC O(2N)
// SC O(1)
int ___majorityElement(vector<int> &nums)
{
    int cnt = 0, el;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (cnt == 0)
        {
            el = nums[i];
            cnt = 1;
        }
        else if (nums[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    // return el
    // No need of below steps if this is confirm that the array must have majority element
    int cnt1 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == el)
        {
            cnt1++;
        }
    }
    if (cnt1 > (nums.size() / 2))
    {
        return el;
    }
    return -1;
}

int main()
{
    vector<int> nums = {42, -294701967, 42, -834534123, -294701967, 391348743, 42, 391348743, 42, 42, -294701967, 42, 42, 42, 391348743, 391348743, 42, 391348743, -294701967, 42, 391348743, 42, -416680422, 391348743, 42, 42, 42, 42, 391348743, -416680422, 42, 42, 391348743, 42, 391348743, 391348743, 42, 391348743, 42, 391348743, 391348743, 391348743, 42, -294701967, -416680422, 42, -294701967, -294701967, 42, 391348743, 42, 391348743, 391348743, 42, 42, -416680422, -294701967, 391348743, 42, -294701967, 42, -294701967, 42, 42, 391348743, 42, 42, 42, 42, -294701967, 42, -294701967, 391348743, -294701967, 42, 42, 42, 42, 42, 42, 391348743, 391348743, 42, -294701967, 391348743, 42, 391348743, 42, 42, 391348743, 42, -294701967, -294701967, 42, -294701967, 42, 42, 42, 391348743, 42};
    cout << majorityElement(nums);
    return 0;
}