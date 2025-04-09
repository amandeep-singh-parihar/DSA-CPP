#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

void Reverse(vector<int> &arr, int n, int s, int e)
{
    // base case
    if (s > e)
        return;

    // processing
    swap(arr[s], arr[e]);

    // R call
    Reverse(arr, n, s + 1, e - 1);
}

int main()
{
    vector<int> arr = {6, 5, 4, 3, 2, 1, 0};
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    Reverse(arr, n, s, e);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}