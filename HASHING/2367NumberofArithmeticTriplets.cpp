#include <bits/stdc++.h>
using namespace std;

int arithmeticTriplets(vector<int> &nums, int diff)
{
    int c=0;
    map<int,int>mp;
    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]]++;
    }

    for(int i=0;i<nums.size();i++)
    {
        if(mp[nums[i]+diff] && mp[nums[i]+diff+diff])
        {
            c++;
        }
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>nums={0,1,4,6,7,10};
    int diff;
    cin>>diff;
    cout<<arithmeticTriplets(nums,diff);
    return 0;
}