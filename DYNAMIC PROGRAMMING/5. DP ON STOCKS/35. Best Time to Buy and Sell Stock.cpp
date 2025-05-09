// 121. Best Time to Buy and Sell Stock
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices);
    return 0;
}