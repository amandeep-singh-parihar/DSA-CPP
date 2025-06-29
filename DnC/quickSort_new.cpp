#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void quickSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;
    int pivot = e;
    int i = s - 1;
    int j = s;
    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            ++i;
            swap(arr[i], arr[j]);
        }
        ++j;
    }
    ++i;
    swap(arr[i], arr[pivot]);
    quickSort(arr, s, i - 1);
    quickSort(arr, i + 1, e);
}

int main()
{
    vector<int> arr = {5, 1, 1, 2, 0, 0};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}