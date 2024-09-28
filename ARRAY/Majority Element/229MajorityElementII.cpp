#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> res;
    int ele1, ele2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (cnt1 == 0 && nums[i] != ele2)
        {
            ele1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && nums[i] != ele1)
        {
            ele2 = nums[i];
            cnt2 = 1;
        }
        else if (nums[i] == ele1)
        {
            cnt1++;
        }
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for (auto it : nums)
    {
        if (it == ele1)
        {
            cnt1++;
        }
        else if (it == ele2)
        {
            cnt2++;
        }
    }
    if (cnt1 > floor(nums.size() / 3))
    {
        res.push_back(ele1);
    }
    if (cnt2 > floor(nums.size() / 3))
    {
        res.push_back(ele2);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> ans = majorityElement(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}