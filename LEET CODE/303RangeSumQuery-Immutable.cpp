#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//it mainly the question of prefix sum

int prefixSum[10000];//10^4 as it the constraint in the question

int sumRange(int left,int right,vector<int>&arr)
{
    prefixSum[0]=arr[0];
    for(int i=1;i<arr.size();++i)
    {
        prefixSum[i]=arr[i]+prefixSum[i-1];
    }
    // if(left==0)
    // {
    //     return prefixSum[right];
    // }else{
    //     return prefixSum[right]-prefixSum[left-1];
    // }
    return (left==0 ? prefixSum[right] : prefixSum[right]-prefixSum[left-1]);
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int left,right;
    // cout<<"enter the left and rigth : ";
    cin>>left>>right;
    cout<<sumRange(left,right,arr);
    return 0;
}