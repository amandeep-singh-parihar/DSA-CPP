#include <bits/stdc++.h>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> counts(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j && nums[i] > nums[j])
            {
                count++;
            }
        }
        counts[i] = count;
    }
    return counts;
}

int main()
{
    int n;
    cout << "enter the size : ";
    cin >> n;
    cout << "enter the array : ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = smallerNumbersThanCurrent(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}