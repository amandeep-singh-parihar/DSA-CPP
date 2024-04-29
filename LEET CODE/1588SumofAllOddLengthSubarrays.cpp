#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sumOddLengthSubarrays(vector<int> &arr)
{
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int count=((i+1)*(n-i)+1)/2;
        sum+=count*arr[i];
    }
    return sum;
}

int main()
{
    vector<int> nums = {10,11,12};
    cout << sumOddLengthSubarrays(nums);
    return 0;
}