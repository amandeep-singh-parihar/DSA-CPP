#include<bits/stdc++.h>
using namespace std;

int piv(vector<int>&arr,int s,int e)
{
    if(s==e) return s;
    int mid=s+(e-s)/2;
    if(arr[mid]>arr[e])
    {
        return piv(arr,mid+1,e);
    }else{
        return piv(arr,s,mid);
    }
}

// logic if the array is sorted and then rotated then the pivot is the minimum element just find the pivot
int findMin(vector<int> &arr)
{
    if(arr.empty()) return -1;
    return arr[piv(arr,0,arr.size()-1)];
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

    // cout<<"**************"<<endl;
    // cout<<piv(nums,0,nums.size()-1);
    return 0;
}