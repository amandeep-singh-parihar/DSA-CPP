// L10. Subset Sum I | Recursion | C++ | Java
// Subset Sums
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(2ⁿ × n)
// SC O(2ⁿ × n)
void solve(int i, vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr, int sum)
{
    if (i == arr.size())
    {
        ans.push_back(ds);
        return;
    }

    sum += arr[i];
    ds.push_back(arr[i]);
    solve(i + 1, ans, ds, arr, sum);
    sum -= arr[i];
    ds.pop_back();

    solve(i + 1, ans, ds, arr, sum);
}

vector<int> subsetSums(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, ans, ds, arr, 0);
    vector<int> res;
    for (auto it : ans)
    {
        int sum = 0;
        for (auto _it : it)
        {
            sum += _it;
        }
        res.push_back(sum);
    }
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TC: O(2ⁿ)
// SC: O(2ⁿ)
void _solve(int i, vector<int> &ds, vector<int> &arr, int sum)
{
    if (i == arr.size())
    {
        ds.push_back(sum);
        return;
    }

    // include
    _solve(i + 1, ds, arr, sum + arr[i]);

    // exclude
    _solve(i + 1, ds, arr, sum);
}
vector<int> _subsetSums(vector<int> &arr)
{
    vector<int> ds;
    _solve(0, ds, arr, 0);
    return ds;
}

int main()
{
    vector<int> arr = {5, 6, 7};
    vector<int> res = subsetSums(arr);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}