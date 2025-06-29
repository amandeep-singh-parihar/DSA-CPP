#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> PSE(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> pse(n, -1);
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && st.top() >= nums[i])
        {
            st.pop();
        }

        if (!st.empty() && st.top() < nums[i])
        {
            pse[i] = st.top();
        }
        else if (st.empty())
        {
            pse[i] = -1;
        }
        st.push(nums[i]);
    }
    return pse;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> ans = PSE(nums);
    for (int it : ans)
    {
        cout << it << " ";
    }
    return 0;
}