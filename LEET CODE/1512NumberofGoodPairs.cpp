#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j <i; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{

    vector<int>nums={1,2,3,1,1,3};
    int ans=numIdenticalPairs(nums);
    cout<<ans;
    return 0;
}