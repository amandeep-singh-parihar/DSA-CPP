#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    if (nums[0] != nums[1])
    {
        return nums[0];
    }
    if (nums[n - 1] != nums[n - 2])
    {
        return nums[n - 1];
    }
    int s = 1, e = n - 2;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }
        // we are on the left
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            s = mid + 1;
        }
        else
        {
            // we are on the right
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"enter the size : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"enter the array elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    int ans=singleNonDuplicate(nums);
    cout<<ans;
    return 0;
}