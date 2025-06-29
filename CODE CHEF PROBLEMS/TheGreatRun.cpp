//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision
//revision


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < k; ++i)
    {
        sum += arr[i];
    }
    maxi = sum;

    for (int i = k; i < n; ++i)
    {
        sum += arr[i] - arr[i - k];
        maxi = max(maxi, sum);
    }

    return maxi;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        cout << solve(arr, k) << endl;
    }
}
