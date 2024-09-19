// MOORE'S VOTING ALGORITHM
// MOORE'S VOTING ALGORITHM
// MOORE'S VOTING ALGORITHM
// MOORE'S VOTING ALGORITHM
// MOORE'S VOTING ALGORITHM
// MOORE'S VOTING ALGORITHM

#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 1
int majorityElement(vector<int> &nums)
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
    // vector<int> nums1 = {207327217, 207327217, 42, 42, 42, 42, 207327217, 42, 207327217, 42, 42, 207327217, 207327217, 42};
    vector<int>nums1={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    cout << majorityElement(nums1) << endl;
    return 0;
}