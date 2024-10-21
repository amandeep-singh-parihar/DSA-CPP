//26. Remove Duplicates from Sorted Array
#include <bits/stdc++.h>
using namespace std;
//revision 1 time

int removeDuplicates(std::vector<int> &nums)
{
    set<int>st;
    for(int i=0;i<nums.size();i++)
    {
        st.insert(nums[i]);
    }
    int index=0;
    for(auto it:st)
    {
        nums[index]=it;
        index++;
    }
    return index;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums);
    return 0;
}