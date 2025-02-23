// 283. Move Zeroes
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
void _moveZeroes(vector<int> &nums)
{
    // create a temp vec only have non zero element
    vector<int> temp;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            temp.push_back(nums[i]);
        }
    }
    // get the size of the give vector
    int give_size = nums.size();
    int temp_size = temp.size();
    // get the size give vector size - temp vector size
    int ans_size = give_size - temp_size;
    // push the zeros in the temp vector
    for (int i = 0; i < ans_size; ++i)
    {
        temp.push_back(0);
    }
    nums = temp;
}

void moveZeroes(vector<int> &arr)
{
    int j = 0; // here j always points the zero element
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] != 0) // if the arr[i] is not zero
        {
            swap(arr[i], arr[j]); // swap that element with the arr[i]
            ++j;                  // increase the j
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    moveZeroes(arr);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}