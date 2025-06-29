#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O(N^2)
// SC O(N)
vector<int> NGE(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, -1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[j] > nums[i])
            {
                nge[i] = nums[j];
                break;
            }
        }
    }
    return nge;
}

// Better
// TC O(2N)
// SC O(2N)
vector<int> _NGE(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i)
    {

        while (!st.empty() && nums[i] >= st.top())
        {
            st.pop();
        }

        if (!st.empty() && st.top() > nums[i])
        {
            nge[i] = st.top();
            // st.push(nums[i]);
        }
        else if (st.empty())
        {
            nge[i] = -1;
            // st.push(nums[i]);
        }
        st.push(nums[i]);
    }
    return nge;
}

int main()
{
    vector<int> nums = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> ans = _NGE(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}