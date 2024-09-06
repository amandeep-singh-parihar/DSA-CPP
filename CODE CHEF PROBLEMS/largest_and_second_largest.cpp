#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int n)
{
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] < max1)
        {
            max2 = arr[i];
        }
    }
    return max1 + max2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = solve(a, n);
        cout << ans << endl;
    }
}
