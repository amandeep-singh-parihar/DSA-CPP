#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
bool helper(vector<int> &counts, vector<int> &quantity, int index)
{
    if (index == quantity.size())
    {
        return true;
    }

    for (int i = 0; i < counts.size(); ++i)
    {
        if (counts[i] >= quantity[index])
        {
            counts[i] -= quantity[index];
            if (helper(counts, quantity, index + 1))
            {
                return true;
            }
            counts[i] += quantity[index];
        }
    }
    return false;
}
bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> mpp;
    for (auto num : nums)
    {
        mpp[num]++;
    }
    vector<int> counts;
    for (auto it : mpp)
    {
        counts.push_back(it.second);
    }
    sort(quantity.rbegin(), quantity.rend());
    return helper(counts, quantity, 0);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    vector<int> quantity(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    for (int j = 0; j < m; ++j)
    {
        cin >> quantity[j];
    }

    cout << canDistribute(nums, quantity);
    return 0;
}