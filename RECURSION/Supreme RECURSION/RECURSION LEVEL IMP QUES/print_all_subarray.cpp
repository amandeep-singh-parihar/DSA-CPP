#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 1
void printSubarray_util(vector<int> &nums, int start, int end)
{
    // base case
    if (end == nums.size())
    {
        return;
    }
    // 1 case solve
    for (int i = start; i <= end; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    // Re
    printSubarray_util(nums, start, end + 1);
}

void printSubarray(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); ++start)
    {
        int end = start;
        printSubarray_util(nums, start, end);
    }
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    printSubarray(arr);
    return 0;
}