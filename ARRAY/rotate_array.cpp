/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr, int k)
{
    vector<int> temp(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        temp[(i + k) % arr.size()] = arr[i];
    }
    arr = temp;
}
void print(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> arr = {11,13,14,15,16};
    int k = 2;
    rotate(arr, k);

    print(arr);
    return 0;
}