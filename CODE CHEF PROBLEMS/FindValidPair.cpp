#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<pair<int, int>> validPair(vector<pair<int, int>> &arr, int l, int r)
{
    vector<pair<int, int>> ans;
    for (auto it : arr)
    {
        int sum = it.first + it.second;
        int product = it.first * it.second;
        if (sum >= l && sum <= r && product >= l && product <= r)
        {
            ans.push_back(it);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    int left, right;
    cin >> left >> right;
    vector<pair<int, int>> ans = validPair(arr, left, right);
    for(auto it:ans)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}