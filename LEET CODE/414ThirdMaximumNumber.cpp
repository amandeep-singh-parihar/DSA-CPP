#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int thirdMax(vector<int> &arr)
{
    long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] < max1)
        {
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] >= max3 && arr[i] < max2)
        {
            max3 = arr[i];
        }
    }
    return (max3 == LONG_MIN ? max1 : max3);
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
    cout << thirdMax(arr);
    return 0;
}