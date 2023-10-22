//***********************************************************INSERTION SORT******************************************************

#include <bits/stdc++.h>
using namespace std;

int insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {0, 1, 5, 6, 10, 3, 7, 9, 4, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);
    print_arr(arr, n);
    return 0;
}