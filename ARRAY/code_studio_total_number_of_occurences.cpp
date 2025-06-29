//**********************TOTAL NUMBER OF OCCURENCES OF AN ELEMENT IN A SORTED ARRAY*******************************************

#include <bits/stdc++.h>
using namespace std;
int firstOcc(int arr[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int secondOcc(int arr[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

int totalNum(int arr[], int size, int key)
{
    int ans = (secondOcc(arr, size, key) - firstOcc(arr, size, key) + 1);
    return ans;
}

int main()
{
    int arr[5] = {1, 2, 2, 2, 3};
    int key;
    cin >> key;
    // cout<<firstOcc(arr,7,1)<<endl;
    // cout<<secondOcc(arr,7,1)<<endl;
    cout << totalNum(arr, 5, key);
    return 0;
}