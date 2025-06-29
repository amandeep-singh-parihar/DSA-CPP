#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool canJump(vector<int> &nums)
{
    int maxi = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > maxi)
            return false;
        maxi = max(maxi, nums[i] + i);
    }
    return true;
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
    cout << canJump(arr);
    return 0;
}