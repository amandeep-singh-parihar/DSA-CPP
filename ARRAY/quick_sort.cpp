#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (true)
    {
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        while (i <= j && arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            break;
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSORT(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSORT(arr, low, pivotIndex - 1);
        quickSORT(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int size;
    cout << "enter the size : ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSORT(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}