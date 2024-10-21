// 962. Maximum Width Ramp
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maxWidthRamp(vector<int> &arr)
{
    int n = arr.size();
    vector<int> rightMax(n);
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }
    int i = 0, j = 0, rampWidth = 0;
    while (j < n)
    {
        while (i < j && arr[i] > rightMax[j])
        {
            i++;
        }
        rampWidth = max(rampWidth, j - i);
        ++j;
    }
    return rampWidth;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << maxWidthRamp(arr);
    return 0;
}