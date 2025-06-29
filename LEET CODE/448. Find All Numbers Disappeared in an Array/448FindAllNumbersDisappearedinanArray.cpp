#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    set<int> s(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 1; i <= nums.size(); ++i)
    {
        if (s.find(i) == s.end())
        {
            res.push_back(i);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    vector<int> ans = findDisappearedNumbers(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}