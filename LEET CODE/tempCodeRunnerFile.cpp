#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }

    int index = 0;
    for (auto it : st)
    {
        nums[index] = it;
        index++;
    }
    return index;
}

int main()
{
    vector<int> nums = {1,1,2};
    cout << removeDuplicates(nums);
    return 0;
}