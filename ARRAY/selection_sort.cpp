#include <iostream>
#include <vector>

using namespace std;
//revision 2
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main()
{
    // Create a vector of integers to be sorted
    vector<int> arr = {12, 45, 23, 6, 56, 78, 34, 89, 13};

    // Get the number of elements in the vector
    int n = arr.size();

    // Sort the vector using the selection sort algorithm
    selectionSort(arr, n);

    // Display the sorted vector
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
