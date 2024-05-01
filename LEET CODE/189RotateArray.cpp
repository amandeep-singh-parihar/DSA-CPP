#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {1, 3, 6, 11, 12, 17};
    rotate(nums, 4);
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    return 0;
}