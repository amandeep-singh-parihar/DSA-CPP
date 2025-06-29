#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//reivsion needed

long merge(vector<int> &arr, vector<int> &temp, int start, int end, int mid)
{
    int i = start, j = mid + 1, k = start;
    long c=0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {   //condition -> arr[i]>arr[j]
            temp[k++] = arr[j++];
            c+=mid-i+1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    // put all in the array now
    while (start <= end)
    {
        arr[start] = temp[start];
        ++start;
    }
    return c;
}

long mergeSORT(vector<int> &arr, vector<int> &temp, int start, int end)
{
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;
    long c=0;

    c+=mergeSORT(arr, temp, start, mid);
    c+=mergeSORT(arr, temp, mid + 1, end);
    c+=merge(arr, temp, start, end, mid);
    return c;
}

long countInversions(vector<int> &arr)
{   
    long c=0;
    vector<int> temp(arr.size(), 0);
    c=mergeSORT(arr, temp, 0, arr.size() - 1);
    return c;
}

int main()
{
    vector<int> arr = {2, 1, 3, 1, 2};
    int n = arr.size();
    cout << countInversions(arr);
    return 0;
}