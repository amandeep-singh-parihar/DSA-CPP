#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
};

vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] + n * (nums[nums[i]] % n);
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] /= n;
    }
    return nums;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans = buildArray(nums);
    cout << "[";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";
    return 0;
    return 0;
}