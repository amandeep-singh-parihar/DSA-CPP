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

    return 0;
}