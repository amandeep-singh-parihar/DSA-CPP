#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

struct Item
{
    double value, weight;
};

bool compare(const Item &a, const Item &b)
{
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        items[i] = {double(val[i]), double(wt[i])};
    }

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (const auto &item : items)
    {
        if (capacity >= item.weight)
        {
            totalValue += item.value;
            capacity -= item.weight;
        }
        else
        {
            totalValue += item.value * (double(capacity) / item.weight);
            break;
        }
    }

    return totalValue;
}

// double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
// {
//     vector<pair<double, int>> frac_array;
//     for (int i = 0; i < val.size(); ++i)
//     {
//         double fraction = (double)val[i] / wt[i];
//         frac_array.push_back({fraction, i});
//     }

//     sort(frac_array.rbegin(), frac_array.rend());

//     double profit = 0;
//     for (auto item : frac_array)
//     {
//         int idx = item.second;
//         if (capacity >= wt[idx])
//         {
//             profit += val[idx];
//             capacity -= wt[idx];
//         }
//         else
//         {
//             profit += val[idx] * ((double)capacity / wt[idx]);
//             break;
//         }
//     }
//     return profit;
// }

int main()
{
    int n, capacity;
    cin >> n >> capacity;
    vector<int> val(n);
    vector<int> wt(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> wt[i];
    }
    cout << fractionalKnapsack(val, wt, capacity);
    return 0;
}