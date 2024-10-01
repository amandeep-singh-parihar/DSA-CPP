#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
void mergeInPlace(vector<int> &arr, int start, int mid, int end)
{
    int total_size = end - start + 1;
    int gap = (total_size / 2) + (total_size % 2);
    while (gap > 0)
    {
        int i = start, j = start + gap;
        while (j <= end)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            ++i, ++j;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

void mergeSORT(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSORT(arr, start, mid);
    mergeSORT(arr, mid + 1, end);
    mergeInPlace(arr, start, mid, end);
}

int main()
{
    vector<int> arr = {4, 3, 2, 1, 0, 12, -2, 12, 0, -1, -1};
    int n = arr.size();

    cout << endl;
    mergeSORT(arr, 0, n - 1);
    cout << endl;
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ",";
    }
    cout << "]";
    cout << endl;
    return 0;
}