//*****************************************RETURN THE PIVOT ELEMENT IN A ROTATED ARRAY**************************************************

#include <bits/stdc++.h>
using namespace std;

int pivot(int arr[], int n)
{
    int s = 0, e = n - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[e])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return e;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << pivot(arr, n);
    return 0;
}