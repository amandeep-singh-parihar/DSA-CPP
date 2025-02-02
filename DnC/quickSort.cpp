#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 2
int Partition(vector<int> &arr, int s, int e)
{
    int pivotIndex = s;
    int pivotElement = arr[pivotIndex];
    int count = 0;
    for (int i = s + 1; i <= e; ++i)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }

    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            ++i;
        }
        while (arr[j] > pivotElement)
        {
            --j;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int p = Partition(arr, s, e);

    // left
    quickSort(arr, s, p - 1);

    // right
    quickSort(arr, p + 1, e);
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