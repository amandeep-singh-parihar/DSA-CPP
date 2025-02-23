// 26. Remove Duplicates from Sorted Array
#include <bits/stdc++.h>
using namespace std;

// revision 2 time

// Using set
int removeDuplicates(std::vector<int> &nums)
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

// using two pointers
int _removeDuplicates(std::vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums);
    cout << _removeDuplicates(nums);

    return 0;
}