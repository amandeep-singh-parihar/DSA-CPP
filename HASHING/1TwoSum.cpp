#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); ++i)
    {
        int num = arr[i];
        int required = target - num;
        if (mpp.find(required) != mpp.end())
        {
            return {mpp[required], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}