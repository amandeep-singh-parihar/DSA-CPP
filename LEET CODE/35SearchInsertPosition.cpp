//35. Search Insert Position
#include<bits/stdc++.h>
using namespace std;
//revision 1
int searchInsert(vector<int>& nums,int target)
{
    int s=0,e=nums.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(nums[mid]==target)
        {
            return mid;
        }else if(nums[mid]<target)
        {
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return s;
}

int main()
{
    int n;
    cout<<"enter the size : ";
    cin>>n;
    
    cout<<"enter the elements ";
    vector<int>nums(n);
    for(int i=0;i<nums.size();++i)
    {
        cin>>nums[i];
    }

    int target;
    cout<<"enter the target : ";
    cin>>target;

    int ans=searchInsert(nums,target);
    cout<<ans;

    return 0;
}