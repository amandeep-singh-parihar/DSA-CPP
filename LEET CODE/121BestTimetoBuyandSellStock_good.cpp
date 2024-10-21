// 121. Best Time to Buy and Sell Stock
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 1
int maxProfit(vector<int> &arr)
{
    int minimumSoFar = arr[0];
    int maxProfit = INT_MIN;
    for (int i = 0; i < arr.size(); ++i)
    {
        minimumSoFar = min(minimumSoFar, arr[i]);
        maxProfit = max(arr[i] - minimumSoFar, maxProfit);
    }
    return maxProfit;
}
int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr);
    return 0;
}