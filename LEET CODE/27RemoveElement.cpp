//27. Remove Element
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
int removeElement(vector<int>nums,int val)
{
    int k=0;
    for(int i=0;i<nums.size();++i)
    {
        if(nums[i]!=val)
        {
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}

int main()
{
    vector<int> nums = {3,2,2,3};
    int val;
    cin>>val;
    cout << removeElement(nums,val);
    return 0;
}