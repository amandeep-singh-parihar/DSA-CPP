#include <bits/stdc++.h>
using namespace std;

int binarySearchRecursive(int arr[], int start, int end, int key)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;

        if (key < arr[mid])
            return binarySearchRecursive(arr, start, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, end, key);
    }
    return -1; // If element not found
}

int binarySearch(int arr[], int size, int key)
{
    return binarySearchRecursive(arr, 0, size - 1, key);
}

int main()
{
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 6);
    cout << " Index of 6 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 5, 14);
    cout << " Index of 14 is " << oddIndex << endl;

    return 0;
}
