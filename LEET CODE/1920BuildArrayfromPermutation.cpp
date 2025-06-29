#include <bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(nums[nums[i]]);
    }
    return ans;
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
}