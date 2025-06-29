// can be done using STL

#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums = {1,1,5};
    nextPermutation(nums);
    cout << "[";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}