#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool check(vector<int> arr)
    {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] != diff)
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;
        for (int i = 0; i < r.size(); i++)
        {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Example input
    vector<int> nums = {4, 6, 5, 9, 3, 7};
    vector<int> l = {0, 0, 2};
    vector<int> r = {2, 3, 5};

    // Call the function to check arithmetic subarrays
    vector<bool> result = solution.checkArithmeticSubarrays(nums, l, r);

    // Output the result
    cout << "[";
    for (bool res : result)
    {
        cout << (res ? "true" : "false") << " ";
    }
    cout << "]" << endl;

    return 0;
}
