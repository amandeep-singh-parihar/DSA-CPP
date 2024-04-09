#include <bits/stdc++.h>
using namespace std;

int ADV_bin(vector<int> &arr, int target)
{
    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return mid;

        if (arr[s] <= arr[mid]) // left part is sorted
        {
            if (arr[s] <= target && target < arr[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        { // right part is sorted
            if (arr[mid] < target && target <= arr[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {9, 10, 11, 1, 2, 3, 4};
    int target;
    cin >> target;
    int result = ADV_bin(arr, target);
    cout << result << endl;
    return 0;
}