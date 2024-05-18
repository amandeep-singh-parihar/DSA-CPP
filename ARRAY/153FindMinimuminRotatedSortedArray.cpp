#include <bits/stdc++.h>
using namespace std;

// logic if the array is sorted and then rotated then the pivot is the minimum element just find the pivot
int findMin(vector<int> &arr)
{
    int n=arr.size();
    int s=0,e=arr.size()-1;
    while(s<e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]>arr[e])
        {
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return arr[s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;++i)
    {
        cin>>nums[i];
    }

    int ans=findMin(nums);
    cout<<ans;
    return 0;
}