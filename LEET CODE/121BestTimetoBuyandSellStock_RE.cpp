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
void maxProfitFinder(vector<int> &arr, int i, int &minSoFar, int &maxProfit)
{
    // bc
    if (i == arr.size())
        return;

    // 1 case solve
    minSoFar = min(minSoFar, arr[i]);
    maxProfit = max(maxProfit, arr[i] - minSoFar);

    // Re
    maxProfitFinder(arr, i + 1, minSoFar, maxProfit);
}

int maxProfit(vector<int> &arr)
{
    int minSoFar = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(arr, 0, minSoFar, maxProfit);
    return maxProfit;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr);
    return 0;
}