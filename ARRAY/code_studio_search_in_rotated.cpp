//********************************************SEARCH IN ROTATED SORTED ARRAY*****************************************************

#include <bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return end;
}

int binarySearch(int arr[], int start, int end, int size, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        // mid = start + (end - start) / 2;
    }
    return -1;
}

int findPos(int arr[], int size, int key)
{
    int pivot = getPivot(arr, size);
    if (key >= arr[pivot] && key <= arr[size - 1])
    {
        return binarySearch(arr, pivot, size - 1, size, key);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, size, key);
    }
}

int main()
{
    int arr[5] = {5, 6, 1, 2, 4};
    int key;
    cin >> key;
    cout << findPos(arr, 5, key);
    return 0;
}