#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}

int main()
{
    int n;
    cout << "enter the size : ";
    cin >> n;
    vector<int> nums(n);
    cout << "enter the elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = singleNonDuplicate(nums);
    cout << ans;
    return 0;
}