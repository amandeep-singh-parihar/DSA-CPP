#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[s] == nums[mid] && nums[e] == nums[mid])
            s++, e--;
        else if (nums[mid] >= nums[s])
        {
            if (target >= nums[s] && target <= nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1
            }
        }
        else
        {
            if (target <= nums[e] && target >= nums[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int res=search(arr,t);
    cout<<res;

    return 0;
}