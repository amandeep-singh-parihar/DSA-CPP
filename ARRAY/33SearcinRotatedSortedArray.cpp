#include <bits/stdc++.h>
using namespace std;

int piv(vector<int> &arr, int s, int e)
{
    if (s == e)
        return s;
    int mid = s + (e - s) / 2;
    if (arr[mid] > arr[e])
    {
        return piv(arr, mid + 1, e);
    }
    else
    {
        return piv(arr, s, mid);
    }
}

int binSearch(vector<int> &arr, int t, int s, int e)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == t)
            return mid;

        if (t > arr[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int ans = 0;
    int p = piv(nums, 0, nums.size() - 1);
    if (target >= nums[p] && target <= nums[nums.size() - 1])
    {
        ans = binSearch(nums, target, p, nums.size() - 1);
    }
    else
    {
        ans = binSearch(nums, target, 0, p - 1);
    }
    return ans;
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