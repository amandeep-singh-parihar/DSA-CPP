// Maximum Score from Subarray Minimums
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int pairWithMaxSum(vector<int> &arr)
{
    int i = 0, j = 1;
    int maxi = INT_MIN;
    while (j < arr.size())
    {
        maxi = max(maxi, arr[i] + arr[j]);
        ++i, ++j;
    }
    return maxi;
}

int main()
{

    return 0;
}