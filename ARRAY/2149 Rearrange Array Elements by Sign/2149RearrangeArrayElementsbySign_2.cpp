#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> rearrangeArray(vector<int> &nums)
{
    int posIdx=0,negIdx=1;
    vector<int>ans(nums.size(),0);
    for(int i=0;i<nums.size();++i)
    {
        if(nums[i]<0)
        {
            ans[negIdx]=nums[i];
            negIdx+=2;
        }else{
            ans[posIdx]=nums[i];
            posIdx+=2;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = rearrangeArray(nums);
    cout<<"[";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
        {
            cout << ",";
        }
    }
    cout<<"]";
    return 0;
}