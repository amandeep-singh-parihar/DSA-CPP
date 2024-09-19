#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int,int>mpp;
    for(int i=0;i<nums.size();++i)
    {
        if(mpp.find(nums[i])!=mpp.end() && i-mpp[nums[i]]<=k)
        {
            return true;
        }
        mpp[nums[i]]=i;
    }
    return false;
}

int main()
{
    int n;
    cout<<"enter the value of n: "<<endl;
    cin >> n;
    vector<int> nums(n);
    cout<<" enter the values of nums : "<<endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int k;
    cout<<"enter the value of K : "<<endl;
    cin>>k;
    cout << containsNearbyDuplicate(nums,k);
    return 0;
}