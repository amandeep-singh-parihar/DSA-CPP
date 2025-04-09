#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 2
void print_arr(int arr[], int n, int i)
{
    // base case
    if (i > n - 1)
        return;

    // first case solved
    cout << arr[i] << " ";

    // recursion
    print_arr(arr, n, ++i);
}

int main()
{
    int i = 0;
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    print_arr(arr, n, i);
    return 0;
}