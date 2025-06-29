#include <bits/stdc++.h>
using namespace std;
// revison 1
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        // for round 1 to n-1
        bool swapped = false;

        for (int j = 0; j < n - i; j++)
        {

            // process element till n-i th index
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            // already sorted
            break;
        }
    }
}

int main()
{
    int a;
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        arr[i] = a;
    }

    bubbleSort(arr, size);

    for (auto &p : arr)
    {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}