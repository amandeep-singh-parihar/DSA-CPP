#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
    }
    int rsum = sum;
    int lsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        rsum = rsum - nums[i];
        if (lsum == rsum)
        {
            return i;
        }

        lsum += nums[i];
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6}; // Replace this with your own input array

    int result = pivotIndex(nums);

    if (result != -1)
    {
        cout << "Pivot index is: " << result << endl;
    }
    else
    {
        cout << "No pivot index found." << endl;
    }

    return 0;
}
