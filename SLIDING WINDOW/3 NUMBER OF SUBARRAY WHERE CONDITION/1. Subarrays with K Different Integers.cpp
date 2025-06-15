#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O(N*N)
// SC O(k+1)
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        unordered_map<int, int> mp;
        for (int j = i; j < n; ++j)
        {
            mp[nums[j]]++;

            if (mp.size() == k)
                ++cnt;
            else if (mp.size() > k)
                break;
        }
    }
    return cnt;
}

// Optimal
// TC O(N)
// SC O(k+1)
int f(vector<int> &nums, int k)
{

    if (k == 0)
        return 0;

    int n = nums.size();
    int cnt = 0;
    int r = 0, l = 0;
    unordered_map<int, int> mp;
    while (r < n)
    {
        mp[nums[r]]++;

        while (mp.size() > k)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
            {
                mp.erase(nums[l]);
            }
            ++l;
        }
        cnt += (r - l + 1);
        ++r;
    }
    return cnt;
}
int _subarraysWithKDistinct(vector<int> &nums, int k)
{
    return f(nums, k) - f(nums, k - 1);
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << _subarraysWithKDistinct(nums, k);
    return 0;
}