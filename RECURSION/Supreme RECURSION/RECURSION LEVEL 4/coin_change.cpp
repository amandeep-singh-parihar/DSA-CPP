#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
int solve(vector<int> &arr, int target)
{
    if (target == 0)
    {
        return 0;
    }

    if (target < 0)
    {
        return INT_MAX;
    }

    // R call
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); ++i)
    {
        int ans = solve(arr, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
            //plus 1 here is for bcz the answer is for target-arr[i] so we add +1 to reach the target
        }
    }

    return mini;
}

int main()
{
    vector<int> arr{1, 2};
    int target = 5;

    int ans = solve(arr, target);
    cout << "Answer is : " << ans << endl;

    return 0;
}