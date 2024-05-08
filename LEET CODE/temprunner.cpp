#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> arr, long long k)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            for (int z = i; z <= j; z++)
            {
                sum += arr[z];
            }
            if (sum == k)
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {1, 1, 1, 1};
    cout << longestSubarrayWithSumK(arr, 3);
    return 0;
}