#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 2

// int mini(int arr[], int n)
// {
//     // bc
//     if (n == 1)
//         return arr[0];

//     int minInRest = mini(arr, n - 1);
//     return min(arr[n - 1], minInRest);
// }

void findMin(int arr[], int n, int i, int &mini)
{
    if (i > n - 1)
    {
        return;
    }

    // if(arr[i]<mini)
    // {
    //     mini=arr[i];
    // }

    // 1 case solve
    mini = min(mini, arr[i]);

    findMin(arr, n, i + 1, mini);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int i = 0;
    int mini = INT_MAX;

    findMin(arr, n, i, mini);
    cout << mini;

    // cout<<mini(arr,n);
    return 0;
}