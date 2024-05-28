// only in sorted array
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int s = 0, e = size - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int even[6] = {2, 3, 5, 7, 9, 11};
    int odd[5] = {1, 3, 5, 7, 8};
    int searchedIndex = binarySearch(even, 6, 11); // 5
    cout << searchedIndex << " " << endl;

    int searchedIndex1 = binarySearch(odd, 5, 99); //-1
    cout << searchedIndex1 << " " << endl;
    return 0;
}