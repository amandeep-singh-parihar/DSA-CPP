/*find first and last position of a number in the given array which comes more than one*/
//the array must be in the ascending order

#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> arr(2, -1);
    int s = 0, e = nums.size() - 1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            arr[0] = mid;
            e = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            arr[1] = mid;
            s = mid + 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return arr;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5}; // You can replace this with your own input vector
    int target = 2;                           // You can replace this with your desired target value

    vector<int> result = searchRange(nums, target);

    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}