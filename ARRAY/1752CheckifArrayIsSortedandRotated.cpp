// 1752. Check if Array Is Sorted and Rotated
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr)
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i]) // if the array is sorted rotated then only one element is greater then its next element
        // {3,4,5,1,2} here only 5 is greater than its nest 2
        {
            count++; // it must be 1 or 0
        }
    }

    if (arr[arr.size() - 1] > arr[0]) // if the array is sorted and rotated by 0 then the last element is greater then the first one
    // {1,2,3,4,5} here only 5 > 1
    {
        count++; // it must be 1 or 0
    }

    return count <= 1; // if all element have same values then no pair of the above is present
    // now both upper condition can't be true at the same so the count must be less or eqaul to 1

    // more then 1 pair it means it is not sorted and rotated
    // eg. {1,3,7,0,4}
    // here 4 > 1 --> one pair and 7 > 0 --> one pair thus here 2 pair is present.
}

int main()
{
    // vector<int> arr = {4, 5, 1, 2, 3};
    vector<int> arr = {3, 4, 5, 1, 2};
    // vector<int> arr = {2, 1, 3, 4};
    // vector<int> arr = {1, 2, 3};

    cout << check(arr);
}