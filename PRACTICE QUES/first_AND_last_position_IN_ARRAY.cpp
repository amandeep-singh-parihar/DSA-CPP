/*find first and last position of a number in the given array which comes more than one*/
// the array is in non decresing order
#include <bits/stdc++.h>
using namespace std;

vector<int> searchRANGE(vector<int> &arr, int target)
{
    vector<int> finalans(2, -1);
    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            finalans[0] = mid;
            e = mid - 1;
        }
        else if (arr[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            finalans[1] = mid;
            s = mid + 1;
        }
        else if (arr[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return finalans;
}

int main()
{
    vector<int> arr = {1, 1, 2, 4, 5, 5, 5, 8};
    int target;
    cin >> target;

    vector<int> result = searchRANGE(arr, target);

    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}