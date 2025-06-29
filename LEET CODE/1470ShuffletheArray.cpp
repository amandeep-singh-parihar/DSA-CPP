#include <bits/stdc++.h>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < nums.size(); j = j + n)
        {
            ans.push_back(nums[j]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = shuffle(nums, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
        {
            cout << ",";
        }
    }
}