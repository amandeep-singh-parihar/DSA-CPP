#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0;
    int n;
    cin >> n;
    int arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ans = ans ^ i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ans = ans ^ arr[i];
    }

    cout << ans;
    return 0;
}