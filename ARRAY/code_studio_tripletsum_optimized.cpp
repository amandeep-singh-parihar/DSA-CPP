#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &nums, int target)
{
    vector<vector<int>> triplets;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int s = i + 1, e = n - 1, sum = target - nums[i];
            while (s < e)
            {
                if (nums[s] + nums[e] == sum)
                {
                    triplets.push_back({nums[i], nums[s], nums[e]});
                    while (s < e && nums[s] == nums[s + 1])
                        s++;
                    while (s < e && nums[e] == nums[e - 1])
                        e--;
                    s++;
                    e--;
                }
                else if (nums[s] + nums[e] < sum)
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
    }

    return triplets;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Replace this with your own input array
    int targetSum = 10;                             // Replace this with your desired target sum

    vector<vector<int>> result = findTriplets(nums, targetSum);

    for (const vector<int> &triplet : result)
    {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }

    return 0;
}
