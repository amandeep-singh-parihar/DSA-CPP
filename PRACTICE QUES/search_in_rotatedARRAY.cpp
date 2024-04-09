#include <bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int size)
{
    int s = 0, e = size - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0])
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

int binarySearch(int arr[], int s, int e, int size, int key)
{
    // s=0,e=size-1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
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