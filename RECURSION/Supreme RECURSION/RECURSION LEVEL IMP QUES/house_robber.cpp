#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int robHelper(vector<int> &arr, int i)
{
    if (i >= arr.size())
    {
        return 0;
    }

    // sol for 1 case;
    int robAmt1 = arr[i] + robHelper(arr, i + 2);
    int robAmt2 = robHelper(arr, i + 1);

    return max(robAmt1, robAmt2);
}

int rob(vector<int> &arr)
{
    return robHelper(arr, 0);
}

int main()
{
    vector<int> arr{2,1,1,2};
    cout << rob(arr);
    return 0;
}