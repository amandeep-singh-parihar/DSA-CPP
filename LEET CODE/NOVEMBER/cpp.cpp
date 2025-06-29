#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> outputArr(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); ++i)
    {
        maxi = max(maxi, arr[i]);
    }
    vector<int> countArr(maxi + 1, 0);

    for (int i = 0; i < arr.size(); ++i)
    {
        countArr[arr[i]]++;
    }

    //prefix sum
    for (int i = 1; i <= maxi; ++i)
    {
        countArr[i] += countArr[i - 1];
    }

    vector<int> outputArr(arr.size());
    //
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        outputArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }
    cout<<endl;
    return outputArr;
}

int main()
{
    vector<int> arr = {2, 1, 2, 3, 1, 2, 4};

    vector<int> ans = outputArr(arr);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}