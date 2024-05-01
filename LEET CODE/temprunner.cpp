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
    int n;
    cout<<"enter the size of array : ";
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    rotate(nums, 2);

    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    return 0;
}