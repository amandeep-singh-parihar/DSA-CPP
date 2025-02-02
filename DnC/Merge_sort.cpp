// merge sort
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k = s;
    for (int i = 0; i < len1; ++i)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; ++i)
    {
        arr2[i] = arr[k++];
    }

    int i = 0, j = 0;
    k = s;
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }

    while (i < len1)
    {
        arr[k++] = arr1[i++];
    }

    while (j < len2)
    {
        arr[k++] = arr2[j++];
    }
}

void mergeSORT(vector<int> &arr, int s, int e)
{
    if (s == e)
        return;

    int mid = s + (e - s) / 2;

    mergeSORT(arr, s, mid);
    mergeSORT(arr, mid + 1, e);

    merge(arr, s, e);
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