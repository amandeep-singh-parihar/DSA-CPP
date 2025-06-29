#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// longest subarray/ substring where <condition>
// condition sum<=k

int main()
{
    int k;
    cin >> k;
    vector<int> nums = {2, 5, 1, 10, 10};
    int l = 0, r = 0, sum = 0, len = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > k)
        {
            sum -= nums[l];
            ++l;
        }
        if (sum <= k)
        {
            len = max(len, r - l + 1);
        }
        ++r;
    }
    cout << len << " " << endl;
    return 0;
}