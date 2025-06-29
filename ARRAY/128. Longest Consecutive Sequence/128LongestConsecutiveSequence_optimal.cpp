#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int longestConsecutive(vector<int> &nums)
{
    if (nums.empty()) return 0;
    int longest=1;
    unordered_set<int>st;
    for(int i=0;i<nums.size();++i)
    {
        st.insert(nums[i]);
    }

    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        {
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end())
            {
                x++,cnt++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
    return 0;
}